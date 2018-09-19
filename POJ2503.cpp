/**
 * POJ2503 Babelfish
 * ×Ö·û´®hash
 */
#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string en, fo;
    string line;
    map<string, string> m;
    while (getline(cin, line))
    {
        if (line == "")
            break;
        istringstream is(line);
        is >> en >> fo;
        m[fo] = en;
    }
    while (cin >> fo)
    {
        if (m.count(fo) > 0)
            cout << m[fo] << endl;
        else
            cout << "eh" << endl;
    }

    return 0;
}
