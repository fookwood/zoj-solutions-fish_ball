// 1663354 2008-10-11 11:26:35 Accepted  1707 C++ 0 184 ´ôÖÍµÄÂı°å 

// ×Ö·û´®Ìæ»»£¬×¢Òâ¶ÁÌâ£ºContinue until the find string no longer occurs within the text. 

#include <iostream>
#include <string>
using namespace std;

int N;
string x[10], y[10], s;

void replace(string z, string p) {
    int pos;
    while((pos = s.find(z)) != string::npos)
        s.replace(pos, z.size(), p);
}

int main() {
    while(cin >> N && N) {
        getline(cin , s);
        for(int i = 0; i < N; ++i) {
            getline(cin, x[i]);
            getline(cin, y[i]);
        }
        getline(cin, s);
        for(int i = 0; i < N; ++i)
            replace(x[i], y[i]);
        cout << s << endl;
    }
}
