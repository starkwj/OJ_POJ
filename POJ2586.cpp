/**
 * POJ2586 Y2K Accounting Bug
 * ����ÿ����ӯ��s�Ϳ���d����֪��������5���¿�����ȫ��ľ�ӯ��
 * ̰��
 */
#include <iostream>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int s, d;
    while (cin >> s >> d)
    {
        int a[12];
        a[0] = s;
        // �ȸ���s��d�Ĵ�С��ϵȷ��ǰ5���µ�ӯ��
        // ̰�Ĳ��ԣ���ӯ������ӯ����������������5���¿��������
        if (4 * s < d)
        {
            a[1] = a[2] = a[3] = s;
        }
        else if (3 * s < 2 * d)
        {
            a[1] = a[2] = s;
            a[3] = -d;
        }
        else if (2 * s < 3 * d)
        {
            a[1] = s;
            a[2] = a[3] = -d;
        }
        else if (s < 4 * d)
        {
            a[1] = a[2] = a[3] = -d;
        }
        else
        {
            cout << "Deficit" << endl;
            continue;
        }
        int sum = 0;
        for (int i = 0; i < 4; i++)
            sum += a[i];
        for (int i = 4; i < 12; i++)
        {
            if (sum + s >= 0)
                a[i] = -d;
            else
                a[i] = s;
            sum -= a[i - 4];
            sum += a[i];
        }
        sum = 0;
        for (int i = 0; i < 12; i++)
            sum += a[i];
        if (sum > 0)
            cout << sum << endl;
        else
            cout << "Deficit" << endl;
    }

    return 0;
}
