/**
 * POJ1129 Channel Allocation
 * 图染色 dfs
 */

#include <stdio.h>
#include <string.h>

int n;
int cur;
int channel[26];
bool edge[26][26];

bool check(int index, int c)
{
    for (int i = 0; i < index; i++)
        if (edge[index][i] && channel[i] == c)
            return false;
    return true;
}

bool dfs(int index)
{
    if (cur == 4 || index == 26)    // 根据四色原理，最多4种颜色，达到4种直接剪枝返回
        return true;
    for (int i = 1; i <= 4; i++)
    {
        if (check(index, i))
        {
            channel[index] = i;
            if (i > cur)
                cur = i;
            if (dfs(index + 1))
                return true;
            channel[index] = 0;
        }
    }
    return false;
}

int main()
{
    while (scanf("%d", &n) != EOF && n)
    {
        memset(channel, 0, sizeof(channel));
        memset(edge, 0, sizeof(edge));
        cur = 0;
        for (int i = 0; i < n; i++)
        {
            char s[6];
            scanf("%s", s);
            int j = 2;
            while (s[j])
            {
                edge[i][s[j] - 'A'] = true;
                j++;
            }
        }
        dfs(0);
        printf("%d channel%s needed.\n", cur, cur > 1 ? "s" : "");
    }

    return 0;
}
