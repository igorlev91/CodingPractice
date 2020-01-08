 #include <iostream>
using namespace std;


/*
 * Approach: Simply add the individual digits of the number together and set num equal to the sum.
 * Repeat this while num >= 10 (not a single digit number)
 *
 * Time complexity: O(number of digits in num * difference between num and 10)
 * Space complexity: O(size of integer)
 */

class Solution {
public:
    int addDigits(int num) 
    {
    	while(num >= 10)
    	{
        	int next = 0;

        	while(num)
        	{
            	int digit=num % 10;

            	next+=digit;

            	num/=10;
        	}

        	num=next;
    	}

    	return num;
    }
};



class Solution2 
{
public:
    int addDigits(int num) 
    {
        return (n - 1) % 9 + 1;
    }
};
