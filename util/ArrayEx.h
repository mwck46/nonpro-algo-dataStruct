#ifndef ARRAYEX_H
#define ARRAYEX_H

#include <stdio.h>
namespace util
{
  class ArrayEx
  {
  public:
    static void cout(int* arr, int arrSize)
    {
      for (int i = 0; i < arrSize; ++i)
      {
        printf("%d ", *(arr + i));
      }
      printf("\n");
    }

    static void swap(int* tri, int i, int j)
    {
      int temp = tri[i];
      tri[i] = tri[j];
      tri[j] = temp;
    }

  };

}

#endif // !ARRAYEX_H
