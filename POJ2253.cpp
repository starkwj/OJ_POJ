/**
 * POJ2253 Frogger
 * 给定一系列坐标，求从起点到终点的路径中，最小的最大边权
 * 基于优先队列的dijkstra算法
 */
#include <stdio.h>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

#define INF 0x1fffffff

int x[200];
int y[200];
int dist2[200];
bool visited[200];

struct status {
    int index;
    int dis2;
    bool operator>(const status &b) const
    {
        return dis2 > b.dis2;
    }
};

int main()
{
    int n;
    int cnt = 0;
    while (scanf("%d", &n) && n)
    {
        cnt++;

        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &x[i], &y[i]);
            dist2[i] = INF;
        }
        dist2[0] = 0;
        memset(visited, false, sizeof(visited));
        priority_queue<status, vector<status>, greater<status> > q;
        q.push({0, 0});
        while (!q.empty())
        {
            int i = q.top().index;
            int d2 = q.top().dis2;
            q.pop();
            visited[i] = true;
            if (d2 > dist2[i])
                continue;
            for (int j = 0; j < n; j++)
            {
                if (visited[j])
                    continue;
                int tmp2 = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                int t = max(dist2[i], tmp2);
                if (dist2[j] > t)
                {
                    dist2[j] = t;
                    q.push({j, t});
                }
            }
        }
        double dis = sqrt(double(dist2[1]));

        printf("Scenario #%d\nFrog Distance = %.3f\n\n", cnt, dis);
    }

    return 0;
}

