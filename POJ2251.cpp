/**
 * POJ2251 Dungeon Master
 * ÈýÎ¬ÃÔ¹¬×î¶ÌÂ·¾¶
 * bfs
 */
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int n, k;
char maze[30][30][30];
bool visited[30][30][30];
int l, r, c;
int sz, sx, sy;
struct point {
    int z, x, y, t;
};

int dir[6][3] = {
    0, -1, 0,
    0, 1, 0,
    0, 0, -1,
    0, 0, 1,
    -1, 0, 0,
    1, 0, 0
};

int bfs()
{
    memset(visited, false, sizeof(visited));
    queue<point> q;
    visited[sz][sx][sy] = true;
    q.push({sz, sx, sy, 0});
    while (!q.empty())
    {
        int z = q.front().z;
        int x = q.front().x;
        int y = q.front().y;
        int t = q.front().t;
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nz = z + dir[i][0];
            int nx = x + dir[i][1];
            int ny = y + dir[i][2];
            if (nz >= 0 && nz < l && nx >= 0 && nx < r && ny >= 0 && ny < c
                && maze[nz][nx][ny] != '#' && !visited[nz][nx][ny])
            {
                if (maze[nz][nx][ny] == 'E')
                    return t + 1;
                visited[nz][nx][ny] = true;
                q.push({nz, nx, ny, t + 1});
            }
        }
    }
    return -1;
}

int main()
{
    while (scanf("%d %d %d", &l, &r, &c) != EOF && l)
    {
        char str[20];
        for (int i = 0; i < l; i++)
        {
            gets(str);
            for (int j = 0; j < r; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    maze[i][j][k] = getchar();
                    if (maze[i][j][k] == 'S')
                    {
                        sz = i, sx = j, sy = k;
                    }
                }
                gets(str);
            }
        }
        int ans = bfs();
        if (ans == -1)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n", ans);
    }

    return 0;
}
