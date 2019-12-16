#include <iostream>
#include <string>
#include <algorithm>



class Solution 
{
public:
	bool isLetter(char c)
	{
		return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
	}

    string reverseOnlyLetters(const string& s) 
    {
    	string res = s;
    	int dst = (int)res.size() - 1;
    	for(int src = 0; src < (int)s.size(); src++)
    	{
    		if(isLetter(s[src]))
    		{
    			while(!isLetter(res[dst]))
    			{
    				dst--;
    				assert(dst >= 0);
    			}
    			res[dst] = s[src];
    			dst--;
    		}
    	}   
    	return res;
    }
};

class Solution2 
{
public:
	bool isLetter(char c)
	{
		return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
	}

    string reverseOnlyLetters(const string& s) 
    {
    	int i = 0;
    	int j = (int)s.size() - 1;
    	while(true)
    	{
    		while(i < j && !isLetter(s[i]))
    		{
    			i++;
    		}
    		while(i < j && !isLetter(s[j]))
    		{
    			j--;
    		}
    		if(i < j)
    		{
    			swap(s[i], s[j]);
    			i++;
    			j--;
    		}
    		else
    		{
    			break;
    		}
    	}
    	return move(s);
    }
};