#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

int N, MASK;

vector<int> S;

void disp(int k) {
    for(int i = 0; i < N; ++i) {
        putchar(k&1 ? '1' : '0');
        k >>= 1;
    }
    puts("");
}

bool B[1<<13];

bool dfs(int k) {
    B[k] = true;
    S.push_back(k);
    if(S.size() == 1<<N && 
        bitset<12>(S.back()^S.front()).count() >= N/2)
        return true;
    for(int i = 0; i < N; ++i) {
        int p = (MASK & ~(1<<i)) ^ k;
        if(!B[p] && dfs(p)) return true;
        for(int j = 0; j < i; ++j) {
            p = (MASK & ~((1<<i)|(1<<j))) ^ k;
            if(!B[p] && dfs(p)) return true;
        }
    }
    S.pop_back();
    return B[k] = false;
}

bool valid(int x, int y) {
    return bitset<12>(x^y).count()>=N/2;
}

int main() {
//    freopen("out.txt", "w", stdout);
    int T = 0;
    while(cin >> N && N) {
        if(T++) puts("");
        if(N == 1) {puts("0\n1"); continue;}
//        if(N == 3) {puts("none"); continue;}
        MASK = (1<<N) - 1;
        memset(B, 0, sizeof(B));
        S.clear();
        if(!dfs(0)){while(1);}// {puts("none"); continue;}
        for(int i=0;i<S.size();++i){if(!valid(S[i],S[(i+1)&MASK]))while(1)puts("fuck");}
        if(S.size()!=1<<N)while(1)puts("fuck");
        for(int i = 0; i < S.size(); ++i) disp(S[i]);
    }
}
