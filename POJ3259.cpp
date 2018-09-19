/**
 * POJ3259 Wormholes
 * 找是否有负环路 Bellman-Ford
 */
#include <iostream>
#include <vector>
using namespace std;

#define INF 0x1fffffff

int dist[2501];

struct E {
    int a, b, c;
};

vector<E> edge;

bool bellmanford(int n)
{
    for (int k = 0; k < n - 1; k++)
    {
        bool work = false;
        for (int i = 0; i < edge.size(); i++)
        {
            int a = edge[i].a;
            int b = edge[i].b;
            int c = edge[i].c;
            if (dist[b] > dist[a] + c)
            {
                work = true;
                dist[b] = dist[a] + c;
            }
        }
        if (!work)
            break;
    }

    for (int i = 0; i < edge.size(); i++)
    {
        int a = edge[i].a;
        int b = edge[i].b;
        int c = edge[i].c;
        if (dist[b] > dist[a] + c)
        {
            return false;
        }
    }
    return true;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int F;
    cin >> F;
    while (F--)
    {
        edge.clear();
        int n, m, w;
        cin >> n >> m >> w;
        int src = 0;
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            if (src == 0)
                src = a;
            edge.push_back({a, b, c});
            edge.push_back({b, a, c});
        }
        for (int i = 0; i < w; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            edge.push_back({a, b, -c});
        }
        if (bellmanford(n))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}
