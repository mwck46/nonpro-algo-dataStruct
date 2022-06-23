#ifndef MERGESORT_H
#define MERGESORT_H

#include <stdlib.h>
#include <string.h> 
#include "ArrayEx.h"

using namespace util;

class mergesort
{
public:
  void sort(int* arr, int arrSize)
  {
    if (arrSize == 1)
    {
      return;
    }

    int leftArrSize = arrSize / 2;
    int* leftArr = (int*)malloc(leftArrSize * sizeof(int));
    memcpy(leftArr, arr, leftArrSize * sizeof(int));
    //_printArray(leftArr, leftArrSize);
    sort(leftArr, leftArrSize);

    int rightArrSize = arrSize - leftArrSize;
    int* rightArr = (int*)malloc(rightArrSize * sizeof(int));
    memcpy(rightArr, arr + leftArrSize, rightArrSize * sizeof(int));
    //_printArray(rightArr, rightArrSize);
    sort(rightArr, rightArrSize);

    merge(arr, leftArr, leftArrSize, rightArr, rightArrSize);
    ArrayEx::cout(arr, arrSize);
  }

private:
  void merge(int* dest, int* arr1, int arr1Size, int* arr2, int arr2Size)
  {
    int i = 0, j = 0, k = 0;
    while (i < arr1Size && j < arr2Size)
    {
      if (arr1[i] < arr2[j])
      {
        dest[k++] = arr1[i++];
      }
      else
      {
        dest[k++] = arr2[j++];
      }
    }
    while (i < arr1Size)
    {
      dest[k++] = arr1[i++];
    }
    while (j < arr2Size)
    {
      dest[k++] = arr2[j++];
    }
  }


};

#endif
