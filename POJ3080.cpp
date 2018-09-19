/**
 * POJ3436 ACM Computer Factory
 * �����
 * n�������������롢�����Ҫ��һ�����������������һ��������Ҫ��ʱ������һ����
 * ����ÿ���������������ƣ���doubleÿ�������ڵ㣬һ���룬һ�������롢�����ڵ�֮�������Ϊ����������
 * ��Ҫ����������������Լ��ߵ��������������㵽�����������������Ϊʣ�������������Ϊ������
 * Edmond-Karp�㷨���������
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
