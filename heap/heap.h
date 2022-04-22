#ifndef HEAP_H

#include <algorithm>

class heap
{
public:
	heap();
	~heap();
	void push(int newElem);
	int pop();
private:
	int _maxElemNum;
	int* _elem;
  int _endIdx;
	
  void doubleStoreSize();

  int getParentIdx(int idx);
  int getRightChildIdx(int idx);
  int getLeftChildIdx(int idx);

  // Need concrete implementation for min heap and max heap
  virtual void heapify() = 0;
};

#endif // !HEAP_H



