/**
 * POJ3041 Asteroids
 * �����и���һЩ�㣬�����ٵ��л�������ȫ��������Щ��
 * ������ͼ��С���� ת���ɶ���ͼ���ƥ������������㷨
 */
#include <iostream>
#include <cstring>
using namespace std;

bool edge[501][501];
int n;
bool check[501];
int match[501];

bool dfs(int u)
{
    for (int i = 1; i <= n; i++)
    {
        if (edge[u][i])
        {
            if (!check[i])
            {
                check[i] = true;
                if (match[i] == 0 || dfs(match[i]))
                {
                    match[i] = u;
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> n >> k;
    memset(edge, false, sizeof(edge));
    memset(match, 0, sizeof(match));
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        edge[x][y] = true;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(check, false, sizeof(check));
        if (dfs(i))
            ++ans;
    }
    cout << ans << endl;

    return 0;
}
