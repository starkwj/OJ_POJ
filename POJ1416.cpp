/**
 * POJ1416 Shredding Company
 * 给一个阈值sum，一个不超过6位的数str
 * 将str分成若干段，其和不超过sum，求最大的和以及分法
 * dfs
 */
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int sum;
string str;
int ans = -1;
int cnt;
bool cut[6];
bool tmpcut[6];
bool rejected;

int getSum(string s)
{
    int t = 0;
    for (int i = 0; i < s.length(); i++)
    {
        t += s[i] - '0';
    }
    return t;
}

void dfs(int cur, int left, int k)
{
    // cur为当前和，left为不切时前面剩下的遗留值
    if (cur > sum || left > sum)    // 超过阈值剪枝
        return;
    if (k == str.length() - 1)  // 到最后一步
    {
        cur += left * 10 + str[k] - '0';
        if (cur > sum)
            return;
        if (cur == ans)
            cnt++;
        else if (cur > ans)
        {
            ans = cur;
            cnt = 1;
            memcpy(cut, tmpcut, sizeof(cut));
        }
        return;
    }
    if (cur + getSum(str.substr(k)) > sum)
        return;
    tmpcut[k] = true;
    dfs(cur + left * 10 + str[k] - '0', 0, k + 1);  // 该步切
    tmpcut[k] = false;  // 回溯
    dfs(cur, left * 10 + str[k] - '0', k + 1);  // 该步不切
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> sum >> str && sum > 0)
    {
        memset(cut, false, sizeof(cut));
        memset(tmpcut, false, sizeof(cut));
        rejected = false;
        ans = -1;
        cnt = 0;
        dfs(0, 0, 0);
        if (ans == -1)
            cout << "error" << endl;
        else if (cnt > 1)
            cout << "rejected" << endl;
        else
        {
            cout << ans;
            int pre = 0;
            cut[str.length() - 1] = true;
            for (int i = 0; i < str.length(); i++)
            {
                if (cut[i])
                {
                    cout << " " << str.substr(pre, i + 1 - pre);
                    pre = i + 1;
                }
            }
            cout << endl;
        }
    }
    return 0;
}
