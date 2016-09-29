#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define N 100

using namespace std;
/**
������Ҫ�� r l n �ֱ���� �� �� ����ֵ
������������������ֵ ����������һ������ֵ
0 ����ͨ·  1 �����ϰ�
��ʼ�� (0,0) �յ� (0,l-1)
*/

int a[N][N];
int vis[N][N];
int fa[N*N];

int r,l,n;
int flag;
int last;

int path[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

int ok(int x, int y, int s)
{
    if(x >= r || x < 0 || y >= l || y < 0) return 0;
    if(a[x][y] == 1 || vis[x][y] == 1 || s < 0) return 0;
    return 1;
}
void dfs(int x, int y, int s)
{
    if(flag == 1) return;
    if(x == 0 && y == l-1 && s >= 0)
    {
        flag = 1;
        last = x*l+y;
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        int nx = x + path[i][0];
        int ny = y + path[i][1];

        if(ok(nx, ny, s))
        {
            fa[nx*l+ny] = x*l+y;
            vis[nx][ny] = 1;
            if(nx != x)
            {
                dfs(nx, ny, s-3);
            }
            if(ny != y)
            {
                dfs(nx, ny, s-1);
            }
            vis[nx][ny] = 0;
        }
    }
}

int main()
{
    while(~scanf("%d %d %d", &r, &l, &n))
    {
        if(r == 0) break;

        memset(vis, 0, sizeof(vis));
        memset(fa, -1, sizeof(fa));

        for(int i = 0;i < r; i++)
        {
            for(int j = 0;j < l; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }

        flag = 0;
        last = -1;
        vis[0][0] = 1;
        dfs(0, 0, n);

        if(flag == 1)
        {
            while(last != -1)
            {
                printf("(%d, %d)\n", last/l, last%l);
                last = fa[last];
            }
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
