/**
 * POJ1094 Sorting It All Out
 * 给出字母的大小关系，判断是否能严格拓扑排序
 * 每给出一条大小关系，就在图中建立一条边，并重新计算所有节点的高度
 * 或通过入度来拓扑排序
 */
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int height[26];
vector<int> graph[26];
bool visited[26];

int getHeight(int x)
{
    if (height[x] != 0)
        return height[x];
    if (visited[x])
        return -1;
    visited[x] = true;

    int tmp = 1;
    for (int i = 0; i < graph[x].size(); i++)
    {
        int h = getHeight(graph[x][i]);
        if (h == -1)
            return -1;
        tmp = max(tmp, h + 1);
    }
    height[x] = tmp;
    return tmp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0)
            break;

        for (int i = 0; i < n; i++)
            graph[i].clear();

        int flag = false;
        for (int cnt = 1; cnt <= m; cnt++)
        {
            char x, c, y;
            cin >> x >> c >> y;
            if (flag)
                continue;
            graph[x - 'A'].push_back(y - 'A');
            char rank[26];
            memset(rank, 0, sizeof(rank));
            int i = 0;
            memset(height, 0, sizeof(height));
            memset(visited, false, sizeof(visited));
            for (; i < n; i++)
            {
                int h = getHeight(i);
                if (h == -1)
                {
                    cout << "Inconsistency found after " << cnt << " relations." << endl;
                    flag = true;
                    break;
                }
                if (h > 0 && rank[h - 1] == 0)
                    rank[h - 1] = 'A' + i;
                else
                    break;
            }
            if (i == n)
            {
                cout << "Sorted sequence determined after " << cnt << " relations: ";
                for (int j = n - 1; j >= 0; j--)
                    cout << rank[j];
                cout << "." << endl;
                flag = true;
            }
        }
        if (!flag)
        {
            cout << "Sorted sequence cannot be determined." << endl;
        }
    }
    return 0;
}
