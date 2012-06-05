// 1802999 2009-03-25 10:39:21 Accepted  3180 C++ 0 184 呆滞的慢板 

// 对于这里，除非一个状态的前驱状态是初始状态，
// 否则一个状态的前驱状态是确定的，因此可以不断倒推状态，每次检查。 

#include <iostream>
#include <algorithm>
using namespace std;

void sort(int* A) {
    if(A[0] > A[1]) swap(A[0], A[1]);
    if(A[1] > A[2]) swap(A[1], A[2]);
    if(A[0] > A[1]) swap(A[0], A[1]);
}

bool decrease(int* A) {
    if(A[2] != A[0] + A[1] - 1) return false;
    A[2] = A[1] + 1 - A[0];
    sort(A);
    return A[0] != 1;
}

bool check(int* A, int* B) {
    if(A[0] == B[0] && A[1] == B[1] && A[2] == B[2]) return true;
    int C[3];
    C[0] = B[0], C[1] = B[1], C[2] = B[0] + B[1] - 1;
    if(A[0] == C[0] && A[1] == C[1] && A[2] == C[2]) return true;
    C[0] = B[0], C[1] = B[2], C[2] = B[0] + B[2] - 1;
    if(A[0] == C[0] && A[1] == C[1] && A[2] == C[2]) return true;
    C[0] = B[1], C[1] = B[2], C[2] = B[2] + B[1] - 1;
    if(A[0] == C[0] && A[1] == C[1] && A[2] == C[2]) return true;
    return false;
}

int main() {
    int A[3], B[3];
    int T;
    for(cin >> T; T--;) {
        cin >> A[0] >> A[1] >> A[2];
        cin >> B[0] >> B[1] >> B[2];
        sort(A);
        sort(B);
        int yes = false;
        while(!yes) {
            if(check(A, B)) yes = true;
            else if(!decrease(A) || A[0] < B[0]) break;
        }
        if(check(A, B)) yes = true;
        puts(yes ? "Yes" : "No");
    }
}
