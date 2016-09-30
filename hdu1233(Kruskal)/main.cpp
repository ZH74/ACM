#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#define N 110

using namespace std;

/**
���鼯������·�����  Kruskal �㷨
*/

struct Edge
{
    //�ֱ���������ߵ���߽ڵ㡢�ұ߽ڵ�ͱߵĳ���
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
    int n; //���� n ���ڵ�
    int m; //���� m ����
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
