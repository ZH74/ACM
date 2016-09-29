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
int n;
void mswap(int i, int j)
{
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}
int partion(int * a, int left, int right)
{
    int i = left;
    int j = right;
    int key = a[left];
    while(1)
    {
        while(i < n-1 && a[++i] < key);
        while(a[--j] > key);
        if(i < j)
        {
            mswap(i, j);
        }
        else
        {
            break;
        }
    }
    a[left] = a[j];
    a[j] = key;
    return j;
}

void myqsort(int * a, int left, int right)
{
    if(left < right)
    {
        int part = partion(a, left, right);
        //printf("%d\n", part);
        myqsort(a, left, part);
        myqsort(a, part+1, right);

    }
}
int main()
{
    scanf("%d", &n);
    if(n < 1 || n >= 100)
    {
        return 0;
    }

    memset(arr, 0, sizeof(arr));

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    myqsort(arr, 0, n);

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
