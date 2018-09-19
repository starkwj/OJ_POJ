/**
 * POJ3026 Borg Maze
 * 给迷宫地图，求其中节点的最小生成树
 * 先根据地图建立节点间邻接矩阵，然后使用prim
 */
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define INF 0x1fffffff

char graph[50][50];
int edge[101][101];
int dist[101];
bool visited[50][50];

int num;
int locx[101];
int locy[101];
int maxx, maxy;

int dir[4][2] = {
    -1, 0,
    1, 0,
    0, -1,
    0, 1
};

struct status {
    int x, y;
    int t;
};

int getIndex(int x, int y)
{
    for (int i = 0; i < num; i++)
    {
        if (x == locx[i] && y == locy[i])
            return i;
    }
    return -1;
}

void bfs(int src)
{
    memset(visited, false, sizeof(visited));
    queue<status> q;
    q.push({locx[src], locy[src], 0});
    visited[locx[src]][locy[src]] = true;
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int t = q.front().t;
        q.pop();
        if (graph[x][y] == 'A' || graph[x][y] == 'S')
        {
            int index = getIndex(x, y);
            if (index >= src)
                edge[src][index] = edge[index][src] = t;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx < 0 || nx >= maxx || ny < 0 || ny >= maxy || graph[nx][ny] == '#')
                continue;
            if (!visited[nx][ny])
            {
                q.push({nx, ny, t + 1});
                visited[nx][ny] = true;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {

        scanf("%d %d", &maxy, &maxx);
        gets(graph[0]);
        for (int i = 0; i < maxx; i++)
        {
            gets(graph[i]);
        }
        num = 0;
        for (int i = 0; i < maxx; i++)
        {
            for (int j = 0; j < maxy; j++)
            {
                if (graph[i][j] == 'A' || graph[i][j] == 'S')
                {
                    locx[num] = i;
                    locy[num++] = j;
                }
            }
        }
        for (int i = 0; i < num; i++)
        {
            bfs(i);
            dist[i] = INF;
        }



        int ans = 0;
        bool used[num];
        memset(used, false, sizeof(used));
        int cur = 0;
        used[0] = true;
        dist[0] = 0;
        for (int i = 0; i < num - 1; i++)
        {
            int mindist = INF, minnode;
            for (int j = 0; j < num; j++)
            {
                if (!used[j])
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
            used[cur] = true;
        }
        printf("%d\n", ans);

    }
    return 0;
}
