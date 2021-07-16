///////////////////////////////////////////////////////////////////////////////
///
/// dr_bdreadth_first_search_mt.c
///
/// \authors Julius Koskela
///
/// \brief Breadth first search on a directed graph (multithreaded).
///
/// Performs a breadth first search on a graph saving the result as edges
/// put into an array. If NULL is passed as destination, will search the
/// whole graph. Checks of edges are valid as well and won't traverse edges
/// that are marked as invalid. This is helpful with max flow for example.
///
/// \param g Source graph.
/// \param src_name name of the root of the search.
/// \param dst_name name of the destination of the search. If NULL is passed
/// will seacrh the whole graph.
///
/// \return An array containing a list of edges.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/digraph.h"

# define			POOL_SIZE 4
pthread_mutex_t		g_digraph_bfs_mutex;
pthread_mutex_t		g_digraph_bfs_mutex_work;
pthread_cond_t		g_digraph_bfs_cond;
t_bool				g_digraph_bfs_terminate;
t_bool				g_target_found;

typedef struct s_arg
{
	t_parray	*queue;
	t_parray	*results;
	t_digraph_node	*current;
	t_digraph_node	*target;
}	t_arg;

// Do work, store results and push new work to the queue.
// There is POOL_SIZE - 1 possible worker threads.

void	*worker_thread(void *ptr)
{
	t_arg		*arg;
	t_digraph_edge	*e;
	t_size		i;

	arg = ptr;
	i = 0;
	while (i < arg->current->e_out.len)
	{
		e = parr_get(&arg->current->e_out, i);
		if (e->valid && e->v->valid)
		{
			pthread_mutex_lock(&g_digraph_bfs_mutex);
			e->v->valid = FALSE;
			parr_add_last(arg->results, e);
			parr_add_last(arg->queue, e->v);
			if (arg->target && e->v == arg->target)
			{
				g_target_found = 1;
				free(arg);
				return (arg->target);
			}
			pthread_mutex_unlock(&g_digraph_bfs_mutex);
		}
		i++;
	}
	free(arg);
	return (NULL);
}

// Wait for queue to have new work and pass the work
// to a worker thread. There is 1 shceduler thread.

void	*scheduler_thread(void *ptr)
{
	t_arg		*arg;
	t_arg		*targ;
	pthread_t	workers[POOL_SIZE];
	t_size		i;
	t_size		j;

	arg = ptr;
	while (arg->queue->len)
	{
		i = 0;
		while (i < POOL_SIZE)
		{
			if (!arg->queue->len)
				break ;
			targ = malloc(sizeof(t_arg));
			targ->queue = arg->queue;
			targ->results = arg->results;
			targ->target = arg->target;
			pthread_mutex_lock(&g_digraph_bfs_mutex);
			targ->current = parr_take_first(arg->queue);
			if (!targ->current)
				return (NULL);
			if (pthread_create(&workers[i], NULL, worker_thread, targ) != 0)
			{
				print("Worker thread failed to create!\n");
				return (NULL);
			}
			pthread_mutex_unlock(&g_digraph_bfs_mutex);
			i++;
		}
		j = 0;
		while (j < i)
		{
			if (pthread_join(workers[j], NULL) != 0)
			{
				print("Worker thread failed to join!\n");
				return (NULL);
			}
			j++;
		}
	}
	return (NULL);
}

t_bool	digraph_breadth_first_search_mt(
		t_digraph *src,
		t_digraph_edge_set *results,
		const char *s_name,
		const char *t_name)
{
	t_digraph_node	*s;
	t_digraph_node	*t;
	t_arg		*sarg;
	t_parray	queue;
	pthread_t	scheduler;

	s = digraph_find_node(src, s_name);
	t = digraph_find_node(src, t_name);
	if (!s)
		return (FALSE);

	// Initialize resources.
	g_digraph_bfs_terminate = POOL_SIZE;
	pthread_mutex_init(&g_digraph_bfs_mutex, NULL);
	pthread_cond_init(&g_digraph_bfs_cond, NULL);
	parr_new(&queue, 1);
	parr_add_last(&queue, s);
	sarg = malloc(sizeof(t_arg));
	sarg->current = NULL;
	sarg->queue = &queue;
	sarg->results = &results->edges;
	sarg->target = t;
	g_target_found = 0;

	// Do the work.
	if (pthread_create(&scheduler, NULL, scheduler_thread, sarg))
	{
		print("Scheduler thread failed to create!\n");
		return (FALSE);
	}
	if (pthread_join(scheduler, NULL) != 0)
	{
		print("Scheduler thread failed to join!\n");
		return (FALSE);
	}

	// Free resources.
	free(sarg);
	parr_free(&queue);
	map_iter(&src->nodes, digraph_node_reset);
	pthread_mutex_destroy(&g_digraph_bfs_mutex);
	pthread_cond_destroy(&g_digraph_bfs_cond);
	return (TRUE);
}

///////////////////////////////////////////////////////////////////////////////
