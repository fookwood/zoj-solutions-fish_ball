#include <iostream>
#include <algorithm>
using namespace std;

int N, A[1001], p;

int main() {
    
    while(cin >> N && N) {
        for(int i = 0; i < N; ++i) cin >> A[i];
        sort(A, A + N);
        for(p = N - 1; p >= 0; p--) {
            bool found = false;
            for(int i = 0; i < N; ++i) {
                if(i == p) continue;
                for(int j = i + 1; j < N; ++j) {
                    if(j == p) continue;
                    if(binary_search(A + j + 1, A + N, A[p]-A[i]-A[j]) &&
                        A[p]-A[i]-A[j] != A[p]) {
                        found = true;
                        break;
                    }
                }
                if(found) break;
            }
            if(found) break;
        }
        if(p == -1) puts("no solution");
        else cout << A[p] << endl;
    }
    
}
