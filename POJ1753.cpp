/**
 * POJ1753 Flip Game
 * ·­Æå×Ó
 * ×´Ì¬Ñ¹Ëõ + BFS
 */
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

unsigned short flip[16] = {
    0x0013, 0x0027, 0x004E, 0x008C,
    0x0131, 0x0272, 0x04E4, 0x08C8,
    0x1310, 0x2720, 0x4E40, 0x8C80,
    0x3100, 0x7200, 0xE400, 0xC800
};

int mark[65536];

int main()
{
    unsigned short g = 0;
    for (int i = 0; i < 16; i++)
    {
        char c;
        cin >> c;
        if (c == 'w')
            g |= 1 << i;
    }
    if (g == 0 || g == 0xffff)
    {
        cout << 0 << endl;
        return 0;
    }
    memset(mark, -1, sizeof(mark));
    queue<unsigned short> q;
    q.push(g);
    mark[g] = 0;
    int ans = -1;
    while (!q.empty() && ans == -1)
    {
        unsigned short t = q.front();
        q.pop();
        for (int i = 0; i < 16; i++)
        {
            unsigned short nt = t ^ flip[i];
            if (mark[nt] == -1)
            {
                mark[nt] = mark[t] + 1;
                q.push(nt);
                if (nt == 0 || nt == 0xffff)
                {
                    ans = mark[nt];
                    break;
                }
            }
        }
    }
    if (ans == 0)
        cout << "Impossible" << endl;
    else
        cout << ans << endl;

    return 0;
}
