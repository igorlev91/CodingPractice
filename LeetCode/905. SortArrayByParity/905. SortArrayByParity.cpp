#include <iostream>
#include <vector>
#include <algorithm>


//runtime 28 ms, memory usage 9.5 mb
class Solution 
{
public:
    std::vector<int> sortArrayByParity(std::vector<int>& a) 
    {
        int i = 0;
        int j = (int)a.size() - 1;
        while(true)
        {
        	while(i < j && (a[i] & 1) == 0)
        	{
        		i++;
        	}
        	while(i < j && (a[i] & 1) != 0)
        	{
        		j--;
        	}
        	if(i < j)
        	{
        		std::swap(a[i], a[j]);
        		i++;
        		j--;
        	}
        	else
        	{
        		break;
        	}
        }
        return std::move(a);
    }
};


class Solution
{
 	public:
    [[nodiscard]] std::vector<int> sortArrayByParity(std::vector<int> const& nums) const
    {
        std::vector<int> result(nums.size(), 0);
        size_t left = 0;
        size_t right = result.size() - 1;
        for (const int num : nums)
        {
        	if (num % 2 == 0)
                result[left++] = num;
            else
                result[right--] = num;
        }
    	return result;
    }
};


int main(int argc, char** argv)
{
    Solution s;
    std::vector<int> v{ 1,2,3,4 };
    for (auto i : s.sortArrayByParity(v))
    {
        std::cerr << i << '\t';
    }

    return 0;
}