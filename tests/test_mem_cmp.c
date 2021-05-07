#include "../inc/core.h"














int main(void)
{
	char	*s1;
	char	*s2;

	s1 = "KKKKKKKKKKKKKKKKK";
	s2 = "KKKKKKKKKKKKKKKKK";
	if (mem_cmp(s1, s2, s_len(s1)) == 0)
		printf("yes");
}
