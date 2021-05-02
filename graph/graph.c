#include <stdio.h>
#include <string.h>
#include "../inc/core.h"

# define CR_GRAPH_NULL (t_graph) {NULL, CR_ARR_NULL}
# define CR_GRAPH_EDGE_NULL (t_graph_edge) {NULL, NULL, NULL}
# define CR_GRAPH_NODE_NULL (t_graph_node) \
            {CR_PARR_NULL, CR_PARR_NULL, NULL}

# define NONE -1
# define NO_ATTR NULL
# define TRUE 1
# define FALSE 0

typedef struct      s_graph_node
{
    t_arr           in;
    t_arr           out;
    size_t			visited;
    void            *attr;
}                   t_graph_node;

typedef struct      s_graph_edge
{
    t_graph_node    *src;
    t_graph_node    *dst;
    void            *attr;
}                   t_graph_edge;

typedef struct      s_graph
{
    char            *name;
    t_arr           nodes;
}                   t_graph;

typedef struct      s_node_attr
{
    char            *name;
    ssize_t         max_capacity;
    ssize_t         curr_capacity;
}                   t_node_attr;

typedef struct      s_edge_attr
{
    size_t          dist;
}                   t_edge_attr;

ssize_t graph_new(t_graph *g, char *name)
{
    g->name = name;
    g->nodes = arr_new(sizeof(t_graph_node));
    return (CR_SUCCESS);
}

ssize_t graph_add_node(t_graph *g, t_graph_node n)
{
    n.out = arr_new(sizeof(t_graph_edge));
    n.in = arr_new(sizeof(t_graph_edge));
    if (!(arr_add_last(&g->nodes, &n)))
        return (-1);
    return (g->nodes.len - 1);
}

ssize_t graph_add_edge(t_graph *g, size_t src_index, size_t dst_index, void *attr)
{
    t_graph_edge    e;
    t_graph_node    *src;
    t_graph_node    *dst;

    src = arr_get(&g->nodes, src_index);
    dst = arr_get(&g->nodes, dst_index);
    if (!src || !dst)
        return (-1);
    e.src = src;
    e.dst = dst;
    e.attr = attr;  
    if (!(arr_add_last(&src->out, &e)))
        return (-1);
    if (!(arr_add_last(&dst->in, &e)))
        return (-1);
    return (CR_SUCCESS);
}

ssize_t compare_nodes(const void *key, t_graph_node *node)
{
    t_node_attr *n2_attr;

    n2_attr = node->attr;
    if (s_cmp(key, n2_attr->name) == 0)
        return (1);
    return (0);
}

t_graph_node    *graph_find_node(t_graph *g, const void *key, ssize_t (*f)(const void *, t_graph_node *))
{
    t_graph_node    *tmp;
    size_t  i;

    i = 0;
    while (i < g->nodes.len)
    {
        tmp = arr_get(&g->nodes, i);
        if (f(key, tmp) == 1)
            return (tmp);
        i++;
    }
    return (NULL);
}

ssize_t graph_find_roots(t_graph *g, t_arr *roots)
{
    t_graph_node    *tmp;
    size_t          i;

    i = 0;
    while (i < g->nodes.len)
    {
        tmp = arr_get(&g->nodes, i);
        if (tmp->in.len == 0)
            arr_add_last(roots, tmp);
        i++;
    }
    if (roots->len)
        return (CR_SUCCESS);
    return (CR_FAIL);
}

ssize_t graph_reset_visited(t_graph *g)
{
    t_graph_node    *tmp;
    size_t          i;

    i = 0;
    while (i < g->nodes.len)
    {
        tmp = arr_get(&g->nodes, i);
        tmp->visited = FALSE;
        i++;
    }
    return (CR_SUCCESS);
}

//-----------------------------------------------------------------------------

ssize_t graph_bfs_loop(t_graph *g, t_arr *bfs_queue, t_graph_node *curr, size_t curr_index)
{
    t_graph_edge    *curr_edge;
    t_graph_node    *dst_node;
    size_t          i;

    i = 0;
    curr->visited = TRUE;
    while (i < curr->out.len)
    {
        curr_edge = arr_get(&curr->out, i);
        if (!curr_edge)
            break ;
        dst_node = curr_edge->dst;
        if (dst_node->visited == FALSE)
        {
            if (!(arr_add_last(bfs_queue, dst_node)))
                return (CR_FAIL);
        }
        i++;
    }
    if (curr_index < bfs_queue->len)
	{
		dst_node = arr_get(bfs_queue, curr_index);
        graph_bfs_loop(g, bfs_queue, dst_node, curr_index + 1);
	}
    return (CR_SUCCESS);
}

ssize_t graph_bfs(t_graph *g, t_arr *bfs_queue, t_graph_node *root)
{
    if (!(arr_add_last(bfs_queue, root)))
        return (CR_FAIL);
    if (!(graph_bfs_loop(g, bfs_queue, root, 1)))
        return (CR_FAIL);
    graph_reset_visited(g);
    return (CR_SUCCESS);
}

//-----------------------------------------------------------------------------

ssize_t graph_dfs_loop(t_graph *g, t_arr *dfs_queue, t_graph_node *curr)
{
    t_graph_edge    *curr_edge;
    t_graph_node    *dst;
    size_t          i;

    curr->visited = TRUE;
    i = 0;
    while (i < curr->out.len)
    {
        curr_edge = arr_get(&curr->out, i);
        dst = curr_edge->dst;
        if (dst->visited == FALSE)
        {
            arr_add_last(dfs_queue, dst);
            graph_dfs_loop(g, dfs_queue, dst);
        }
        i++;
    }
    return (CR_SUCCESS);
}

ssize_t graph_dfs(t_graph *g, t_arr *dfs_queue, t_graph_node *root)
{
    if (!(arr_add_last(dfs_queue, root)))
        return (CR_FAIL);
    if (!(graph_dfs_loop(g, dfs_queue, root)))
        return (CR_FAIL);
    graph_reset_visited(g);
    return (CR_SUCCESS);
}

//-----------------------------------------------------------------------------

ssize_t graph_print_node(void *data, size_t i)
{
    t_graph_node    *tmp;
    t_node_attr     *attr;

    tmp = data;
    attr = tmp->attr;
    printf("%s max[%ld] curr[%ld]\n", attr->name, attr->max_capacity, attr->curr_capacity);
    return (i);
}

int main(void)
{
    t_graph g;
    t_arr   bfs;
    t_arr   dfs;
    t_graph_node n;
    t_node_attr na0;
    t_node_attr na1;
    t_node_attr na2;
    t_node_attr na3;
    t_edge_attr ea0;
    t_edge_attr ea1;
    t_edge_attr ea2;
    t_edge_attr ea3;
    ssize_t source;
    ssize_t sink;
    ssize_t room1;
    ssize_t room2;

    graph_new(&g, "Flow Graph");
    na0 = (t_node_attr) {"S", NONE, NONE};
    n = (t_graph_node) {CR_ARR_NULL, CR_ARR_NULL, FALSE, &na0};
    source = graph_add_node(&g, n);
    na1 = (t_node_attr) {"T", NONE, NONE};
    n = (t_graph_node) {CR_ARR_NULL, CR_ARR_NULL, FALSE, &na1};
    sink = graph_add_node(&g, n);
    na2 = (t_node_attr) {"R1", 3, 3};
    n = (t_graph_node) {CR_ARR_NULL, CR_ARR_NULL, FALSE, &na2};
    room1 = graph_add_node(&g, n);
    na3 = (t_node_attr) {"R2", 4, 4};
    n = (t_graph_node) {CR_ARR_NULL, CR_ARR_NULL, FALSE, &na3};
    room2 = graph_add_node(&g, n);

    ea0 = (t_edge_attr) {1};
    graph_add_edge(&g, source, room1, &ea0);
    ea1 = (t_edge_attr) {1};
    graph_add_edge(&g, source, room2, &ea1);
    ea2 = (t_edge_attr) {1};
    graph_add_edge(&g, room2, sink, &ea2);
    ea3 = (t_edge_attr) {1};
    graph_add_edge(&g, room1, sink, &ea3);

	bfs = arr_new(sizeof(t_graph_node));
	arr_alloc(&bfs, 100);
	graph_bfs(&g, &bfs, graph_find_node(&g, "S", compare_nodes));
	printf("Breadth First Search\n\n");
	arr_iter(&bfs, graph_print_node);
    
    dfs = arr_new(sizeof(t_graph_node));
	arr_alloc(&dfs, 100);
    graph_dfs(&g, &dfs, graph_find_node(&g, "S", compare_nodes));
    printf("Depth First Search\n\n");
    arr_iter(&dfs, graph_print_node);
}
