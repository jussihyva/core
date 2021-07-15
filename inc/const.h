#ifndef CONST_H
# define CONST_H

///////////////////////////////////////////////////////////////////////////////
///
/// \brief Library constants, do not change!
///
/// \authors Julius Koskela
///
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
///
/// Defines

# define CR_PI 3.14159265358979323846
# define CR_STOP -1
# define CR_CONTINUE 1
# define CR_TRUE 1
# define CR_FALSE 0
# define CR_EMPTY -1
# define CR_WRITE 0
# define CR_APPEND 1
# define CR_PREPEND -1
# define CR_STRING NULL

///////////////////////////////////////////////////////////////////////////////
///
/// Errors

enum e_return_type
{
	CR_ERROR_BOUNDS = -4,
	CR_ERROR_MALLOC,
	CR_ERROR_INPUT,
	CR_FAIL,
	CR_SUCCESS = 0
};

///////////////////////////////////////////////////////////////////////////////

#endif
