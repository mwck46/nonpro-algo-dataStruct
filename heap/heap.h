#ifndef HEAP_H

#include <algorithm>

class heap
{
public:
	heap();
	~heap();
	void push(int newElem);

protected:
	int _maxElemNum;
	int* _elem;
  int _endIdx;
	
  void doubleStoreSize();

  int getParentIdx(int idx);
  int getRightChildIdx(int idx);
  int getLeftChildIdx(int idx);

  void swapElem(int idx1, int idx2);
  int compareElem(int idx1, int idx2);

  // Need concrete implementation for min heap and max heap
  virtual void heapify(int idx) = 0;
};

#endif // !HEAP_H



