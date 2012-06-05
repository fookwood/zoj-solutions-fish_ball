// 1663290 2008-10-11 10:48:57 Accepted  1764 C++ 0 184 ´ôÖÍµÄÂý°å 

// ¼òµ¥Ä£Äâ¡£ 

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Rec {
    string name;
    int c, p;
    Rec() : name(""), c(0), p(0) {}
};

bool cmp(const Rec& lhs, const Rec& rhs) {
    return lhs.c > rhs.c || lhs.c == rhs.c && lhs.p < rhs.p;
}

vector<Rec> V;

int N;

int main() {
    while(cin >> N) {
        V.resize(N);
        for(int i = 0; i < N; ++i) {
            cin >> V[i].name;
            string buf;
            getline(cin, buf);
            istringstream is(buf);
            int x, y;
            while(is >> x >> y) {
                if(y) {
                    V[i].c += 1;
                    V[i].p += (x-1)*20 + y;
                }
            }
        }
        sort(V.begin(), V.end(), cmp);
        cout << V[0].name << ' ' << V[0].c << ' ' << V[0].p << endl;
    }
    
}
