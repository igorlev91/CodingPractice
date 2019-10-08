#include <iostream>
using namespace std;
int main()
{
    int arr[] = {-2, -3, -5, -7, -2, -8, -9, -3};
    int sum=0, max_sum=INT_MIN;
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
    {
        sum = sum + arr[i];
        if(sum>max_sum)
        {
            max_sum=sum;
        }
        if(sum<0)
        {
            sum = 0;
        }
    }
    cout<<"Maximum Contiguous Subarray: "<<max_sum<<"\n";
    return 0;
}
