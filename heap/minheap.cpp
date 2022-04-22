#include "minheap.h"

int minheap::pop_min()
{
  if (_endIdx < 0)
    throw std::exception("Index out of range");

  int root = _elem[0];
  _elem[0] = _elem[_endIdx--];
  if (_endIdx > 0) {
    heapify4pop(0);
  }
  return root;
}

void minheap::heapify4pop(int idx)
{
  int rId = getRightChildIdx(idx);
  int lId = getLeftChildIdx(idx);

  int r = INT_MAX;
  if (rId >= 0)
    r = _elem[rId];
  int l = INT_MAX;
  if (lId >= 0)
    l = _elem[lId];

  int p = _elem[idx];
  if (r >= l && p > l) {
    swapElem(idx, lId);
    heapify4pop(lId);
  }
  else if (l >= r && p > r) {
    swapElem(idx, rId);
    heapify4pop(rId);
  }
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


