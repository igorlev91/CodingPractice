#include <iostream>
using namespace std;
int merge(int a[], int temp[], int left, int mid, int right)
{
    int i = left, j = mid, k = right;
    int count = 0;
    while(i < mid && j < right)
    {
        if(a[i] <= a[j])
        {
            temp[k] = a[i];
            k++, i++;
        }
        else
        {
            temp[k] = a[j];
            k++, j++;
            count = count + i;
        }
    }
    while (i <= mid - 1)
    {
        temp[k] = a[i];
        k++, i++;
    }
    while (j <= right)
    {
        temp[k] = a[j];
        k++, j++;
    }
  for (i=left; i <= right; i++)
    a[i] = temp[i];
  return count;
}
int mergeSort(int a[], int temp[], int left, int right)
{
    int mid, count = 0;
    if(right > left)
    {
        mid = right+left/2;
        count = mergeSort(a, temp, left, mid);
        count += mergeSort(a, temp, mid+1, right);
        count += merge(a, temp, left, mid, right);
    }
    return count;
}
int main()
{
    int a[] = {1, 20, 6, 4, 5};
    int n = sizeof(a)/sizeof(a[0]);
    int *temp = (int *)malloc(sizeof(int) * n);
    cout<<"Inversion Count: "<<mergeSort(a, temp, 0, n-1)<<"\n";
    return 1;
}
