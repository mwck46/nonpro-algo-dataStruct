#include <iostream>
#include <vector>
#include "minheap.h"

using namespace std;

int main()
{
  vector<int> arr{ 10, 4, 5, 3, 7, -1, 7 };
  minheap h;
  for (auto& elem : arr) {
    h.push(elem);
  }

  for (int i = 0; i < arr.size(); ++i) {
    cout << h.pop_min() << endl;
  }
}
