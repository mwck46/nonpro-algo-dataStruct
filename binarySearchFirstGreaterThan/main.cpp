#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

// First index i, such that nums[i] > target
int binarySearchFirstGreaterThan(const vector<int>& nums, int target)
{
  int l = 0;
  int r = nums.size();
  
  
  while(l < r)
  {
    int m = (r+l)/2;
    cout << l << r << m <<endl;
    int mid = nums[m];
    
    if(mid > target)
    {
      r = m;
    }
    else if (mid <= target)
    {
      l = m+1;
    }
  }
  
  return l;
}

int main()
{
  vector<int> arr1{ -1,0,3,5,9,12 };
  auto rst1 = binarySearchFirstGreaterThan(arr1, 4);
  assert(rst1 == 3);
  
  vector<int> arr2{ 3 };
  auto rst2 = binarySearchFirstGreaterThan(arr2, 3);
  assert(rst2 == 0);
  
  vector<int> arr3{ -1,0,3,5,9,12 };
  auto rst3 = binarySearchFirstGreaterThan(arr3, 12);
  assert(rst3 == 6);
}