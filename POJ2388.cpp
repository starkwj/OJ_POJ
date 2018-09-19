/**
 * POJ2388 Who's in the Middle
 * 求中位数
 */
#include <iostream>
using namespace std;

int cow[10000];

int findKth(int left, int right, int k)
{
    if (left == right)
        return cow[left];

    int l = left, r = right;
    int tmp = cow[left];
    while (l < r)
    {
        while (l < r && cow[r] >= tmp)
            r--;
        while (l < r && cow[l] <= tmp)
            l++;
        if (l < r)
            swap(cow[l], cow[r]);
    }
    swap(cow[left], cow[l]);
    int t = l - left + 1;
    if (t == k)
        return cow[l];
    else if (t < k)
        return findKth(l + 1, right, k - t);
    else
        return findKth(left, l - 1, k);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> cow[i];
    cout << findKth(0, n - 1, (n + 1) >> 1) << endl;

    return 0;
}
