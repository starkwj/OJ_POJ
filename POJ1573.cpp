/**
 * POJ1573 Robot Motion
 * 模拟
 * 顺着地图走，计算走出地图的步数或走入循环的步数
 */
#include <iostream>
#include <cstring>
using namespace std;

char grid[10][10];
int mark[10][10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, n, k;
    while (cin >> m >> n >> k)
    {
        if (k == 0)
            break;
        memset(mark, false, sizeof(mark));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }
        int x = 0, y = k - 1;
        int cnt = 0;
        while (true)
        {
            if (x < 0 || x >= m || y < 0 || y >= n)
            {
                cout << cnt << " step(s) to exit" << endl;
                break;
            }
            cnt++;
            if (mark[x][y])
            {
                cout << (mark[x][y] - 1) << " step(s) before a loop of " << (cnt - mark[x][y]) << " step(s)" << endl;
                break;
            }
            mark[x][y] = cnt;
            if (grid[x][y] == 'N')
                x--;
            else if (grid[x][y] == 'E')
                y++;
            else if (grid[x][y] == 'S')
                x++;
            else
                y--;
        }
    }
    return 0;
}
