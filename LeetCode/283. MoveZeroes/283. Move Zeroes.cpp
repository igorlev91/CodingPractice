#include <iostream>
#include <vector>
using namespace std;


//runtime 12 ms
class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int i = 0;
        while(i < (int)a.size() && a[i] != 0)
        {
        	i++;
        }
        int j = i;
        for(; i < (int)a.size(); i++)
        {
        	if(a[i] != 0)
        	{
        		swap(a[i], a[j]);
        		j++;
        	}
        }
    }
};

/*
 * Approache:
 *  Move all non-zero elements to the left as far as possible in the vector.
 * Then, fill the rest of the spots with zeroes.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
    	if(nums.empty())
    	{
    		return;
    	}

    	int insertPosition = 0;
    	for(int number : nums)
    	{
    		if(number!=0)
        	{
    			nums[insertPosition] = number;
    			insertPosition++;
    		}
    	}
    	int n = int(nums.size());

    	while(insertPosition < n) 
    	{
    		nums[insertPosition]= 0;
        	insertPosition++;
    	}
    }
};


class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
    	int i = 0;
    	while(i < (int)a.size() && a[i] != 0){
    		i++;
    	}
    	int j = i;
    	for(; i < (int)a.size(); i++){
    		if(a[i] != 0){
    			a[j] = a[i];
    			j++;
    		}
    	}
    	for(; j < (int)a.size(); j++){
    		a[j] = 0;
    	}
    }
};
