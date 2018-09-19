/**
 * POJ3274 Gold Balanced Lineup
 * 给n个k位的二进制数
 * 寻找最大的跨度i~j，使得这些数中，每一位出现的次数相同
 * 统计各位的累积和，如3位数，i:(a,b,c)，j:(d,e,f)，则(a+x,b+x,c+x) = (d,e,f)
 * 同时减去同一位(a-c,b-c,0) = (d-f,e-f,0)，故寻找跨度最大的相同的两组数
 * 使用hash加速查找
 */
#include <stdio.h>
#include <string.h>

int n, k;
int num[100001][30];
int ans = 0;

struct Node {
    int index;
    int next;
};

int cur = 0;
Node node[100001];
int hashTable[100007];

bool cmp(int a, int b)
{
    for (int i = 0; i < k; i++)
        if (num[a][i] != num[b][i])
            return false;
    return true;
}

int getHash(int x)
{
    int h = 0;
    for (int i = 0; i < k; i++)
    {
        h += num[x][i] * (i + 1);
    }
    return (h & 0x7fffffff) % 100007;
}

void insertHash(int x)
{
    int h = getHash(x);
    int i = hashTable[h];
    while (i != -1)
    {
        if (cmp(node[i].index, x))
        {
            if (ans < x - node[i].index)
                ans = x - node[i].index;
            return;
        }
        i = node[i].next;
    }
    node[cur].next = hashTable[h];
    node[cur].index = x;
    hashTable[h] = cur++;
}

int main()
{
    scanf("%d %d", &n, &k);
    memset(num[0], 0, sizeof(num[0]));
    memset(hashTable, -1, sizeof(hashTable));
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < k; j++)
            num[i][j] = (x >> j) & 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++)
            num[i][j] += num[i - 1][j];

    for (int i = 1; i <= n; i++)
        for (int j = k - 1; j >= 0; j--)
            num[i][j] -= num[i][0];

    for (int i = 0; i <= n; i++)
    {
        insertHash(i);
    }
    printf("%d\n", ans);

    return 0;
}

