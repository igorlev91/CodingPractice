#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
public:
    vector<int> sortArrayByParityII(vector<int>& a) 
    {
        vector<int> res(a.size());
        int even = 0;
        int odd = 1;
        for(int e : a)
        {
        	if((e & 1) == 0)
        	{
        		res[even] = e;
        		even += 2;
        	}
        	else
        	{
        		res[odd] = e;
        		odd += 2;
        	}
        }
        return res;
    }
};



class Solution2
{
public:
    vector<int> sortArrayByParityII(vector<int>& a) 
    {
       int even = (int)a.size() - 2;
       int odd = (int)a.size() - 1;
       while(true)
       {
       		while(even >= 0 && (a[even] & 1) == 0)
       		{
       			even -= 2;
       		}
       		while(odd >= 0 && (a[odd] & 1) == 1)
       		{
       			odd -= 2;
       		}
       		if(even >= 0)
       		{
       			swap(a[even], a[odd]);
       			even -= 2;
       			odd -= 2;

       		}
       		else
       		{
       			break;
       		}
       }
       return move(a);
    }
};