/**
 * POJ1840 Eqs
 * a1x13+ a2x23+ a3x33+ a4x43+ a5x53=0
 * ����������a1~a5��xi��[-50,50]��xi != 0�����ĸ���
 * hash���ȱ�������ǰ�������п��ܵĽ����ͳ�ƣ��ټ���������ֵ�ĸ�ֵ�Ƿ���ƥ��
 */
#include <iostream>
using namespace std;

#define OFFSET 18750000
int x3[51];

short m[37500001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a[5];
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
    for (int i = 0; i <= 50; i++)
        x3[i] = i * i * i;
    for (int i = -50; i <= 50; i++)
    {
        if (i == 0)
            continue;
        int t0 = i > 0 ? x3[i] : -x3[-i];
        for (int j = -50; j <= 50; j++)
        {
            if (j == 0)
                continue;
            int t1 = j > 0 ? x3[j] : -x3[-j];
            for (int k = -50; k <= 50; k++)
            {
                if (k == 0)
                    continue;
                int t2 = k > 0 ? x3[k] : -x3[-k];
                int tmp = a[0] * t0 + a[1] * t1 + a[2] * t2;
                m[tmp + OFFSET]++;
            }
        }
    }
    int ans = 0;
    for (int i = -50; i <= 50; i++)
    {
        if (i == 0)
            continue;
        int t3 = i > 0 ? x3[i] : -x3[-i];
        for (int j = -50; j <= 50; j++)
        {
            if (j == 0)
                continue;
            int t4 = j > 0 ? x3[j] : -x3[-j];
            int tmp = -a[3] * t3 - a[4] * t4;
            ans += m[tmp + OFFSET];
        }
    }
    cout << ans << endl;

    return 0;
}

