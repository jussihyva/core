#include <time.h>
#include <math.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/*#include "../inc/core.h"*/

size_t		iters = 0; // 2^36

//-----------------------------------------------------------------------------
// Optimized memcpy
//

static inline void __attribute__((nonnull))
copy_small(uint8_t *restrict dst, const uint8_t *restrict src, size_t n)
{
	if (n >= 8)
	{
		*(uint64_t *restrict)dst = *(const uint64_t *restrict)src;
		return;
	}
	if (n >= 4)
	{
		*(uint32_t *restrict)dst = *(const uint32_t *restrict)src;
		dst += 4;
		src += 4;
	}
	if (n & 2)
	{
		*(uint16_t *restrict)dst = *(const uint16_t *restrict)src;
		dst += 2;
		src += 2;
	}
	if (n & 1)
		*dst = *src;
}

static inline void __attribute__((nonnull))
copy512(uint64_t *restrict dst, const uint64_t *restrict src, size_t n)
{
	size_t chunks;
	size_t offset;

	chunks = n >> 3;
	offset = n - (chunks << 3);
	while (chunks--)
	{
		*dst++ = *src++;
		*dst++ = *src++;
		*dst++ = *src++;
		*dst++ = *src++;
		*dst++ = *src++;
		*dst++ = *src++;
		*dst++ = *src++;
		*dst++ = *src++;
	}
	while (offset--)
		*dst++ = *src++;
}

void __attribute__((nonnull))
*mem_cpy(void *restrict dst, const void *restrict src, size_t n)
{
	uint8_t			*dst8;
	const uint8_t	*src8;
	size_t			qwords;
	size_t			aligned_size;

	dst8 = (uint8_t*)dst;
	src8 = (const uint8_t*)src;
	qwords = n >> 3;
	if (n > 8)
	{
		copy512((uint64_t*)dst, (const uint64_t*)src, qwords);
		return (dst);
	}
	aligned_size = qwords << 3;
	n -= aligned_size;
	dst8 += aligned_size;
	src8 += aligned_size;
	copy_small(dst8, src8, n);
	return (dst);
}

//-----------------------------------------------------------------------------
// Tests
//
double		test(int (*f)(char *, char *, size_t),
			char *test_data,
			char *test_dst,
			char *test_name,
			size_t i)
{	
	clock_t begin = clock();
	f(test_dst, test_data, i);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	return (time_spent);
}

char		*make_string(size_t size)
{
	char	*out;
	size_t	i;

	out = (char *)malloc(sizeof(char) * size);
	i = 0;
	while (i < size)
	{
		out[i] = i % 128;
		i++;
	}
	return (out);
}

int			test_usr(char *dst, char *src, size_t bytes)
{
	size_t	i;

	i = 0;
	while (i < iters)
	{
		mem_cpy(dst, src, bytes);
		/*assert(memcmp(dst, src, bytes) == 0);*/
		i++;
	}
	return (1);
}

int			test_lib(char *dst, char *src, size_t bytes)
{
	size_t	i;

	i = 0;
	while (i < iters)
	{
		memcpy(dst, src, bytes);
		/*assert(memcmp(dst, src, bytes) == 0);*/
		i++;
	}
	return (1);
}

int			test_different_sizes()
{
	size_t	power;
	size_t	i;
	size_t	size;
	double	lib;
	double	usr;
	double	lmbs;
	double	umbs;
	char	*src;
	char	*dst;

	i = 0;
	power = 32;
	iters = pow(2, power);
	printf("total bytes per iteration = %zuMB\n", iters / (size_t)pow(10, 6));
	printf("| bytes / string | lib (s) | usr (s) | lib (MB/s) | usr (MB/s) | lib / usr |\n");
	printf("|---|---|---|---|---|\n");
	while (i < power)
	{
		size = pow(2, i);
		src = make_string(size);
		dst = make_string(size);
		lib = test(test_lib, src, dst, "LIB", size);
		usr = test(test_usr, src, dst, "USR", size);
		lmbs = ((size * iters) / pow(10, 6)) / lib;
		umbs = ((size * iters) / pow(10, 6)) / usr;
		printf("|%-10zu|%-10lf|%-10lf|%-10.2lf|%-10.2lf|%-10lf|\n",
				size, lib, usr, lmbs, umbs, lib / usr);
		iters /= 2;
		free(src);
		free(dst);
		i++;
	}
	return (1);
}

int			main(void)
{
	test_different_sizes();
}
