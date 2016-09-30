#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#define N 110

using namespace std;

/**
并查集求所有路径最短  Kruskal 算法
*/

struct Edge
{
    //分别代表这条边的左边节点、右边节点和边的长度
    int left;
    int right;
    int length;
};
Edge edge[N*(N-1)];

int fa[N];
int cmp(Edge e1, Edge e2)
{
    return e1.length < e2.length;
}

int get_par(int x)
{
    if(x != fa[x])
    {
        fa[x] = get_par(fa[x]);
    }
    return fa[x];
}

bool check(Edge e)
{
    int fleft = get_par(e.left);
    int fright = get_par(e.right);
    if(fleft != fright)
    {
        fa[fleft] = fright;
        return true;
    }
    return false;
}
int main()
{
    int n; //代表 n 个节点
    int m; //代表 m 个边
    while(~scanf("%d", &n))
    {
        if(n == 0) break;
        m = n*(n-1)/2;

        for(int i = 1; i <= n; i++)
        {
            fa[i] = i;
        }
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d %d", &edge[i].left, &edge[i].right, &edge[i].length);
        }

        sort(edge+1, edge+m+1, cmp);

        int ans = 0;
        for(int i = 1; i <= m; i++)
        {
            if(check(edge[i]))
            {
                ans += edge[i].length;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
