/**
 * POJ1001 Exponentiation
 * �߾��ȸ������˷�
 * �ȼ�¼С����λ����ת��Ϊ�߾��������˷����ٻ�ԭС����
 * ��Ҫ��������ͷβ
 */
#include <iostream>
#include <string>
using namespace std;

struct bigInt {
    string s;
    string multi(string strb)
    {
        string strc(s.length() + strb.length(), '0');
        int carry = 0;
        int i, j;
        for (i = s.length() - 1; i >= 0; i--)
        {
            for (j = strb.length() - 1; j >= 0; j--)
            {
                int t = (s[i] - '0') * (strb[j] - '0') + strc[i + j + 1] - '0' + carry;
                strc[i + j + 1] = (t % 10) + '0';
                carry = t / 10;
            }
            if (carry)
            {
                strc[i + j + 1] = carry + '0';
                carry = 0;
            }
        }
        return strc;
    }
};

int main()
{
    string r;
    int n;
    while (cin >> r >> n)
    {
        if (r[0] == '.')
            r.insert(0, 1, '0');
        size_t pos1 = r.find('.');
        size_t pos2 = r.find_last_not_of("0");
        if (pos2 != string::npos && pos1 != string::npos && pos2 > pos1)
        {
            r = r.substr(0, pos2 + 1);
        }
        if (pos1 != string::npos)
        {
            r.erase(pos1, 1);
            pos1 = (r.length() - pos1) * n; // ȷ�����С�����λ��
        }
        bigInt rbi, ans;
        ans.s = "1";
        rbi.s = r;
        while (n)
        {
            if (n & 1)
                ans.s = ans.multi(rbi.s);
            rbi.s = rbi.multi(rbi.s);
            n >>= 1;
        }
        r = ans.s;
        if (pos1 != string::npos)
        {
            pos1 = r.length() - pos1;
            r.insert(pos1, 1, '.');
            pos2 = r.find_last_not_of("0");
            if (pos2 != string::npos)   // ɾȥС�����ĩβ��0
            {
                if (pos2 > pos1)
                    r.erase(r.begin() + pos2 + 1, r.end());
                if (pos2 == pos1)   // �����һλ��С���㣬��ҪɾȥС����
                    r.erase(r.begin() + pos2, r.end());
            }
        }
        pos2 = r.find_first_not_of("0");
        if (pos2 == string::npos)
            r = "0";
        else
            r = r.substr(pos2);
        cout << r << endl;
    }

    return 0;
}

