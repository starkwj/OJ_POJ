/**
 * POJ2531 Network Saboteur
 * ���㼯��Ϊ�����֣�ʹ��������֮��ı�Ȩ֮�����
 * dfs Ĭ�ϵ�һ������A���֡���������i���㣬����i��A���֣�����Ȩֵ�ͣ���ȥi��A���ֵ�Ȩ�ͣ�����i��B���ֵ�Ȩ��
 * ��Ȩ�ͱ�������dfs
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
