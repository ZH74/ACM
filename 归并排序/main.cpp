#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define N 100
using namespace std;

int arr[N];
int b[N];

void mergeArr(int * a, int left, int mid, int right)
{
    //printf("hello\n");
    int i = left;
    int j = mid+1;
    int k = left;
    while(i <= mid && j <= right)
    {
        if(a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }

    while(i <= mid)
    {
        b[k++] = a[i++];
    }
    while(j <= right)
    {
        b[k++] = a[j++];
    }

    for(int kk = left; kk < k; kk++)
    {
        arr[kk] = b[kk];
    }
}
void mergeSort(int * a, int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) >> 1;
        mergeSort(a, left, mid);
        mergeSort(a, mid+1, right);
        mergeArr(a, left, mid, right);
    }
}
int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n-1);

    for(int i = 0; i < n; i++)
    {
        if(i == n-1)
        {
            printf("%d\n", arr[i]);
        }
        else
        {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}
