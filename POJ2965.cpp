/**
 * POJ2965 The Pilots Brothers' refrigerator
 * ×´Ì¬Ñ¹Ëõ + BFS»òDFS
 */
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

unsigned short flip[16] = {
    0x111F, 0x222F, 0x444F, 0x888F,
    0x11F1, 0x22F2, 0x44F4, 0x88F8,
    0x1F11, 0x2F22, 0x4F44, 0x8F88,
    0xF111, 0xF222, 0xF444, 0xF888
};

int mark[65536];
struct status {
    unsigned short t;
    int i;
};
status pre[65536];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned short r = 0;
    for (int i = 0; i < 16; i++)
    {
        char c;
        cin >> c;
        if (c == '+')
            r |= 1 << i;
    }

    memset(mark, -1, sizeof(mark));
    queue<unsigned short> q;
    q.push(r);
    mark[r] = 0;

    while (!q.empty() && mark[0] == -1)
    {
        unsigned short t = q.front();
        q.pop();
        for (int i = 0; i < 16; i++)
        {
            unsigned short nt = t ^ flip[i];
            if (mark[nt] == -1)
            {
                mark[nt] = mark[t] + 1;
                pre[nt].t = t;
                pre[nt].i = i;
                q.push(nt);
            }
        }
    }
    cout << mark[0] << endl;
    int nt = 0;
    while (true)
    {
        if (nt == r)
            break;
        int i = pre[nt].i;
        int x = (i >> 2) + 1;
        int y = (i & 3) + 1;
        cout << x << " " << y << endl;
        nt = pre[nt].t;
    }

    return 0;
}
