#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;


/*
 * Approaches:

 * 1) Since we are just concerned with whether or not the number from the range [1, n] in the input vector
 * and not its frequency, we can just use an unordered_set<int> instead of an unordered_map<int, int>
 * (unordered_set will also get rid of duplicates). Then, we just iterate over the numbers [1, n] if a
 * number is not in the unordered_set, add it to the result vector.
 *
 * Time complexity: O(n)
 * Space complexity: O(n-number of duplicate elements)
 *
 * 2) This is the big IQ play. For each number in the vector, we multiply the number at the index (current number-1)
 * in the vector by -1, if it isn't already negative. Then, we loop over the vector and if any number is positive,
 * we know that the number equal to the (current index+1) is not in vector. 
 * Time complexity: O(n)
 * Space complexity: O(1)
 *
 */

vector<int> findDisappearedNumbers(vector<int>& nums)
{
    vector<int> result;

    if(nums.empty())
    {
        return result;
    }

    int n=int(nums.size());

    unordered_set<int> cache(nums.begin(), nums.end());

    for(int number=1;number<=n;++number)
    {
        if(!cache.count(number))
        {
            result.push_back(number);
        }
    }

    return result;
}




class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> & nums){
    
        vector<int> result;

        if(nums.empty())
        {
            return result;
        }

        int n=int(nums.size());

        for(int i=0;i<n;++i)
        {
            int current=nums[i];

            int oneLess=abs(current)-1;

            if(nums[oneLess] > 0)
            {
                nums[oneLess]*=-1;
            }
        }

        for(int index=0;index<n;++index)
        {
            if(nums[index] > 0)
            {
                result.emplace_back(index+1);
            }
        }

        return result;
    }
};



//Runtime 128 ms, Memory Usage 15 Mb
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int x : nums)
        {
            int i = abs(x) - 1;
            if(nums[i] > 0)
            {
                nums[i] = -nums[i]; 
            }
        }
        vector<int> ans;
        for(int v = 1; v <= (int)nums.size(); v++)
        {
            int i =  v - 1;
            if(nums[i] > 0)
            {
                ans.push_back(v);
            }
        }
        return ans;
    }
};