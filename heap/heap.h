#ifndef HEAP_H

#include <algorithm>
#include <stdexcept>

class heap
{
public:
	heap();
	~heap();
	

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
};

#endif // !HEAP_H



