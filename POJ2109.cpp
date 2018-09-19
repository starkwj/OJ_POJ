/**
 * POJ2109 Power of Cryptography
 * 给定n，p 求k，k^n = p
 * 二分 + 高精度整数
 * 此题也可取巧用double实现
 */
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string multi(string &a, string &b)
{
    int lena = a.length();
    int lenb = b.length();
    string c(lena + lenb, '0');
    int carry = 0;
    for (int i = lena - 1; i >= 0; i--)
    {
        for (int j = lenb - 1; j >= 0; j--)
        {
            int tmp = (a[i] - '0') * (b[j] - '0') + c[i + j + 1] - '0' + carry;
            c[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        if (carry > 0)
        {
            c[i] = carry + '0';
            carry = 0;
        }
    }
    size_t pos = c.find_first_not_of("0");
    if (pos == string::npos)
        return "";
    else
        return c.substr(pos);
}

int cmp(string a, string b)
{
    size_t pos = a.find_first_not_of("0");
    if (pos == string::npos)
        a = "0";
    else
        a = a.substr(pos);
    pos = b.find_first_not_of("0");
    if (pos == string::npos)
        b = "0";
    else
        b = b.substr(pos);

    if (a.length() == b.length())
    {
        if (a < b)
            return -1;
        else if (a == b)
            return 0;
        else
            return 1;
    }
    else
    {
        if (a.length() < b.length())
            return -1;
        else
            return 1;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string p;
    while (cin >> n >> p)
    {
        int left = 1, right = 1e9;
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            stringstream os;
            os << mid;
            string s = os.str();
            string c = "1";
            int t = n;
            while (t)
            {
                if (t & 1)
                    c = multi(c, s);
                s = multi(s, s);
                t >>= 1;
            }
            int k = cmp(c, p);
            if (k == 0)
            {
                right = mid;
                break;
            }
            else if (k < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        cout << right << endl;
    }

    return 0;
}
