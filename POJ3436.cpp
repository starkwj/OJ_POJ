/**
 * POJ3436 ACM Computer Factory
 * 最大流
 * n个机器，对输入、输出有要求，一个机器的输出满足另一个的输入要求时，建立一条边
 * 由于每个机器有容量限制，故double每个机器节点，一个入，一个出，入、出两节点之间的容量为机器的容量
 * 需要输出网络流的数量以及边的流量，遍历出点到入点的网络流（正向边为剩余容量，反向边为流量）
 * Edmond-Karp算法计算最大流
 */
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define INF 0x1fffffff

int p, n;
int s, t;   // 源点、汇点

int capacity[102][102];
int flow[102];
int pre[102];

int in[51][10];
int out[51][10];

int resin[2500];
int resout[2500];
int resflow[2500];

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

    cin >> p >> n;
    s = 0;
    t = (n << 1) + 1;
    memset(capacity, 0, sizeof(capacity));

    for (int i = 1; i <= n; i++)
    {
        int q;
        cin >> q;
        capacity[i][i + n] = q;
        bool flag = true;
        for (int j = 0; j < p; j++)
        {
            cin >> in[i][j];
            if (in[i][j] == 1)
                flag = false;
        }
        if (flag)
            capacity[s][i] = INF;   // 汇入点

        flag = true;
        for (int j = 0; j < p; j++)
        {
            cin >> out[i][j];
            if (!out[i][j])
                flag = false;
        }
        if (flag)
            capacity[i + n][t] = INF;   // 出点
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            bool flag = true;
            for (int k = 0; k < p; k++)
            {
                if (in[j][k] != 2 && out[i][k] != in[j][k])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                capacity[i + n][j] = INF;   // 输入、输出符合要求的节点之间建边
            }
        }
    }

    cout << maxFlow(s, t);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j && capacity[j][i + n] > 0)
            {
                resin[cnt] = i;
                resout[cnt] = j;
                resflow[cnt++] = capacity[j][i + n];
            }
        }
    }
    cout << " " << cnt << endl;
    for (int i = 0; i < cnt; i++)
    {
        cout << resin[i] << " " << resout[i] << " " << resflow[i] << endl;
    }

    return 0;
}
