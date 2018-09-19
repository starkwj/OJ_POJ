/**
 * POJ3009 Curling 2.0
 * dfs
 */
#include <stdio.h>

int grid[20][20];
int h, w;
int sx, sy;
int minstep;

int dir[4][2] = {
    0, -1,  // left
    -1, 0,  // up
    0, 1,   // right
    1, 0    // down
};

void dfs(int x, int y, int step)
{
    if (step > 10 || step >= minstep)
        return;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny] != 1)
        {
            while (nx >= 0 && nx < h && ny >= 0 && ny < w)
            {
                if (grid[nx][ny] == 1)
                {
                    grid[nx][ny] = 0;
                    dfs(nx - dir[i][0], ny - dir[i][1], step + 1);
                    grid[nx][ny] = 1;
                    break;
                }
                else if (grid[nx][ny] == 3)
                {
                    minstep = minstep > step ? step : minstep;
                    return;
                }
                nx += dir[i][0];
                ny += dir[i][1];
            }
        }
    }
}

int main()
{
    while (scanf("%d %d", &w, &h) && h)
    {
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                scanf("%d", &grid[i][j]);
                if (grid[i][j] == 2)
                {
                    sx = i;
                    sy = j;
                }
            }
        }
        minstep = 11;
        dfs(sx, sy, 1);
        printf("%d\n", minstep > 10 ? -1 : minstep);
    }

    return 0;
}
