/**
 * POJ1068 Parencodings
 * 括号匹配，根据输入先构造括号串
 */
#include <iostream>
#include <string.h>
using namespace std;

int a[40];
bool visited[40];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            while (k < x + i)
                a[k++] = 0;
            a[k++] = 1;
        }
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < (n << 1); i++)
        {
            if (a[i])
            {
                int cnt = 0;
                for (int j = i; j >= 0; j--)
                {
                    if (a[j])
                        cnt++;
                    else if (!visited[j])
                    {
                        visited[j] = true;
                        cout << cnt << " ";
                        break;
                    }
                }
            }
        }
        cout << endl;
    }

    return 0;
}
