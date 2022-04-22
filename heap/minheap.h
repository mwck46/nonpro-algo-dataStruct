#ifndef MINHEAP_H

#include "heap.h"
class minheap : public heap
{
public:
  int pop_min();
private:
  void heapify(int idx);
};
#endif // !MINHEAP_H