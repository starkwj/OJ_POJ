/**
 * POJ2632 Crashing Robots
 * Ä£Äâ
 */
#include <iostream>
#include <string.h>
using namespace std;

int grid[101][101];
int dir[4][2] = {
    0, 1,
    1, 0,
    0, -1,
    -1, 0
};  // N E S W

struct R {
    int x, y;
    int dir;
};

R robot[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;
    while (k--)
    {
        int a, b, n, m;
        cin >> a >> b >> n >> m;
        memset(grid, 0, sizeof(grid));
        for (int i = 1; i <= n; i++)
        {
            char c;
            cin >> robot[i].x >> robot[i].y >> c;
            grid[robot[i].x][robot[i].y]= i;
            if (c == 'N')
                robot[i].dir = 0;
            else if (c == 'E')
                robot[i].dir = 1;
            else if (c == 'S')
                robot[i].dir = 2;
            else
                robot[i].dir = 3;
        }
        bool craflag = false;
        while (m--)
        {
            int index, t;
            char c;
            cin >> index >> c >> t;
            if (craflag)
                continue;
            if (c == 'L')
            {
                t = t % 4;
                robot[index].dir = (robot[index].dir + 4 - t) % 4;
            }
            else if (c == 'R')
            {
                robot[index].dir = (robot[index].dir + t) % 4;
            }
            else
            {
                int nx = robot[index].x;
                int ny = robot[index].y;
                int d = robot[index].dir;
                for (int i = 0; i < t; i++)
                {
                    nx += dir[d][0];
                    ny += dir[d][1];
                    if (nx < 1 || nx > a || ny < 1 || ny > b)
                    {
                        craflag = true;
                        cout << "Robot " << index << " crashes into the wall" << endl;
                        break;
                    }
                    if (grid[nx][ny] != 0)
                    {
                        craflag = true;
                        cout << "Robot " << index << " crashes into robot " << grid[nx][ny] << endl;
                        break;
                    }
                }
                grid[robot[index].x][robot[index].y] = 0;
                grid[nx][ny] = index;
                robot[index].x = nx;
                robot[index].y = ny;
            }
        }
        if (!craflag)
            cout << "OK" << endl;
    }

    return 0;
}
