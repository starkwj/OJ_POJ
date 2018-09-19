/**
 * POJ3414 Pots
 * µ¹Ë® bfs
 */
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

bool visited[101][101];
struct status {
    int x;
    int y;
    int t;
};

struct P {
    int px, py;
    int op;
    int num;
};
P pre[101][101];

void dfs(int x, int y)
{
    if (x == 0 && y == 0)
        return;
    dfs(pre[x][y].px, pre[x][y].py);
    if (pre[x][y].op == 0)
        printf("FILL(%d)\n", pre[x][y].num);
    else if (pre[x][y].op == 1)
        printf("DROP(%d)\n", pre[x][y].num);
    else
        printf("POUR(%d,%d)\n", pre[x][y].num, 3 - pre[x][y].num);
}

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    queue<status> q;
    q.push({0, 0, 0});
    visited[0][0] = true;
    int ans = -1;
    int ex, ey;
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int t = q.front().t;
        q.pop();
        if (x == c || y == c)
        {
            ans = t;
            ex = x;
            ey = y;
            break;
        }
        if (!visited[a][y])
        {
            pre[a][y] = {x, y, 0, 1};
            visited[a][y] = true;
            q.push({a, y, t + 1});
        }
        if (!visited[x][b])
        {
            pre[x][b] = {x, y, 0, 2};
            visited[x][b] = true;
            q.push({x, b, t + 1});
        }
        if (!visited[0][y])
        {
            pre[0][y] = {x, y, 1, 1};
            visited[0][y] = true;
            q.push({0, y, t + 1});
        }
        if (!visited[x][0])
        {
            pre[x][0] = {x, y, 1, 2};
            visited[x][0] = true;
            q.push({x, 0, t + 1});
        }
        int k = min(x, b - y);
        if (!visited[x - k][y + k])
        {
            pre[x - k][y + k] = {x, y, 2, 1};
            visited[x - k][y + k] = true;
            q.push({x - k, y + k, t + 1});
        }
        k = min(y, a - x);
        if (!visited[x + k][y - k])
        {
            pre[x + k][y - k] = {x, y, 2, 2};
            visited[x + k][y - k] = true;
            q.push({x + k, y - k, t + 1});
        }
    }

    if (ans == -1)
        printf("impossible\n");
    else
    {
        printf("%d\n", ans);
        dfs(ex, ey);
    }

    return 0;
}
