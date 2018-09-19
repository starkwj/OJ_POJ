/**
 * POJ2513 Colored Sticks
 * 每根木棍两端都有颜色，给一系列木棍，判断这些木棍能否连起来，连接端点颜色相同
 * 字典树 + 并查集
 */
#include <stdio.h>
#include <string.h>

struct trie {
    bool flag;
    int id;
    trie *next[26];
    trie()
    {
        flag = false;
        id = 0;
        memset(next, NULL, sizeof(next));
    }
};
trie trieroot;

int indegree[500001];
int cur = 0;

// 查询、添加字典树
int hashTrie(char *s)
{
    trie *p = &trieroot;
    while (*s)
    {
        int i = *s - 'a';
        if (p->next[i] == NULL)
            p->next[i] = new trie();
        p = p->next[i];
        s++;
    }
    if (p->flag)
        return p->id;
    else
    {
        p->flag = true;
        p->id = ++cur;
        return p->id;
    }
}

// 并查集
int root[500001];
int findRoot(int x)
{
    if (root[x] == x)
        return x;
    else
    {
        int p = findRoot(root[x]);
        root[x] = p;
        return p;
    }
}

void union_root(int x, int y)
{
    x = findRoot(x);
    y = findRoot(y);
    root[y] = x;
}

int main()
{
    for (int i = 0; i <= 500000; i++)
        root[i] = i;

    char a[11], b[11];
    while (scanf("%s %s", a, b) != EOF)
    {
        int i = hashTrie(a);
        int j = hashTrie(b);
        indegree[i]++;
        indegree[j]++;
        union_root(i, j);
    }
    if (cur == 0)
    {
        printf("Possible\n");
        return 0;
    }
    int cnt = 0;
    for (int i = 1; i <= cur; i++)
        cnt += indegree[i] & 1;
    if (cnt == 1 || cnt > 2)
    {
        printf("Impossible\n");
        return 0;
    }

    int s = findRoot(1);
    for (int i = 2; i <= cur; i++)
    {
        if (findRoot(i) != s)
        {
            printf("Impossible\n");
            return 0;
        }
    }
    printf("Possible\n");
    return 0;
}
