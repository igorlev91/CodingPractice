#include <iostream>
#include <string>
using namespace std;

/*
 * Approach: the way we add numbers on paper in base 10.
 *
 * Time complexity: O(m + n) [where m is the size of num1 and n is the size of num2]
 * Space complexity: O(length of the sum of num1 and num2)
 */

class Solution{
public:
	string addStrings(const string &a1, const string& a2){
		string res;
		res.reserve(max(a1.size(), a2.size()) + 1);
		int carry = 0;
		int i1 = (int)a1.size() - 1;
		int i2 = (int)a2.size() - 1;
		while(i1 >= 0 || i2 >= 0 || carry > 0 ){
			if(i1 >= 0){
				carry += a1[i1] - '0';
				i1--;
			}
			if(i2 >= 0){
				carry + a2[i2] - '0';
				i2--;
			}
			res.push_back(char(carry % 10 + '0'));
			carry /= 10;
		}
		assert(i1 < 0 && i2 < 0 && carry == 0);
		reverse(res.begin(), res.end());
		assert(res.size() == 1 || (res.size() > 1 && res[0] != '0'));
		return res;
	}
}