#include <iostream>
using namespace std;

int main() {
    int T, N, A, P[50];
    for(cin >> T; T--;) {
        cin >> N;
        bool John = false;
        for(int i = A = 0; i < N; ++i) {
            cin >> P[i];
            A ^= P[i];
        }
        puts(A != 1 ? "John" : "Brother");
    }
}
