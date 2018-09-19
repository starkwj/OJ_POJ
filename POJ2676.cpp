/**
 * POJ2676 Sudoku
 * Êý¶À dfs
 */
#include <stdio.h>
#include <vector>
using namespace std;
int grid[9][9];
struct point {
    int x, y;
};

vector<point> vec;

bool check(int x, int y, int k)
{
    for (int i = 0; i < 9; i++)
    {
        if (grid[i][y] == k)
            return false;
        if (grid[x][i] == k)
            return false;
    }
    int m = (x / 3) * 3;
    int n = (y / 3) * 3;
    for (int i = m; i < m + 3; i++)
    {
        for (int j = n; j < n + 3; j++)
        {
            if (grid[i][j] == k)
                return false;
        }
    }
    return true;
}

bool dfs(int index)
{

    if (index == vec.size())
    {
        return true;
    }
    int x = vec[index].x;
    int y = vec[index].y;
    for (int i = 1; i <= 9; i++)
    {
        if (check(x, y, i))
        {
            grid[x][y] = i;
            if (dfs(index + 1))
                return true;
            grid[x][y] = 0;
        }
    }
    return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        vec.clear();
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                scanf("%1d", &grid[i][j]);
                if (grid[i][j] == 0)
                    vec.push_back({i, j});
            }
        }
        dfs(0);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                printf("%d", grid[i][j]);
            printf("\n");
        }
    }
    return 0;
}
