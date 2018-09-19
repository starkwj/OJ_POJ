/**
 * POJ1328 Radar Installation
 * 贪心
 * 根据每个坐标计算出雷达安置的横坐标区间，将这些区间按左端点排序
 * 从左至右遍历，若能与下一个合并，则说明这两个岛屿能被同一雷达探测，新区间为两区间交集
 */
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

struct node {
    double left, right;
    bool operator<(const node &b) const
    {
        return left < b.left;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int ci = 0;
    int n, d;
    while (cin >> n >> d)
    {
        if (n == 0 && d == 0)
        {
            break;
        }
        ci++;
        vector<node> vec;
        double dsquare = d * d;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            if (y > d)
            {
                flag = false;
            }
            if (flag)
            {
                double d = sqrt(dsquare - y * y);
                vec.push_back({x - d, x + d});
            }
        }
        if (!flag)
        {
            cout << "Case " << ci << ": -1" << endl;
            continue;
        }
        sort(vec.begin(), vec.end());

        int i = 0;
        while (i < vec.size() - 1)
        {
            if (vec[i].right >= vec[i + 1].left)
            {
                vec[i + 1].right = min(vec[i].right, vec[i + 1].right);
                vec.erase(vec.begin() + i);
            }
            else
                i++;
        }
        cout << "Case " << ci << ": " << vec.size() << endl;
    }

    return 0;
}
