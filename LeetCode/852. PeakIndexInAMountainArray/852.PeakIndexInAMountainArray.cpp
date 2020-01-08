#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
public:
    int peakIndexInMountainArray(const vector<int>& a) 
    {
        int left = 0;
        int right = (int)a.size() - 1;
        while(right - left > 2)
        {
            int mid = left + (right - left) / 2;
            if(a[mid] < a[mid + 1])
            {
                left = mid;
            }
            else
            {
                right = mid + 1;
            }
        }
        assert(right - left == 2);
        return left + 1;
    }
};