/**
 * POJ1837 Balance
 * 天平平衡 背包问题
 */
#include <stdio.h>
#include <string.h>

#define OFFSET 7500

int dp[21][15001];
int pos[21];
int weight[21];

int main()
{
    int c, g;
    scanf("%d %d", &c, &g);
    for (int i = 1; i <= c; i++)
        scanf("%d", &pos[i]);
    for (int i = 1; i <= g; i++)
        scanf("%d", &weight[i]);
    dp[0][OFFSET] = 1;
    for (int i = 1; i <= g; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            int w = pos[j] * weight[i];
            int left, right;
            if (w < 0)
                left = 0, right = 15000 + w;
            else
                left = w, right = 15000;
            for (int k = left; k <= right; k++)
            {
                if (dp[i - 1][k - w] != 0)
                    dp[i][k] += dp[i - 1][k - w];
            }
        }
    }
    printf("%d\n", dp[g][OFFSET]);
    return 0;
}
