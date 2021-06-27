#include "inc/core.h"

/*void counting_sort(int arr[], int n)*/
/*{*/
 
    /*int maximum;*/
    /*int *count;*/
    /*int *sorted_arr;*/
 
	/*maximum = -1;*/
    /*for(int i=0;i<n;i++)*/
	/*{*/
        /*if(maximum < arr[i])*/
            /*maximum = arr[i];*/
    /*}*/
	/*count = malloc(sizeof(int) * maximum);*/
    /*for(int i = 0; i <= maximum; i++)*/
	/*{*/
        /*count[i] = 0;*/
    /*}*/
    /*for(int i = 0; i < n; i++)*/
	/*{*/
        /*count[arr[i]]++;*/
    /*}*/
    /*for(int i = 1; i <= maximum; i++)*/
	/*{*/
        /*count[i] += count[i - 1];*/
    /*}*/
	/*sorted_arr = malloc(sizeof(int) * n);*/
    /*for(int i = 0; i < n; i++)*/
	/*{*/
        /*sorted_arr[count[arr[i]]-1] = arr[i];*/
        /*count[arr[i]]--;*/
    /*}*/
    /*for(int i = 0; i < n; i++)*/
	/*{*/
        /*printf("%d ", sorted_arr[i]);*/
    /*}*/
    /*printf("\n");*/
/*}*/

static void counting_sort_8s(t_uint8 *arr, t_uint8 *aux, size_t n)
{
	size_t cnt[256] = { 0 };
	size_t i;

	// Count number of occurrences of each octet.
	for (i = 0 ; i < n ; ++i) {
		cnt[arr[i]]++;
	}

	// Calculate prefix sums.
	size_t a = 0;
	for (int j = 0 ; j < 256 ; ++j) {
		size_t b = cnt[j];
		cnt[j] = a;
		a += b;
	}

	// Sort elements
	for (i = 0 ; i < n ; ++i) {
		// Get the key for the current entry.
		t_uint8 k = arr[i];
		// Find the location this entry goes into in the output array.
		size_t dst = cnt[k];
		// Copy the current entry into the right place.
		aux[dst] = arr[i];
		// Make it so that the next 'k' will be written after this one.
		// Since we process source entries in increasing order, this makes us a stable sort.
		cnt[k]++;
	}
}
