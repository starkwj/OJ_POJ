/**
 * POJ2151 Check the difficulty of problems
 * ��̬�滮 ����dp
 * dp[i][j][k]��ʾ��i��������ǰj�����ж���k����ĸ���
 * �����ж��鶼��������1�⣬�ҵ�һ������������n�����
 *   = ���ж�����������һ��ĸ��� - ���ж���������������[1, n-1]�ĸ���
 */
#include <stdio.h>
#include <string.h>
using namespace std;

double dp[1000][31][31];
double sum[1000][31];

int main()
{
    int m, t, n;
    while (scanf("%d %d %d", &m, &t, &n) != EOF && m)
    {
        memset(dp, 0, sizeof(dp));
        memset(sum, 0, sizeof(sum));
        double p;
        for (int i = 0; i < t; i++)
        {
            dp[i][0][0] = 1.0;
            for (int j = 1; j <= m; j++)
            {
                scanf("%lf", &p);
                dp[i][j][0] = dp[i][j - 1][0] * (1.0 - p);
                for (int k = 1; k <= j; k++)
                {
                    dp[i][j][k] = dp[i][j - 1][k - 1] * p + dp[i][j - 1][k] * (1.0 - p);
                }
            }
            sum[i][0] = dp[i][m][0];
            for (int j = 1; j <= m; j++)
                sum[i][j] = sum[i][j - 1] + dp[i][m][j];
        }

        double p1 = 1.0;
        double p2 = 1.0;
        for (int i = 0; i < t; i++)
        {
            p1 *= (1.0 - sum[i][0]);
            p2 *= (sum[i][n - 1] - sum[i][0]);
        }
        printf("%.3f\n", p1 - p2);
    }
    return 0;
}

