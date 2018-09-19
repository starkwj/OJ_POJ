/**
 * POJ1008 Maya Calendar
 * 日期转换，注意取余计算，下标从0开始比较方便
 */
#include <iostream>
#include <string>
using namespace std;

string maya[19] = {
    "pop", "no", "zip", "zotz", "tzec",
    "xul", "yoxkin", "mol", "chen", "yax",
    "zac", "ceh", "mac", "kankin", "muan",
    "pax", "koyab", "cumhu", "uayet"
};

string Tzolkin[20] = {
    "imix", "ik", "akbal", "kan", "chicchan",
    "cimi", "manik", "lamat", "muluk", "ok",
    "chuen", "eb", "ben", "ix", "mem",
    "cib", "caban", "eznab", "canac", "ahau"
};

int getMayaDay(string s)
{
    for (int i = 0; i < 19; i++)
    {
        if (s == maya[i])
            return i * 20;
    }
    return 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cout << n << endl;
    while (n--)
    {
        int x, y;
        char c;
        string month;
        cin >> x >> c >> month >> y;
        int day = y * 365 + getMayaDay(month) + x;
        int ty = day / 260;
        int td = day % 260;
        string tm = Tzolkin[td % 20];
        int tdi = td % 13 + 1;
        cout << tdi << " " << tm << " " << ty << endl;
    }

    return 0;
}
