#include <iostream>
using namespace std;
void blockSwap(int a[], int s1, int s2, int n)
{
    int temp;
    for(int i = 0; i<d; i++)
    {
        temp = a[s1 + i];
        a[s1 + i] = a[s2 + i];
        a[s2 + i] = temp;
    }
}
void blockRotation(int a[], int d, int n)
{
    if(n-d == d)
    {
        blockSwap(a, 0, d, d);
        return;
    }
    if(d < n-d)
    {
        blockSwap(a, 0, n-d, d);
        blockRotation(a, d, n-d);
    }
    else
    {
        blockSwap(a, 0, d, n-d);
        blockRotation(a+n-d, 2*d - n, d); // Doubt
    }
}
void reverseArray(int a[], int d, int n)
{
    int temp;
    for(; d<n; d++, n--)
    {
        temp = a[d];
        a[d] = a[n];
        a[n] = temp;
    }
}
void rotateByReversal(int a[], int d, int n)
{
    reverseArray(a, 0, d-1);
    reverseArray(a, d, n-1);
    reverseArray(a, 0, n-1);
}
void leftRotatebyOne(int a[], int n)
{
    int temp = a[0];
    for(int i=0; i<n-1; i++)
        a[i] = a[i+1];
    a[n-1] = temp;
}
void leftRotate(int a[], int d, int n)
{
    for(int i=0; i<d; i++)
    {
        leftRotatebyOne(a, n);
    }
}
int gcd(int a, int b)
{
    if(b == 0)
        return 0;
    else
        return (b, a%b);
}
void jugglingMethod(int a[], int d, int n)
{
    int g = gcd(d, n);
    int temp, i, j ,k;
    for(i=0; i<g; i++)
    {
        j = i;
        temp = a[j];
        while(true)
        {
            k = j+d;
            if(k >= n)
                k = k-n;
            if(k == i)
                break;
            arr[j] = k;
            j = k;
        }
        a[i] = a[i+g];
        a[j] = temp;
    }
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int d = 2;
    int n = sizeof(a)/sizeof(a[0]);
    leftRotate(a, d, n);
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}
