/**
 * POJ2996 Help Me with the Game
 * 字符串输入处理
 * 给出象棋地图，按要求输出棋子位置
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string col = "abcdefgh";
string wl = "KQRBN";
string bl = "kqrbn";
vector<string> w[5];
vector<string> b[5];
vector<string> wp, bp;
bool cmp1(const string &a, const string &b)
{
    if (a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}
bool cmp2(const string &a, const string &b)
{
    if (a[1] == b[1])
        return a[0] < b[0];
    return a[1] > b[1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string line;
    for (int i = 0; i < 8; i++)
    {
        cin >> line;
        cin >> line;
        for (int j = 0; j < 8; j++)
        {
            char c = line[(j << 2) + 2];
            if (!isalpha(c))
                continue;
            string loc(1, col[j]);
            loc.append(1, '0' + 8 - i);
            if (isupper(c))
            {
                for (int k = 0; k < 5; k++)
                {
                    if (c == wl[k])
                    {
                        w[k].push_back(loc);
                        break;
                    }
                }
                if (c == 'P')
                    wp.push_back(loc);
            }
            else
            {
                for (int k = 0; k < 5; k++)
                {
                    if (c == bl[k])
                    {
                        b[k].push_back(loc);
                        break;
                    }
                }
                if (c == 'p')
                    bp.push_back(loc);
            }
        }
    }
    cin >> line;
    sort(wp.begin(), wp.end(), cmp1);
    sort(bp.begin(), bp.end(), cmp2);
    cout << "White: ";
    bool flag = false;
    for (int i = 0; i < 5; i++)
    {
        sort(w[i].begin(), w[i].end(), cmp1);
        for (int j = 0; j < w[i].size(); j++)
        {
            if (flag)
                cout << ",";
            else
                flag = true;
            cout << wl[i] << w[i][j];
        }
    }
    for (int i = 0; i < wp.size(); i++)
    {
        if (flag)
            cout << ",";
        else
            flag = true;
        cout << wp[i];
    }
    cout << endl;
    flag = false;
    cout << "Black: ";
    for (int i = 0; i < 5; i++)
    {
        sort(b[i].begin(), b[i].end(), cmp2);
        for (int j = 0; j < b[i].size(); j++)
        {
            if (flag)
                cout << ",";
            else
                flag = true;
            cout << wl[i] << b[i][j];
        }
    }
    for (int i = 0; i < bp.size(); i++)
    {
        if (flag)
            cout << ",";
        else
            flag = true;
        cout << bp[i];
    }
    cout << endl;
    return 0;
}
