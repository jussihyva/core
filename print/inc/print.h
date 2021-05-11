/*******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 ******************************************************************************/

#ifndef PRINT_H
# define PRINT_H

# include <stdarg.h>
# include <stddef.h>
# include <inttypes.h>
# include <stdint.h>
# include <sys/types.h>

int				print(const char *format, ...);
char			*format(const char *format, ...);

#endif
