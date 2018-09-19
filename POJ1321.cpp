/**
 * POJ1321 棋盘问题
 * 有下棋位置限制的n皇后问题
 * dfs回溯
 */
#include <stdio.h>

int n, k;
bool board[8][8];
bool usey[8];
int ans;

void dfs(int row, int cur)
{
    if (cur == 0)
    {
        ans++;
        return;
    }
    if (n - row < cur)
        return;
    for (int j = 0; j < n; j++)
    {
        if (board[row][j] && !usey[j])
        {
            usey[j] = true;
            dfs(row + 1, cur - 1);
            usey[j] = false;
        }
    }
    dfs(row + 1, cur);
}

int main()
{
    while (scanf("%d %d", &n, &k) != EOF && n != -1)
    {
        char str[20];
        for (int i = 0; i < n; i++)
        {
            gets(str);
            for (int j = 0; j < n; j++)
            {
                char c = getchar();
                board[i][j] = c == '#';
            }
        }
        ans = 0;
        dfs(0, k);
        printf("%d\n", ans);
    }

    return 0;
}
