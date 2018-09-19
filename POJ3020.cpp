/**
 * POJ3020 Antenna Placement
 * ����2*1�����ߣ�����ͼ�����е�'*'
 * �Ƚ�ͼ����'*'Ϊ���㣬��double�������ֵĶ���ͼ������С���㸲�� = ԭ������ - ���ƥ����/2
 * �������㷨
 */
#include <iostream>
#include <cstring>
using namespace std;

char graph[40][10];
int index[40][10];
int cnt;
bool edge[401][401];

int dir[4][2] = {
    -1, 0,
    1, 0,
    0, -1,
    0, 1
};

int match[401];
bool check[401];

bool dfs(int u)
{
    for (int i = 1; i <= cnt; i++)
    {
        if (edge[u][i] && !check[i])
        {
            check[i] = true;
            if (match[i] == 0 || dfs(match[i]))
            {
                match[i] = u;
                return true;
            }
        }
    }
    return false;
}

int hungarian()
{
    int ans = 0;
    memset(match, 0, sizeof(match));
    for (int i = 1; i <= cnt; i++)
    {
        memset(check, false, sizeof(check));
        if (dfs(i))
            ans++;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--)
    {
        cnt = 0;
        memset(edge, false, sizeof(edge));
        memset(index, 0, sizeof(index));
        int h, w;
        cin >> h >> w;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> graph[i][j];
                if (graph[i][j] == '*')
                {
                    index[i][j] = ++cnt;
                }
            }
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (graph[i][j] == '*')
                {
                    int s = index[i][j];
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = i + dir[k][0];
                        int ny = j + dir[k][1];
                        if (nx >= 0 && nx < h && ny >= 0 && ny < w && graph[nx][ny] == '*')
                        {
                            int d = index[nx][ny];
                            edge[s][d] = edge[d][s] = true;
                        }
                    }
                }
            }
        }

        cout << (cnt - hungarian() / 2) << endl;
    }
    return 0;
}
