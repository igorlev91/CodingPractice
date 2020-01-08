#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
Approach: Just find the minimum and for each element add the difference between the current element
and the minimum to the total moves.

Time complexity: O(n) [where n is the total number of elements in the input vector]
Space complexity: O(1)
*/

int minMoves(vector<int>& nums)
{
    int moves=0;

    int minimum=*(min_element(nums.begin(), nums.end()));

    for(int number : nums)
    {
        moves+=number-minimum;
    }

    return moves;
}