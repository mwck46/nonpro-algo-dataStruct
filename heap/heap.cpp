#include "heap.h"

heap::heap() : _maxElemNum(100), _endIdx(-1)
{
	_elem = new int[_maxElemNum];
}

heap::~heap()
{
	delete[] _elem;
}

void heap::push(int newElem)
{
  if (++_endIdx >= _maxElemNum)
    doubleStoreSize();

  *(_elem + _endIdx) = newElem;
  heapify(_endIdx);
}

void heap::doubleStoreSize()
{
	int newSize = _maxElemNum * 2;
	int* newArr = new int[newSize];
	std::copy(_elem, _elem + _maxElemNum, newArr);
	delete[] _elem;
	_elem = newArr;
}

int heap::getParentIdx(int idx)
{
  return (idx-1)/2;
}

int heap::getRightChildIdx(int idx)
{
  return idx * 2 + 2;
}

int heap::getLeftChildIdx(int idx)
{
  return idx * 2 + 1;
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

