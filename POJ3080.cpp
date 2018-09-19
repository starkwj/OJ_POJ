/**
 * POJ3436 ACM Computer Factory
 * 最大流
 * n个机器，对输入、输出有要求，一个机器的输出满足另一个的输入要求时，建立一条边
 * 由于每个机器有容量限制，故double每个机器节点，一个入，一个出，入、出两节点之间的容量为机器的容量
 * 需要输出网络流的数量以及边的流量，遍历出点到入点的网络流（正向边为剩余容量，反向边为流量）
 * Edmond-Karp算法计算最大流
 */
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool cmp(const string &a, const string &b)
{
    if (a.length() == b.length())
        return a < b;
    else
        return a.length() > b.length();
}

string str[10];

int main()
{
    int n, m;
    cin >> n;
    while (n--)
    {
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> str[i];
        }
        int dp[61][61];
        memset(dp, 0, sizeof(dp));
        vector<string> v;
        for (int i = 1; i <= 60; i++)
        {
            for (int j = 1; j <= 60; j++)
            {
                if (str[0][i - 1] == str[1][j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = 0;
                if (dp[i][j] >= 3)
                {
                    v.push_back(str[0].substr(i - dp[i][j], dp[i][j]));
                }
            }
        }
        sort(v.begin(), v.end(), cmp);
        int i = 0;
        for (; i < v.size(); i++)
        {
            int j = 2;
            for (; j < m; j++)
            {
                if (str[j].find(v[i]) == string::npos)
                    break;
            }
            if (j == m)
                break;
        }
        if (i == v.size())
            cout << "no significant commonalities" << endl;
        else
            cout << v[i] << endl;
    }
    return 0;
}
