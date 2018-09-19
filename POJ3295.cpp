/**
 * POJ3295 Tautology
 * 判断表达式是否永真，最多5个变量
 * 枚举5个变量共32种情况，从尾开始计算表达式的值
 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

char getVal(char code, char c)
{
    switch (c) {
    case 'p':
        return (code >> 4) & 1;
    case 'q':
        return (code >> 3) & 1;
    case 'r':
        return (code >> 2) & 1;
    case 's':
        return (code >> 1) & 1;
    case 't':
        return code & 1;
    default:
        return 2;  // 运算符返回2
    }
}

bool isTautology(string WFF, char code)
{
    stack<bool> res;
    for (int i = WFF.length() - 1; i >= 0; i--)
    {
        char v = getVal(code, WFF[i]);
        if (v < 2)
            res.push(v);
        else
        {
            if (WFF[i] == 'N')
            {
                bool w = res.top();
                res.pop();
                res.push(!w);
            }
            else
            {
                bool w = res.top();
                res.pop();
                bool x = res.top();
                res.pop();
                switch (WFF[i]) {
                case 'K':
                    res.push(w && x);
                    break;
                case 'A':
                    res.push(w || x);
                    break;
                case 'C':
                    res.push((!w) || x);
                    break;
                case 'E':
                    res.push(w == x);
                    break;
                }
            }
        }
    }
    return !res.empty() && res.top();
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    string WFF;
    while (cin >> WFF)
    {
        if (WFF == "0")
            break;
        bool flag = true;
        for (char i = 0; i < 32; i++)
        {
            if (!isTautology(WFF, i))
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "tautology" << endl;
        else
            cout << "not" << endl;
    }

    return 0;
}
