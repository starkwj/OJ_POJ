/**
 * POJ1789 Truck History
 * 给定一系列字符串，以字符差距作为两字符串的距离，求最小生成树
 * prim
 */
#include <cstdio>
#include <cstring>
using namespace std;

#define INF 0x1fffffff

char code[2000][8];
int edge[2000][2000];
int dist[2000];
bool visited[2000];

int calcdist(char *a, char *b)
{
    int cnt = 0;
    for (int i = 0; i < 7; i++)
    {
        if (a[i] != b[i])
            cnt++;
    }
    return cnt;
}

int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%s", code[i]);
        }
        for (int i = 0; i < n; i++)
        {
            edge[i][i] = 0;
            dist[i] = INF;
            for (int j = i + 1; j < n; j++)
            {
                edge[i][j] = edge[j][i] = calcdist(code[i], code[j]);
            }
        }
        memset(visited, false, sizeof(visited));
        dist[0] = 0;
        int sum = 0;
        int cur = 0;
        visited[0] = true;
        for (int i = 0; i < n - 1; i++)
        {
            int m = INF;
            int next = n;
            for (int j = 0; j < n; j++)
            {
                if (visited[j] || j == cur)
                    continue;
                dist[j] = dist[j] < edge[cur][j] ? dist[j] : edge[cur][j];
                if (dist[j] < m)
                {
                    m = dist[j];
                    next = j;
                }
            }
            visited[next] = true;
            cur = next;
            sum += m;
        }
        printf("The highest possible quality is 1/%d.\n", sum);
    }
    return 0;
}
