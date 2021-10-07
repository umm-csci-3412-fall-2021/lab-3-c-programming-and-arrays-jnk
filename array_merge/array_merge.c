#include "array_merge.h"
#include "../mergesort/mergesort.c"

int totalSize(int length, int* array){
  int size = 0;
  for(int i = 0; i < length; ++i){
  	size = array[i] + size;
  }
  return size;
}

int* mergeSubarrays(int length, int* size, int** subArrays){
  int total_size = totalSize(length, size);
  int *unsorted_arr = (int*) calloc(total_size, sizeof(int));
  int copyIndex = 0;
  for(int i = 0; i < length; ++i){
  	for(int j = 0; j < size[i]; ++j){
		unsorted_arr[copyIndex] = subArrays[i][j];
		++copyIndex;
	}
  }
  return unsorted_arr;
}


int* array_merge(int num_arrays, int* sizes, int** values) {
  int total_size_arr = totalSize(num_arrays, sizes);
  int* unordered_arr = mergeSubarrays(num_arrays, sizes, values);

  mergesort(total_size_arr, unordered_arr);

  int sortedInd = 0;

  for(int i = 0; i < total_size_arr; i++){
  	if(unordered_arr[i] != unordered_arr[i+1]){
		++sortedInd;
	}
  }

  int *sorted_arr = (int*) calloc(sortedInd+1, sizeof(int));

  sorted_arr[0] = sortedInd;

  int nodupe_ind = 1;

  for(int i = 0; i < total_size_arr; i++){
		if(unordered_arr[i] != unordered_arr[i+1]){
			sorted_arr[nodupe_ind] = unordered_arr[i];
			++nodupe_ind;
		}
  }

  free(unordered_arr);
  return sorted_arr;
  /*
   * IDEA FOR APPROACHING THIS TASK
   * 1. We merge all of the subarrays together (maybe through iterating through a for loop?)
   * 2. We run mergesort on the array.
   * 3. We remove duplicates from the array with another function.
   * 4. Finally, we get the size of the array and insert said size value into the array.
   *
   */
}


