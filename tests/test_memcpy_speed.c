#include <time.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

const size_t		iters = 100000000;

//-----------------------------------------------------------------------------
// Optimized memcpy
//
static void
copy_words(void *restrict dst, const void *restrict src, size_t words)
{
	const uint64_t	*restrict src64;
	uint64_t		*restrict dst64;
	uint64_t		pages;
	uint64_t		offset;

	pages = words / 8;
	offset = words - pages * 8;
	src64 = (const uint64_t *restrict)src;
	dst64 = (uint64_t *restrict)dst;
	while (pages--)
	{
		*dst64++ = *src64++;
		*dst64++ = *src64++;
		*dst64++ = *src64++;
		*dst64++ = *src64++;
		*dst64++ = *src64++;
		*dst64++ = *src64++;
		*dst64++ = *src64++;
		*dst64++ = *src64++;
	}
	while (offset--)
		*dst64++ = *src64++;
}
static void
copy_small(void *restrict dst, const void *restrict src, size_t size)
{
	const uint64_t	*restrict src64;
	uint64_t		*restrict dst64;

	src64 = (const uint64_t *restrict)src;
	dst64 = (uint64_t *restrict)dst;
	*dst64 = *src64;
}
void
*mem_cpy(void *restrict dst, const void *restrict src, const size_t size)
{
	const uint8_t	*restrict src8;
	uint8_t			*restrict dst8;
	size_t			offset;
	size_t			words;
	size_t			aligned_size;

	if (!src || !dst)
		return (NULL);
	if (size <= 8)
	{
		copy_small(dst, src, size);
		return (dst);
	}
	words = size / 8;
	aligned_size = words * 8;
	offset = size - aligned_size;
	copy_words(dst, src, words);
	if (offset)
	{
		src8 = (const uint8_t *restrict)src;
		src8 = &src8[aligned_size];
		dst8 = (uint8_t *restrict)dst;
		dst8 = &dst8[aligned_size];
		while (offset--)
			*dst8++ = *src8++;
	}
	return (dst);
}

//-----------------------------------------------------------------------------
// Naive memcpy
//
void				*mem_cpy_naive(void *dst, const void *src, size_t n)
{
	const uint8_t	*src8;
	uint8_t			*dst8;

	if (src == NULL)
		return (NULL);
	src8 = (const uint8_t *)src;
	dst8 = (uint8_t *)dst;
	while (n--)
		*dst8++ = *src8++;
	return (dst);
}

//-----------------------------------------------------------------------------
// Tests
//
int			test(int (*f)(), char *test_name)
{	
	clock_t begin = clock();
	f();
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%s: %f\n", test_name, time_spent);
	return (1);
}

char		*big_data()
{
	char	*out;
	size_t	i;

	out = (char *)malloc(sizeof(char) * 1000);
	i = 0;
	while (i < 1000)
	{
		out[i] = 'a';
		i++;
	}
	return (out);
}

int			test1()
{
	char	*src;
	char	*dst;
	size_t	i;

	src = big_data();
	dst = (char *)malloc(sizeof(char) * 1000);
	i = 0;
	while (i < iters)
	{
		mem_cpy(dst, src, 1000);
		assert(memcmp(dst, src, 1000) == 0);
		i++;
	}
	printf("%c\n", *dst);
	return (1);
}


int			test2()
{
	char	*src;
	char	*dst;
	size_t	i;

	src = big_data();
	dst = (char *)malloc(sizeof(char) * 1000);
	i = 0;
	while (i < iters)
	{
		mem_cpy_naive(dst, src, 1000);
		assert(memcmp(dst, src, 1000) == 0);
		i++;
	}
	printf("%c\n", *dst);
	return (1);
}

int			test3()
{
	char	*src;
	char	*dst;
	size_t	i;

	src = big_data();
	dst = (char *)malloc(sizeof(char) * 1000);
	i = 0;
	while (i < iters)
	{
		memcpy(dst, src, 1000);
		assert(memcmp(dst, src, 1000) == 0);
		i++;
	}
	printf("%c\n", *dst);
	return (1);
}

int			test4()
{
	char	*src;
	char	*dst;
	size_t	i;

	src = "12345678";
	dst = (char *)malloc(sizeof(char) * 8);
	i = 0;
	while (i < iters)
	{
		mem_cpy(dst, src, 8);
		assert(memcmp(dst, src, 8) == 0);
		i++;
	}
	printf("%c\n", *dst);
	return (1);
}

int			test5()
{
	char	*src;
	char	*dst;
	size_t	i;

	src = "12345678";
	dst = (char *)malloc(sizeof(char) * 8);
	i = 0;
	while (i < iters)
	{
		mem_cpy_naive(dst, src, 8);
		assert(memcmp(dst, src, 8) == 0);
		i++;
	}
	return (1);
}

int			test6()
{
	char	*src;
	char	*dst;
	size_t	i;

	src = "12345678";
	dst = (char *)malloc(sizeof(char) * 8);
	i = 0;
	while (i < iters)
	{
		memcpy(dst, src, 8);
		assert(memcmp(dst, src, 8) == 0);
		i++;
	}
	return (1);
}

int			main(void)
{
	test(test1, "User memcpy (big string)");
	test(test2, "User memcpy naive (big string)");
	test(test3, "Libc memcpy (big string)");
	test(test4, "User memcpy");
	test(test5, "USer memcpy naive");
	test(test6, "Libc memcpy");
}
