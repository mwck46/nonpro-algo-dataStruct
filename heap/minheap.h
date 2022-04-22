#ifndef MINHEAP_H

#include "heap.h"
class minheap : public heap
{
public:
  int pop_min();
  void push(int newElem);
private:
  void insertHeapify(int idx);
  void removeHeapify(int idx);
};
#endif // !MINHEAP_H