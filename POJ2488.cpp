/**
 * POJ2488 A Knight's Journey
 * 棋盘，走"日"字，遍历完整个棋盘，按字典序输出第一条路径或不可能
 * dfs
 */
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

bool visited[8][8];
struct point {
    int x, y;
};
vector<point> vec;
int p, q;

int dir[8][2] = {
    -2, -1,
    -2, 1,
    -1, -2,
    -1, 2,
    1, -2,
    1, 2,
    2, -1,
    2, 1
};

bool dfs(int x, int y, int k)
{
    if (k == p * q)
        return true;

    visited[x][y] = true;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx >= 0 && nx < q && ny >= 0 && ny < p && !visited[nx][ny])
        {
            if (dfs(nx, ny, k + 1))
            {
                vec.push_back({nx, ny});
                return true;
            }
        }
    }
    visited[x][y] = false;
    return false;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &p, &q);
        memset(visited, false, sizeof(visited));
        vec.clear();
        printf("Scenario #%d:\n", i);
        if (dfs(0, 0, 1))
        {
            vec.push_back({0, 0});
            for (int j = vec.size() - 1; j >= 0; j--)
                printf("%c%d", 'A' + vec[j].x, vec[j].y + 1);
            printf("\n\n");
        }
        else
            printf("impossible\n\n");
    }

    return 0;
}
