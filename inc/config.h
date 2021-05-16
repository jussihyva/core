#ifndef CONFIG_H
# define CONFIG_H

# define CR_ACTIVE 1
# define CR_STACK_TRACE_MAX 1024
# define CR_TRACK_ALLOC 1
# define CR_TRACK_ALLOC_BACKTRACE 1
# define CR_TRACK_ERROR 1
# define CR_TRACK_ERROR_BACKTRACE 1
# define CR_RECOVERY_POLICY 0

# define CR_MAP_START_CAPACITY 128
# define CR_MAP_LOAD_FACTOR 1
# define CR_MAP_HASH map_hash_1
# define CR_MAP_PROBE map_probe_linear
# define CR_MAP_RESIZE map_resize_linear

#endif