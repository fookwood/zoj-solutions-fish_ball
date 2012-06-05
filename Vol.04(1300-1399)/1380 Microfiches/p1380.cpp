#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

typedef bitset<15> B15;
typedef bitset<10000> B1W;

int T, N, G;

vector<B15> V;
vector<B1W> W;
const B1W base = 1;

bool P[15];

bool check(int k) {
    memset(P, 0, sizeof(P));
    for(int i = 0; i < k; ++i)
        P[G-i-1] = true;
    do {
        B1W now;
        now.set();
        for(int i = 0; i < G; ++i)
            if(P[i])
                now &= W[i];
        if(now == base) return true;
    } while(next_permutation(P, P + G));
    return false;
}

int main() {
    freopen("G.in", "r", stdin);
    freopen("test.out", "w", stdout);
    
    for(cin >> T; T--;) {
        cin >> N >> G;
        V.resize(N);
        W.resize(G);
        for(int i = 0; i < N; ++i)
            cin >> V[i];
        if(N == 1) {
            puts("0");
            continue;
        }
        for(int i = 0; i < G; ++i) {
            W[i].reset();
            for(int j = 0; j < N; ++j)
                if(!(V[0] ^ V[j])[i])
                    W[i].set(j);
        }
        int l = 0, r = G, m;
        while(l + 1 < r) {
            m = l + r >> 1;
            if(check(m)) r = m;
            else l = m;
        }
        cout << r << endl;
    }
}

