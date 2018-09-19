/**
 * POJ1426 Find The Multiple
 * 给整数n，找n的倍数，使得该数只含有0和1
 * bfs，从1开始添0、1
 */
#include <stdio.h>

long long Q[10000000];

int main()
{
    int n;
    while (scanf("%d", &n) != EOF && n)
    {
        Q[0] = 1;
        int cur = 0;
        int sz = 1;
        while (1)
        {
            long long k = Q[cur++];
            if (k % n == 0)
            {
                printf("%lld\n", k);
                break;
            }
            Q[sz++] = k * 10;
            Q[sz++] = k * 10 + 1;
        }
    }
    return 0;
}
