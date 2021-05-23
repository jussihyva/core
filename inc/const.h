#ifndef CONST_H
# define CONST_H

///////////////////////////////////////////////////////////////////////////////
///
/// \brief Library constants, do not change!
///
/// \authors Julius Koskela
///
///////////////////////////////////////////////////////////////////////////////

/// Defines ///////////////////////////////////////////////////////////////////

# define CR_PI 3.14159265358979323846
# define CR_STOP -1
# define CR_CONTINUE 1
# define CR_SUCCESS 1
# define CR_FAIL 0
# define CR_TRUE 1
# define CR_FALSE 0
# define CR_EMPTY -1
# define CR_WRITE 0
# define CR_APPEND 1
# define CR_PREPEND -1
# define CR_STRING NULL
# define CR_MEM_NULL (t_raw) {NULL, 0}
# define CR_PARR_NULL (t_parray) {NULL, 0, 0}
# define CR_ARR_NULL (t_array) {CR_MEM_NULL, 0, 0}
# define CR_GRAPH_NULL (t_graph) {CR_MAP_NULL, 0, NULL}
# define CR_GRAPH_NULL_NODE (t_graph_node) {NULL, CR_ARR_NULL, CR_ARR_NULL, 0, NULL, NULL}
# define CR_GRAPH_EDGE_NULL (t_graph_edge) {NULL, NULL, 0, NULL}
# define CR_MAP_NULL_NODE (t_map_node) {NULL, NULL}
# define CR_MAP_NULL (t_map) {NULL, 0, 0, 0.0, NULL, NULL, NULL}
# define CR_FILE_POS &(t_file_pos){__FUNCTION__, __FILE__, __LINE__}

///////////////////////////////////////////////////////////////////////////////

#endif
