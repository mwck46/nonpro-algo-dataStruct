#include "minheap.h"

int minheap::pop_min()
{
  if (_endIdx < 0)
    throw std::exception("Index out of range");

  if (_endIdx == 1)
    return _elem[_endIdx--];

  int smallest = _elem[0];
  _elem[0] = _elem[_endIdx--];
  heapify4pop(0);
  return smallest;
}

void minheap::heapify4pop(int idx)
{
}

void minheap::push(int newElem)
{
  if (++_endIdx >= _maxElemNum)
    doubleStoreSize();

  *(_elem + _endIdx) = newElem;
  heapify4push(_endIdx);
}

void minheap::heapify4push(int idx)
{
  if (idx == 0)
    return;

  int parentIdx = getParentIdx(idx);
  if (compareElem(parentIdx, idx) > 0) {
    swapElem(parentIdx, idx);
    heapify4push(parentIdx);
  }
}


