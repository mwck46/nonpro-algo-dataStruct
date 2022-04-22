#include "heap.h"

heap::heap() : _maxElemNum(5), _endIdx(-1)
{
  _elem = new int[_maxElemNum];
}

heap::~heap()
{
  delete[] _elem;
}

void heap::doubleStoreSize()
{
  int newSize = _maxElemNum * 2;
  int* newArr = new int[newSize];
  std::copy(_elem, _elem + _maxElemNum, newArr);
  delete[] _elem;
  _elem = newArr;
  _maxElemNum = newSize;
}

int heap::getParentIdx(int idx)
{
  return (idx - 1) / 2;
}

int heap::getRightChildIdx(int idx)
{
  int r = idx * 2 + 2;
  return (r > _endIdx) ? -1 : r;
}

int heap::getLeftChildIdx(int idx)
{
  int l = idx * 2 + 1;
  return (l > _endIdx) ? -1 : l;
}

void heap::swapElem(int idx1, int idx2)
{
  int temp = _elem[idx1];
  _elem[idx1] = _elem[idx2];
  _elem[idx2] = temp;
}

int heap::compareElem(int idx1, int idx2)
{
  if (_elem[idx1] > _elem[idx2])
    return 1;
  else if (_elem[idx1] < _elem[idx2])
    return -1;
  else
    return 0;
}