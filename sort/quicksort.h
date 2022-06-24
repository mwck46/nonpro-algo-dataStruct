#ifndef QUICKSORT_H
#define QUICKSORT_H

// Inline implementation of quicksort
class quicksort
{
public:
  static void sort(int* arr, int arrSize)
  {
    if (arrSize <= 1)
      return;

    int i = arrSize - 1;
    int p = arr[i];

    --i;
    int j = -1;
    while (i > j)
    {
      if (arr[i] > p)
      {
        --i;
      }
      else if (arr[i] < p)
      {
        ++j;
        swap(arr, i, j);
      }
      else
      {
        break;
      }
    }
    // At this point arr[idx<=j] all < p and arr[i< idx <arrSize-1] > p

    swap(arr, arrSize - 1, i + 1);
    // At this point arr[0,...,j-1,j] all < p and arr[i+2, i+3, ..., arrSize-1] > p
    quicksort::sort(arr, j + 1);
    quicksort::sort(arr + i + 2, arrSize - 1 - (i + 2) + 1);
  }

private:
  static void swap(int* tri, int i, int j)
  {
    int temp = tri[i];
    tri[i] = tri[j];
    tri[j] = temp;
  }
};

#endif
