#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

int binary_search(const vector<int>& nums, int target)
{
  int l = 0;
  int r = nums.size()-1;
  
  int idx = -1;
  while(l <= r)
  {
    int m = (r+l)/2;
    //cout << l << r << m <<endl;
    int mid = nums[m];
    
    if(mid > target)
    {
      r = m-1;
    }
    else if (mid < target)
    {
      l = m+1;
    }
    else
    {
      idx = m;
      break;
    }
  }
  
  return idx;
}

int main()
{
  vector<int> arr1{ -1,0,3,5,9,12 };
  auto rst1 = binary_search(arr1, 9);
  assert(rst1 == 4);
  
  vector<int> arr2{ 3 };
  auto rst2 = binary_search(arr2, 3);
  assert(rst2 == 0);
  
  vector<int> arr3{ -1,0,3,5,9,12 };
  auto rst3 = binary_search(arr3, 2);
  assert(rst3 == -1);
}