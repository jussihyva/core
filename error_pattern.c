#include "inc/core.h"

typedef enum e_error
{
	ERRF_CASE_1 = -1000,
	ERRW_CASE_3 = -3,
	ERRW_CASE_2,
	ERRW_CASE_1
}	t_error;

int main(void)
{
	t_error err = ERRW_CASE_1;

	print("%d\n", err);
}
		
