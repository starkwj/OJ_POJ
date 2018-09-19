/**
 * POJ3253 Fence Repair
 * ¹þ·òÂüÊ÷
 */
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int m = 0;
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m = max(m, x);
        q.push(x);
    }
    long long ans = 0;
    while (true)
    {
        int x = q.top();
        q.pop();
        if (q.empty())
            break;
        int y = q.top();
        q.pop();
        ans += (long long)x + y;
        q.push(x + y);
    }
    cout << ans << endl;

    return 0;
}
