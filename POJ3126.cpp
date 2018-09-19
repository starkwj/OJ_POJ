/**
 * POJ3126 Prime Path
 * 给两个4位数s、e，从s到e每次改变一个数字，且每个数都是质数，求最短改变次数
 * bfs
 */
#include <stdio.h>
#include <string.h>
bool prime[10000];
bool visited[10000];
struct node {
    int x;
    int t;
};
node Q[10000];

int main()
{
    memset(prime, true, sizeof(prime));
    prime[2] = true;
    for (int i = 2; i < 10000; i++)
    {
        if (prime[i] == false)
            continue;
        for (int j = i * i; j < 10000; j += i)
        {
            prime[j] = false;
        }
    }

    int n;
    scanf("%d", &n);
    int s, e;
    while (n--)
    {
        memset(visited, 0, sizeof(visited));
        scanf("%d %d", &s, &e);
        int cur = 0;
        Q[cur] = {s, 0};
        int sz = 1;
        visited[s] = true;
        while (cur < sz)
        {
            int x = Q[cur].x;
            int t = Q[cur++].t;
            if (x == e)
            {
                printf("%d\n", t);
                break;
            }

            for (int i = 1; i <= 1000; i *= 10)
            {
                int tmp = x - x % (i * 10) + x % i;
                for (int j = 0; j < 10; j++)
                {
                    if (i == 1000 && j == 0)
                        continue;
                    int nx = tmp + i * j;
                    if (prime[nx] && !visited[nx])
                    {
                        visited[nx] = true;
                        Q[sz++] = {nx, t + 1};
                    }
                }
            }
        }
        if (!visited[e])
            printf("Impossible\n");
    }
    return 0;
}
