// https://www.codingame.com/ide/puzzle/create-the-longest-sequence-of-1s

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
    string s;

    getline(cin, s);

    size_t p1 = 0;
    size_t p2 = 0;
    size_t max = 0;

    do
    {
        p2 = s.find('0', p1);
        vector<string> strings;
        if (p2 != string::npos)
        {
            string s2 = s;
            string ns = s2.replace(p2, 1, "1");
            istringstream f(ns);
            string temp;
            while (getline(f, temp, '0')) {
                strings.push_back(temp);
            }
            for (string str : strings)
            {
                if (str.length() > max)
                    max = str.length();
            }
            p1 = p2 + 1;
        }
    } while (p2 != string::npos);
    cout << max;
}