#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(4);
    map<int, int> mymap;
    for(int i=0; i<nums.size(); i++)
    {
        if(mymap.find(nums[i])!=mymap.end())
        {
            mymap[nums[i]]++;
            if(mymap[nums[i]]>=(nums.size()+1)/2)
            {
                cout<<"Majority Element is: "<<nums[i]<<"\n";
                break;
            }
        }
        else
            mymap[nums[i]] = 1;
    }
    cout<<"NONE\n";
    return 0;
}
