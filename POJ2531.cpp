/**
 * POJ2531 Network Saboteur
 * 将点集分为两部分，使得两部分之间的边权之和最大
 * dfs 默认第一个点在A部分。遍历到第i个点，若点i在A部分，更新权值和，减去i和A部分的权和，加上i和B部分的权和
 * 若权和变大，则继续dfs
 */
#include <stdio.h>
using namespace std;
int edge[20][20];
bool mark[20];
int n;
int ans = 0;

void dfs(int cur, int temp)
{
    mark[cur] = true;
    int t = temp;
    for (int i = 0; i < n; i++)
        if (mark[i])
            t -= edge[cur][i];
        else
            t += edge[cur][i];
    if (t > ans)
        ans = t;
    if (t > temp)
    {
        for (int j = cur + 1; j < n; j++)
        {
            dfs(j, t);
            mark[j] = false;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &edge[i][j]);
    dfs(0, 0);
    printf("%d\n", ans);
    return 0;
}
