#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
 * Approach: we store the indices for all the occurrences of the target character in a vector<int> targetIndices.
 * Then, for each letter in the string, we calculate the distance from all target characters throughout the string
 * and take the minimum of these values. We place that minimum value in the appropriate spot in our vector<int> result.
 * Return the vector<int> result.
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(m) [where m is the number of indices of our target character]
 */

class Solution 
{
public:
    vector<int> shortestToChar(const string &s, char c) 
    {
        const int INF = (int)s.size();
        vector<int> res(s.size(), INF);
        int dist = INF;
        for(int i = 0; i < (int)s.size(); i++)
        {
        	if(s[i] == c)
        	{
        		dist = 0;
        	}
        	else
        	{
        		dist++;
        	}
        	res[i] = dist;
        }
        dist = INF;
        for(int i = (int)s.size() - 1; i >= 0; i--)
        {
        	if(s[i] == c)
        	{
        		dist = 0;
        	}
        	else
        	{
        		dist++;
        	}
        	res[i] = min(res[i], dist);
        }
        return res;
    }
};


class Solution2
{
public:
   
	vector<int> shortestToChar(string S, char C)
	{
    	if(S.empty())
    	{
        	return {};
    	}

    	size_t n=S.size();	

    	vector<int> result(n, 0);

    	vector<int> targetIndices;

    	for(size_t i=0;i<n;++i)
    	{
        	if(S[i]==C)
        	{
            	targetIndices.push_back(int(i));
        	}
    	}

    	for(size_t i=0;i<n;++i)
    	{
        	if(S[i]!=C)
        	{
            	int candidate=numeric_limits<int>::max();

            	for(int index : targetIndices)
            	{
                	candidate=min(candidate, abs(index - static_cast<int>(i)));
            	}

            	result[i]=candidate;
        	}
        	else
        	{
            	result[i]=0;
            }
        }

    	return result;
    }
};


