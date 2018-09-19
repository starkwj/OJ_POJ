/**
 * POJ3087 Shuffle'm Up
 * Ï´ÅÆ Ä£Äâ
 */
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int k = 1; k <= n; k++)
    {
        int c;
        cin >> c;
        string s1, s2, target;
        cin >> s1 >> s2 >> target;
        set<string> s;
        int ans = 0;
        while (true)
        {
            string tmp(2 * c, 0);
            for (int i = 0; i < c; i++)
            {
                tmp[i << 1] = s2[i];
                tmp[(i << 1) + 1] = s1[i];
            }
            ans++;
            if (tmp == target)
            {
                cout << k << " " << ans << endl;
                break;
            }
            if (s.count(tmp) > 0)
            {
                cout << k << " " << -1 << endl;
                break;
            }
            s.insert(tmp);
            s1 = tmp.substr(0, c);
            s2 = tmp.substr(c, c);
        }
    }

    return 0;
}
