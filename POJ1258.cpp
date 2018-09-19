/**
 * POJ1258 Agri-Net
 * 最小生成树
 * Prim
 */
#include <cstdio>
#include <cstring>
using namespace std;

#define INF 0x1fffffff

int edge[100][100];
int dist[100];

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
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
            ans += mindist;
            cur = minnode;
            visited[cur] = true;
        }
        printf("%d\n", ans);

    }
    return 0;
}
