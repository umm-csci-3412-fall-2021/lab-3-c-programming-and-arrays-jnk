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
  const int rangeSize = endIndex - startIndex;
  int destination[] = new int[rangeSize];
  int firstIndex = startIndex;
  int secondIndex = midPoint;
  int copyIndex = 0;

  while(firstIndex < midPoint && secondIndex < endIndex) {
    if (values[firstIndex] < values[secondIndex]) {
      destination[copyIndex] = values[firstIndex];
      ++firstIndex;
    }
    
    else {
      destination[copyIndex] = values[firstIndex];
      ++secondIndex;    
    }
    ++copyIndex;
  }

  while(firstIndex < midPoint) {
    destination[copyIndex] = values[secondIndex];
    ++copyIndex;
    ++firstIndex;
  }

  while(secondIndex < endIndex) {
    destination[copyIndex] = values[secondIndex];
    ++copyIndex;
    ++secondIndex;
  }
  
  int i;
  for(int i = 0; i < rangeSize; ++i) {
    values[i + startIndex] = destination[i];
  }
}

private boolean needsSorting(int rangeSize) {
  return rangeSize >= 2;
}


bool needsSorting(int rangeSize){
  return rangeSize >= 2;
}


