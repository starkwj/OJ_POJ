/**
 * POJ2240 Arbitrage
 * 判断能否通过换汇增值，即找出正权重的环，最短距离由加法改为乘法
 * spfa判环
 * 节点以字符串形式给出，用string到int的映射存储
 */
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
using namespace std;

#define INF 0x1fffffff

struct E {
    int next;
    double rate;
};
vector<E> edge[30];
double dist[30];
bool inqueue[30];
int indegree[30];
int sum[30];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int cnt = 0;
    while (cin >> n && n)
    {
        cnt++;
        memset(indegree, 0, sizeof(indegree));
        map<string, int> no;

        for (int i = 0; i < n; i++)
        {
            string t;
            cin >> t;
            no[t] = i;
            edge[i].clear();
        }

        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            string a, b;
            double r;
            cin >> a >> r >> b;
            edge[no[a]].push_back({no[b], r});
            indegree[no[b]]++;
        }

        bool flag = false;
        for (int i = 0; i < n && !flag; i++)
        {
            memset(dist, 0, sizeof(dist));
            dist[i] = 1;
            memset(inqueue, false, sizeof(inqueue));
            memset(sum, 0, sizeof(sum));
            queue<int> q;
            q.push(i);
            inqueue[i] = true;
            sum[i]++;
            while (!q.empty() && !flag)
            {
                int cur = q.front();
                q.pop();
                inqueue[cur] = false;
                for (int j = 0; j < edge[cur].size(); j++)
                {
                    int next = edge[cur][j].next;
                    double tmp = dist[cur] * edge[cur][j].rate;
                    if (tmp > dist[next])
                    {
                        dist[next] = tmp;
                        if (++sum[next] > indegree[next])
                        {
                            flag = true;
                            break;
                        }
                        if (!inqueue[next])
                        {
                            q.push(next);
                            inqueue[next] = true;
                        }
                    }
                }
            }

        }


        if (flag)
            cout << "Case " << cnt << ": Yes" << endl;
        else
            cout << "Case " << cnt << ": No" << endl;
    }

    return 0;
}
