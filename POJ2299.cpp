/**
 * POJ2299 Ultra-QuickSort
 * 求逆序对数
 * 归并排序，也可用线段树做
 */
#include <iostream>
#include <cstring>
using namespace std;

int arr[500000];
int tmp[500000];

long long msort(int left, int right)
{
    if (left == right)
        return 0;
    long long cnt = 0;
    int mid = (left + right) >> 1;
    cnt += msort(left, mid);
    cnt += msort(mid + 1, right);
    int p = left, q = mid + 1;
    int k = 0;
    while (p <= mid && q <= right)
    {
        if (arr[p] <= arr[q])
            tmp[k++] = arr[p++];
        else
        {
            tmp[k++] = arr[q++];
            cnt += (mid - p + 1);
        }
    }
    while (p <= mid)
        tmp[k++] = arr[p++];
    while (q <= right)
    {
        tmp[k++] = arr[q++];
        cnt += mid - p + 1;
    }
    memcpy(arr + left, tmp, sizeof(int) * (right - left + 1));
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n && n)
    {
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << msort(0, n - 1) << endl;
    }

    return 0;
}
