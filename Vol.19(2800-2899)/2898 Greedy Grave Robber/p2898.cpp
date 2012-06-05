#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int N, V[24];
    bitset<50> B[24];
    while(cin >> N) {
        for(int i = 0; i < N; ++i) {
            cin >> V[i];
            int k; cin >> k;
            B[i].reset();
            while(k--) {
                int v;
                cin >> v;
                B[i].set(v - 1);
            }
        }
        int mx = 0;
        for(int i = 0; i < (1<<N); ++i) {
            
        }
    }
}
