#include "array_merge.h"
#include "../mergesort/mergesort.c"

int totalSize(int length, int* array){
  int size = 0;
  for(int i = 0, i < length, ++i){
  	size = array[i] + size;
  }
  return size
}

int* mergeSub(int** arr, int* size, int num){

}


int* array_merge(int num_arrays, int* sizes, int** values) {
  int total_size;
  /*
   * IDEA FOR APPROACHING THIS TASK
   * 1. We merge all of the subarrays together (maybe through iterating through a for loop?)
   * 2. We run mergesort on the array.
   * 3. We remove duplicates from the array with another function.
   * 4. Finally, we get the size of the array and insert said size value into the array.
   *
   */
  return sizes;
}


