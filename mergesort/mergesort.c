#include "mergesort.h"

void mergesort(int size, int values[]) {
  // This obviously doesn't actually do any *sorting*, so there's
  // certainly work still to be done.
  mergesortRange(values, 0, values.length);
}

void mergesortRange(int values[], int startIndex, int endIndex) {
  int rangeSize = endIndex - startIndex;
  if (needsSorting(rangeSize)) {
    int midPoint = (startIndex + endIndex) / 2;
    mergesortRange(values, startIndex, midPoint);
    mergesortRange(values, midPoint, endIndex);
    mergeRanges(values, startIndex, midPoint, endIndex);
  }

void mergeRanges(int values[], int startIndex, int midPoint, int endIndex) {
}


bool needsSorting(int rangeSize){
  return rangeSize >= 2;
}


