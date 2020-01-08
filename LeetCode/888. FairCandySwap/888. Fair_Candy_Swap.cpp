#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//runtime 776 ms
class Solution 
{
public:
    vector<int> fairCandySwap(const vector<int>& a, const vector<int>& b) 
    {
        int sumA = 0;
        for(int v : a)
        {
            sumA += v;
        }
        int sumB = 0;
        for(int v : b)
        {
            sumB += v;
        }
        for(int av : a)
        {
            for(int bv : b)
            {
                if(sumA - av + bv == sumB - bv + av)
                {
                    return vector<int>{av, bv};
                }
            }
        }
        throw invalid_argument("no solution for given A and B is found");

    }
};


//Runtime 132 ms MemoryUsage: 22.1 Mb
class Solution 
{
public:
    vector<int> fairCandySwap(const vector<int>& a, vector<int>& b) 
    {
        int sumA = 0;
        for(int v : a)
        {
            sumA += v;
        }
        unoredered_set<int> bValues;
        int sumB = 0;
        for(int v : b)
        {
            sumB += v;
            bValues.insert(v);
        }
        assert((sumA - sumB) % 2 == 0);
        int diff = (sumA - sumB) /2;
        for(int av : a)
        {
            int bv = av - diff;
            if(bValues.count(bv) > 0)
            {
                return vector<int>{av, bv};
            }
        }
        throw invalid_argument("no solution for given A and B");
    }
};


//Runtime 40 ms MemoryUsage: 12.4 Mb
class Solution 
{
public:
    vector<int> fairCandySwap(const vector<int>& a, vector<int>& b) 
    {
      int sumA = 0;
      for(int v : a)
      {
        sumA += v;
      }
      sort(b.begin(), b.end());
      int sumB = 0;
      for(int v : b)
      {
        sumB += v;
      }
      assert((sumA - sumB) % 2 == 0);
      int diff = (sumA - sumB) / 2;
      for(int av : a)
      {
        int bv = av - diff;
        if(binary_search(b.begin(), b.end(), bv))
        {
            return vector<int>{av, bv};
        }
      }
      throw invalid_argument("no solution for given A and B");
    }
};

//Runtime 52 ms MemoryUsage: 12.4 Mb
class Solution 
{
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b){
    sort(a.begin(), a.end());
    int sumA = 0;
    for(int v : a){
        sumA += v;
    }
    sort(b.begin(), b.end());
    int sumB = 0;
    for(int v : b){
        sumB += v;
    }
    assert((sumA - sumB) % 2 == 0);
    int diff = (sumA - sumB) / 2;
    int bi = 0;
    for(int av : a){
        int bv = av - diff;
        while(bi < (int)b.size() && b[bi] < bv){
            bi++;
        }
        if(bi < (int)b.size() && b[bi] == bv){
            return vector<int>{av, bv};
        }
    }

    throw invalid_argument("no solution for given A and B");
    }
};
