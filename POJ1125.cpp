/**
 * POJ1125 Stockbroker Grapevine
 * 找一个根节点，使得该节点到其他所有节点的最短路径的最大值最小，以及该值
 * floyd-warshall
 */
#include <iostream>
using namespace std;

#define INF 0x1fffffff

int graph[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n && n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                graph[i][j] = INF;
            graph[i][i] = 0;

            int x;
            cin >> x;
            while (x--)
            {
                int next, t;
                cin >> next >> t;
                graph[i][next] = t;
            }
        }
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
        int ans = INF, v = 0;
        for (int i = 1; i <= n; i++)
        {
            int tmp = 0;
            for (int j = 1; j <= n; j++)
                tmp = max(tmp, graph[i][j]);
            if (ans > tmp)
            {
                ans = tmp;
                v = i;
            }
        }
        if (ans == INF)
            cout << "disjoint" << endl;
        else
            cout << v << " " << ans << endl;
    }

    return 0;
}

