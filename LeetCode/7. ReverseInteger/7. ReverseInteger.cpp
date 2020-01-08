#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
    static_assert(INT_MAX == 2'147'483'647);
    static_assert(INT_MIN = -2'147'483'647 - 1);
public:
    int reverse(int x)
    {
        if(x == INT_MIN)
        {
            return 0;
        }

        int sign;
        if(x >= 0)
        {
            sign = 1;
        }
        else
        {
            sign = -1;
            x = -x;
        }
        int res = 0;
        while( x>0)
        {
            int d =  x % 10;
            x /= 10;
            if(res < INT_MAX / 10 || res == INT_MAX / 10 && d <= INT_MAX % 10)
            {
                res = res * 10 + d;
            }
            else
            {
                return 0;
            }
        }
        return res * sign;
    }
}


/*
 Second Approach: loop through the digits of the integer and create the reverse of the number

 Time Complexity: O(number of digits)

 Space Complexity: O(number of digits)
 */

class Solution2
{
   int getDigits(int x)
    {
        int number=x;

        int digits=0;

        while(number)
        {
            number/=10;

            digits++;
        }
        return digits;
    }

public:
    int reverse(int x)
    {
        long int answer=0;

        int digits=getDigits(x);

        long int place=pow(10, digits-1);

        while(x)
        {
            int digit=x % 10;

            long int total=(digit * place);

            answer+=total;

            x/=10;

            place/=10;
        }

        return (answer > numeric_limits<int>::max() || answer < numeric_limits<int>::min()) ? 0 : answer;
    }
};

