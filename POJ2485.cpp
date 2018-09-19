/**
 * POJ2485 Highways
 * 求最小生成树的最长边
 */
#include <cstdio>
#include <cstring>
using namespace std;

#define INF 0x1fffffff

int edge[500][500];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int dist[n];
        for (int i = 0; i < n; i++)
        {
            dist[i] = INF;
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &edge[i][j]);
            }
        }

        int ans = 0;
        bool visited[n];
        memset(visited, false, sizeof(visited));
        int cur = 0;
        visited[0] = true;
        dist[0] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int mindist = INF, minnode;
            for (int j = 0; j < n; j++)
            {
                if (!visited[j])
                {
                    if (dist[j] > edge[cur][j])
                        dist[j] = edge[cur][j];
                    if (dist[j] < mindist)
                    {
                        mindist = dist[j];
                        minnode = j;
                    }
                }
            }
            if (ans < mindist)
                ans = mindist;
            cur = minnode;
            visited[cur] = true;
        }
        printf("%d\n", ans);

    }
    return 0;
}
