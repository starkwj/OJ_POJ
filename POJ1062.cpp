/**
 * POJ1062 昂贵的聘礼
 * 具有限制条件的最短路径
 * 要求所有路径中的点的等级差不能超过M，枚举所有的可行等级区间
 * 带优先队列的dijkstra算法
 */
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define INF 0x1fffffff

struct G {
    int price;
    int level;
};
G goods[101];

int edge[101][101];
int dist[101];
struct status {
    int index;
    int dis;
    bool operator>(const status &b) const
    {
        return dis > b.dis;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            edge[i][j] = INF;
        }
        edge[i][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> goods[i].price >> goods[i].level >> x;
        while (x--)
        {
            int t, v;
            cin >> t >> v;
            edge[i][t] = v;
        }
    }

    int klevel = goods[1].level;
    int left = klevel - m;
    int right = klevel;
    int ans = INF;
    while (right <= klevel + m)
    {
        for (int i = 2; i <= n; i++)
        {
            dist[i] = INF;
        }
        dist[1] = 0;
        priority_queue<status, vector<status>, greater<status> > q;
        q.push({1, 0});
        while (!q.empty())
        {
            int k = q.top().index;
            int d = q.top().dis;
            q.pop();
            if (d > dist[k])
                continue;

            for (int i = 1; i <= n; i++)
            {
                if (i == k || goods[i].level < left || goods[i].level > right)
                    continue;
                if (dist[i] > dist[k] + edge[k][i])
                {
                    dist[i] = dist[k] + edge[k][i];
                    q.push({i, dist[i]});
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            ans = min(ans, dist[i] + goods[i].price);
        }
        left++;
        right++;
    }
    cout << ans << endl;

    return 0;
}
