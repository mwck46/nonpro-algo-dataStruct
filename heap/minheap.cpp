#include "minheap.h"

void minheap::heapify(int idx)
{
  if (idx == 0)
    return;

  int parentIdx = getParentIdx(idx);
  if (compareElem(parentIdx, idx) > 0) {
    swapElem(parentIdx, idx);
  }

  heapify(parentIdx);
}
