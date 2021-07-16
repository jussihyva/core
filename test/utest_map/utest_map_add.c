#include "inc/core.h"
#include <assert.h>

const char *errors[] =
{
	"CR_SUCCESS",
	"CR_FAIL",
	"CR_ERROR_INPUT",
	"CR_ERROR_MALLOC",
	"CR_ERROR_BOUNDS",
	"CR_ERROR_FILE"
};

t_bool	print_error(t_ret error_code)
{
	if (error_code > 0)
		return (TRUE);
	print("%s\n", errors[math_abs(error_code)]);
	return (FALSE);
}

t_bool	utest_map_add(void)
{
	t_map	test;
	char	*payload;
	t_ret	ret;

	ret = map_new(&test, 1, CR_MAP_LINEAR, map_hash_fast);
	if (ret < 0) return (print_error(ret));
	ret = map_add(&test, "A PAYLOAD", "A");
	if (ret < 0) return (print_error(ret));
	ret = map_add(&test, "B PAYLOAD", "B");
	if (ret < 0) return (print_error(ret));
	ret = map_add(&test, "C PAYLOAD", "C");
	if (ret < 0) return (print_error(ret));
	payload = map_get(&test, "A");
	assert(s_cmp(payload, "A PAYLOAD") == 0);
	payload = map_get(&test, "B");
	assert(s_cmp(payload, "B PAYLOAD") == 0);
	payload = map_get(&test, "C");
	assert(s_cmp(payload, "C PAYLOAD") == 0);
	map_free(&test);
	return (TRUE);
}

int main(void)
{
	if (utest_map_add() == TRUE)
		print("TESTS_SUCCEEDED!\n");
	else
		print("TESTS_FAILED!\n");
}
