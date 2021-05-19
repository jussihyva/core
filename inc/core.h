#ifndef CORE_H
# define CORE_H

# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include <stdbool.h>
# include <inttypes.h>
# include <execinfo.h>

typedef unsigned char		t_byte;
typedef unsigned long long	t_size;
typedef long long			t_ssize;
typedef signed char			t_int8;
typedef short int			t_int16;
typedef long int			t_int32;
typedef long long int		t_int64;
typedef unsigned char		t_uint8;
typedef short int			t_uint16;
typedef long int			t_uint32;
typedef long long int		t_uint64;

# include "../memory/inc/mem.h"
# include "../array/inc/array.h"
# include "../ptr_array/inc/parr.h"
# include "../linear_algebra/inc/lin.h"
# include "../cstring/inc/cstr.h"
# include "../map/inc/map.h"
# include "../graph/inc/graph.h"
# include "../math/inc/math.h"
# include "../print/inc/print.h"
# include "../string/inc/string.h"
# include "../checks/inc/checks.h"
# include "../system/inc/system.h"
# include "const.h"
# include "config.h"

#endif
