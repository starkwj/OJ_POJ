/**
 * POJ3278 Catch That Cow
 * 一维最短路径，从x每步只能走到x-1、x+1、2*x
 * bfs
 */
#include <stdio.h>
#include <queue>
using namespace std;

int mark[100001];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    queue<int> q;
    q.push(n);
    mark[n] = 1;
    while (!q.empty() && mark[k] == 0)
    {
        int cur = q.front();
        q.pop();
        if (cur - 1 >= 0 && mark[cur - 1] == 0)
        {
            q.push(cur - 1);
            mark[cur - 1] = mark[cur] + 1;
        }
        if (cur + 1 <= 100000 && mark[cur + 1] == 0)
        {
            q.push(cur + 1);
            mark[cur + 1] = mark[cur] + 1;
        }
        if (cur != 0)
        {
            int next = cur << 1;
            if (next <= 100000 && mark[next] == 0)
            {
                q.push(next);
                mark[next] = mark[cur] + 1;
            }
        }
    }
    printf("%d\n", mark[k] - 1);
    return 0;
}
