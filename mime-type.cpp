https://www.codingame.com/ide/puzzle/mime-type

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int N;
    cin >> N; cin.ignore();
    int Q;
    cin >> Q; cin.ignore();
    map<string, string> mimes;

    for (int i = 0; i < N; i++) {
        string EXT;
        string MT;
        cin >> EXT >> MT; cin.ignore();
        transform(EXT.begin(), EXT.end(), EXT.begin(), ::tolower);
        mimes[EXT] = MT;
    }

    for (int i = 0; i < Q; i++) {
        string FNAME;
        getline(cin, FNAME);
        transform(FNAME.begin(), FNAME.end(), FNAME.begin(), ::tolower);
        int idx = FNAME.find_last_of('.');
        if (idx != -1) {
            string ext = FNAME.substr(idx + 1);
            if (mimes.find(ext) != mimes.end()) {
                cout << mimes[ext] << endl;
                continue;
            }
        }
        cout << "UNKNOWN" << endl;
    }
}
