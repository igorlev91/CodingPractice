#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//runtime 28 ms, memory usage 9.5 mb
class Solution 
{
public:
    vector<int> sortArrayByParity(vector<int>& a) 
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
        		swap(a[i], a[j]);
        		i++;
        		j--;
        	}
        	else
        	{
        		break;
        	}
        }
        return move(a);
    }
};