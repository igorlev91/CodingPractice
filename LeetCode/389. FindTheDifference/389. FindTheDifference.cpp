#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) Using an unordered_map as a hashtable, map each letter in t to its frequency.
 * Then, loop over s and decrease the frequency of each letter. Finally, loop over the hashtable
 * and the character that appears once, is the extra character.
 *
 * Time complexity: O(m + n) [where m is the length of s and n is the length of t]
 * Space complexity: O(m)
 */


class Solution 
{
public:
    char findTheDifference(const string& s, const string& t)
    {
        char result{};

        if(s.empty())
        {
            if(!t.empty())
            {
                return t[0];
            }
            else
            {
                return result;
            }
        }

        unordered_map<char, int> hashtable;

        for(char letter : t)
        {
            hashtable[letter]++;
        }

        for(char letter : s)
        {
            if(hashtable.count(letter))
            {
                if(hashtable[letter] > 0)
                {
                    hashtable[letter]--;
                }
            }
        }

        for(const auto & element : hashtable)
        {
            if(element.second==1)
            {
                result=element.first;

                break;
            }
        }

        return result;
    }

};


class Solution2 
{
public:
    char findTheDifference(const string& s, const string& t)
    {
        char answer = 0;
        for(char letter : s)
        {
            answer ^= letter;
        }
        for(char letter : t)
        {
            answer ^= letter;
        }
        return answer;
    }
};