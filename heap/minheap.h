#ifndef MINHEAP_H

#include "heap.h"
class minheap : public heap
{
public:
  int pop_min();
  void push(int newElem);
private:
  void heapify4push(int idx);
  void heapify4pop(int idx);
};
#endif // !MINHEAP_H