#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define N 1100

using namespace std;

/**
输出某个数组的全排列结果
*/

int a[N];
int b[N];
int vis[N];
int n;
void dfs(int x)
{
    if(x >= n)
    {
        for(int i = 0;i < n; i++)
        {
            printf("%d ", b[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 0;i < n; i++)
    {
        if(vis[i] == 0)
        {
            vis[i] = 1;
            b[x] = a[i];
            dfs(x+1);
            vis[i] = 0;
        }
    }
}

int main()
{

    while(~scanf("%d", &n))
    {
        if(n == 0) break;

        memset(vis, 0, sizeof(vis));
        for(int i = 0;i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        dfs(0);
    }

    return 0;
}
