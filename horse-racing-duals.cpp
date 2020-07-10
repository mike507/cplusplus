#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N; cin.ignore();

    vector<int> vect;
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        vect.push_back(Pi);
    }
    sort(vect.begin(), vect.end());
    long val = vect[1] - vect[0];

    for(auto it = begin(vect); it != end(vect)-1; it++)
    {
        int diff = *(it+1) - (*it);
        if (val > diff)
            val = diff;
    }
  
    cout << val << endl;
}