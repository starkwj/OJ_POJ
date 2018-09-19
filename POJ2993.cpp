/**
 * POJ2993 Emag eht htiw Em Pleh
 * 字符串输入处理，与poj2996相反
 * 给出棋子位置，输出棋盘
 */
#include <iostream>
#include <string>
using namespace std;

string board = "+---+---+---+---+---+---+---+---+";
string oddline = "|...|:::|...|:::|...|:::|...|:::|";
string evenline = "|:::|...|:::|...|:::|...|:::|...|";
string grid[17];
string letter[2] = {
    "KQRBNP", "kqrbnp"
};

int main()
{
    for (int i = 0; i < 17; i += 2)
        grid[i] = board;
    for (int i = 1; i < 17; i += 4)
        grid[i] = oddline;
    for (int i = 3; i < 17; i += 4)
        grid[i] = evenline;

    string line;
    for (int i = 0; i < 2; i++)
    {
        cin >> line;
        cin >> line;
        line.append(1, ',');
        size_t pos1 = 0, pos2;
        while (pos1 < line.length())
        {
            pos2 = line.find(',', pos1);
            string tmp = line.substr(pos1, pos2 - pos1);
            pos1 = pos2 + 1;
            if (tmp.length() == 3)
            {
                char c = tmp[0];
                int row = (('0' + 8 - tmp[2]) << 1) + 1;
                int col = ((tmp[1] - 'a') << 2) + 2;
                for (int j = 0; j < 5; j++)
                {
                    if (c == letter[0][j])
                    {
                        grid[row][col] = letter[i][j];
                        break;
                    }
                }
            }
            else
            {
                int row = (('0' + 8 - tmp[1]) << 1) + 1;
                int col = ((tmp[0] - 'a') << 2) + 2;
                grid[row][col] = letter[i][5];
            }
        }
    }
    for (int i = 0; i < 17; i++)
        cout << grid[i] << endl;

    return 0;
}
