#include<stdio.h>

//Function to find the Largest Number

int getMax(int array[], int n)
{
	int max = array[0];
	int i;
	for (i = 1; i < n; i++) if (array[i] > max)
	max = array[i];
	return max;
} 

//Function for Count sort

void countSort(int array[], int n, int dig)
{
	int output[n]; 
	int i, count[10] = { 0 };
	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(array[i] / dig) % 10]++; 
	
	// Change count[i] so that count[i] now contains actual position of this
	// digit in output[] 
	
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1]; 
	
	// Build the output array
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(array[i] / dig) % 10] - 1] = array[i];
		count[(array[i] / dig) % 10]--;
	} 
	
	// Copy the output array to arr[], so that arr[] now 
	// contains sorted numbers according to current digit
	
	for (i = 0; i < n; i++) array[i] = output[i]; }

	// The main function to that sorts arr[] of size n using Radix Sort void
	radixsort(int array[], int n)
	{ //Get the largest number to know the
	// maximum number of digits
		int m = getMax(array, n); int dig; //Counting
	// sort is performed for every digit
	for (dig = 1; m / dig > 0; dig *= 10)
	
	countSort(array, n, dig);
}

//Function to Print Array
void print(int arr[], int n) {
int i;
for (i = 0; i < n; i++)
printf("%d ", arr[i]);
} 
int main() {
int arr[] = { 140, 65, 85, 110, 612, 54, 12, 86 };
int n = sizeof(arr) / sizeof(arr[0]);
radixsort(arr, n);
print(arr, n);
return 0;
}
