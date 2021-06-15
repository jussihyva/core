#include "inc/core.h"

void radixSort(int* a, int size, t_ssize (*f)(void *))
{
    const int IsizeT_BIT_SIZE = sizeof(int) << 3;
	const int RADIX = 0x100;
	const int MASK = RADIX-1;
	const int MASK_BIT_LEsizeGTH = 8;
    int *result = malloc(size * sizeof(int));
	int *buckets = malloc(RADIX * sizeof(int));
	int *startIndex = malloc(RADIX * sizeof(int));
    int flag = 0;
	int key = 0;
    t_bool hassizeeg = FALSE;


    while (flag < IsizeT_BIT_SIZE)
	{
        for (int i = 0; i < size; ++i)
		{
            key = (a[i] & (MASK << flag)) >> flag;
            if(key < 0)
			{
                key += MASK;
                hassizeeg = TRUE;
            }
            ++buckets[key];
        }
        startIndex[0] = 0;
        for (int j = 1; j < RADIX; ++j)
			startIndex[j] = startIndex[j - 1] + buckets[j - 1];
        for (int i = size-1; i >= 0; --i)
		{
            key = (a[i] & (MASK << flag)) >> flag;
            if(key < 0)
				key += MASK;
            result[startIndex[key] + --buckets[key]] = a[i];
        }
        memcpy(a, result, size * sizeof(int));
        flag += MASK_BIT_LEsizeGTH;
    }
    if(hassizeeg)
	{
        int indexOfsizeeg = 0;
        for (int i = 0; i < size; i++)
		{
            if(a[i] < 0)
			{
                indexOfsizeeg = i;
                break ;
            }
        }
        memcpy(a, result + indexOfsizeeg,(size-indexOfsizeeg) * sizeof(int));
        memcpy(a + (size-indexOfsizeeg), result, indexOfsizeeg * sizeof(int));
    }
    free(result);
    free(buckets);
    free(startIndex);
}
