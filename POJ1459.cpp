/**
 * POJ1459 Power Network
 * 最大流
 * Edmond-Karp算法
 */
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define INF 0x1fffffff

int n, np, nc, m;
int s, t;   // 源点、汇点

int capacity[102][102];
int flow[102];
int pre[102];

int bfs(int s, int t)
{
    queue<int> q;
    memset(pre, -1, sizeof(pre));
    flow[s] = INF;
    q.push(s);
    while (!q.empty())
    {
        int index = q.front();
        q.pop();
        if (index == t)
            break;
        for (int i = 0; i <= t; i++)
        {
            if (i != s && capacity[index][i] > 0 && pre[i] == -1)
            {
                pre[i] = index;
                flow[i] = min(capacity[index][i], flow[index]);
                q.push(i);
            }
        }
    }
    if (pre[t] == -1)
        return -1;
    else
        return flow[t];
}

int maxFlow(int s, int t)
{
    int inc = 0;
    int sum = 0;
    while ((inc = bfs(s, t)) != -1)
    {
        int k = t;
        while (k != s)
        {
            int last = pre[k];
            capacity[last][k] -= inc;
            capacity[k][last] += inc;
            k = last;
        }
        sum += inc;
    }
    return sum;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n >> np >> nc >> m)
    {
        s = n;
        t = n + 1;
        memset(capacity, 0, sizeof(capacity));
        for (int i = 0; i < m; i++)
        {
            char c;
            int a, b, t;
            cin >> c >> a >> c >> b >> c >> t;
            capacity[a][b] = t;
        }
        for (int i = 0; i < np; i++)
        {
            char c;
            int u, z;
            cin >> c >> u >> c >> z;
            capacity[s][u] = z;
        }
        for (int i = 0; i < nc; i++)
        {
            char c;
            int u, z;
            cin >> c >> u >> c >> z;
            capacity[u][t] = z;
        }

        cout << maxFlow(s, t) << endl;
    }
    return 0;
}
