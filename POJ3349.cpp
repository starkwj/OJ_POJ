/**
 * POJ3349 Snowflake Snow Snowflakes
 * 一个雪花6个数表示，判断所给的雪花中有没有相同的
 * 顺时针逆时针均要判断，每读入一个雪花，需要将可能的12种情况均添加到hash中
 * 注意雪花本身有循环时，不应判断成有相同，添加时间戳解决
 */
#include <stdio.h>
#include <string.h>

int timestamp = 0;
struct Node {
    int arr[6];
    int timestamp;
    int next;
};

Node node[1200000];
int hashTable[100007];

int cur = 0;

int gethash(int *arr)
{
    int h = 0;
    for (int i = 0; i < 6; i++)
        h += arr[i];
    return h % 100007;
}

bool cmp(int *a, int *b)
{
    for (int i = 0; i < 6; i++)
        if (a[i] != b[i])
            return false;
    return true;
}

bool insertHash(int *arr)
{
    int h = gethash(arr);
    int i = hashTable[h];
    while (i != -1)
    {
        if (cmp(arr, node[i].arr))
        {
            if (node[i].timestamp == timestamp)
                return true;
            else
                return false;
        }
        i = node[i].next;
    }
    for (i = 0; i < 6; i++)
    node[cur].arr[i] = arr[i];
    node[cur].timestamp = timestamp;
    node[cur].next = hashTable[h];
    hashTable[h] = cur++;
    return true;
}

int main()
{
    memset(hashTable, -1, sizeof(hashTable));
    int n;
    scanf("%d", &n);
    bool flag = true;
    while (n--)
    {
        int a[12];
        int b[12];
        for (int i = 0; i < 6; i++)
        {
            scanf("%d", &a[i]);
            a[i + 6] = b[5 - i] = b[11 - i] = a[i];
        }
        if (!flag)
            continue;
        for (int i = 0; i < 6; i++)
        {
            if (!insertHash(a + i) || !insertHash(b + i))
            {
                flag = false;
                break;
            }
        }
        timestamp++;
    }
    if (flag)
        printf("No two snowflakes are alike.\n");
    else
        printf("Twin snowflakes found.\n");

    return 0;
}
