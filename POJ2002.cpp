/**
 * POJ2002 Squares
 * ����n�����꣬���������ж�����4���������������
 * hash
 * ������󣬶����������㣬�����Ӧ���������㣬ֻ����һ������ÿ�����λᱻ��2�Σ�������2
 * ������������Ҫ����������
 */
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

#define MOD 1007

struct point {
    int x, y;
    int next;
};

int cur = 0;
point node[1000];
int hashTable[MOD];

bool sortcmp(const point &a, const point &b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int getHash(int x, int y)
{
    int h = x << 4 + y;
    return (h & 0x7fffffff) % MOD;
}

bool cmp(int ax, int ay, int bx, int by)
{
    return ax == bx && ay == by;
}

void insertHash(int x, int y)
{
    int h = getHash(x, y);
    node[cur].x = x;
    node[cur].y = y;
    node[cur].next = hashTable[h];
    hashTable[h] = cur++;
}

bool exist(int x, int y)
{
    int h = getHash(x, y);
    int i = hashTable[h];
    while (i != -1)
    {
        if (cmp(node[i].x, node[i].y, x, y))
            return true;
        i = node[i].next;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n)
    {
        cur = 0;
        memset(hashTable, -1, sizeof(hashTable));
        int x, y;
        for (int i = 0; i < n; i++)
        {
            cin >> node[i].x >> node[i].y;
        }
        sort(node, node + n, sortcmp);
        for (int i = 0; i < n; i++)
            insertHash(node[i].x, node[i].y);

        int ans = 0;
        for (int i = 0; i < cur; i++)
        {
            for (int j = i + 1; j < cur; j++)
            {
                int ax = node[i].x, ay = node[i].y;
                int bx = node[j].x, by = node[j].y;
                int dx = ax - bx, dy = ay - by;
                if (exist(ax + dy, ay - dx) && exist(bx + dy, by - dx))
                {
                    ans++;
                    printf("%d (%d,%d) (%d,%d) (%d,%d) (%d,%d)\n", ans, ax, ay, bx, by, ax + dy, ay - dx, bx + dy, by - dx);
                }
            }
        }
        cout << (ans >> 1) << endl;
    }
    return 0;
}
