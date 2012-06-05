// 1683744 2008-10-31 00:12:52 Accepted  2409 C++ 0 184 呆滞的慢板 

// 纸牌的蘑菇题，创建比较准则，生成所有排列并检验即可。 

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int C[128];

class Card : public string {};

void init() {
    C['A'] = 0;  C['2'] = 1;  C['3'] = 2;  C['4'] = 3;
    C['5'] = 4;  C['6'] = 5;  C['7'] = 6;  C['8'] = 7;
    C['9'] = 8;  C['0'] = 9;  C['J'] = 10; C['Q'] = 11;
    C['K'] = 12; 
    C['C'] = 0;  C['D'] = 1;  C['H'] = 2;  C['S'] = 3;
}

int val(const Card& s) {
    int p = s.size() - 2;
    return C[s[p]]*4 + C[s[p+1]];
}

bool operator <(const Card& lhs, const Card& rhs) {
    return val(lhs) < val(rhs);
}

Card P[5];

int inc() {
    int p = P[3] < P[4] ? 3 : 4;
    p = P[2] < P[p] ? 2 : p;
    if(p == 2) {
        if(P[4] < P[3]) p += 3;
    }
    else if(p == 3) {
        if(P[4] < P[2]) p += 3;
    }
    else{
        if(P[3] < P[2]) p += 3;
    }
    return p - 1;
}

bool check() {
    return val(P[0]) == (val(P[1]) + inc()*4) % 52;
}

int main() {
    int T;
    cin >> T;
    init();
    for(int t = 1; t <= T; ++t) {
        for(int i = 0; i < 5; ++i)
            cin >> P[i];
        sort(P, P + 5);
        do {
            if(check()) break;
        } while(next_permutation(P, P + 5));
        printf("Problem %d:", t);
        for(int i = 0; i < 5; ++i)
            cout << ' ' << P[i];
        cout << endl;
    }
}
