// 1802959 2009-03-25 10:08:03 Accepted  3179 C++ 0 184 呆滞的慢板 

// 算盘，先按照算盘形状读出实际数字，然后再验证即可，比较简单的一道题。 

#include <iostream>
using namespace std;

int main() {
    int T, X, Y, S;
    char A[8][7];
    for(cin >> T; T--;) {
        cin >> X >> Y;
        for(int i = 0; i < 8; ++i)
            cin >> A[i];
        S = 0;
        for(int i = 0; i < 6; ++i) {
            S *= 10;
            if(A[0][i] == '|') S += 5;
            if(A[4][i] == '|') S += 1;
            if(A[5][i] == '|') S += 2;
            if(A[6][i] == '|') S += 3;
            if(A[7][i] == '|') S += 4;
        }
        for(int i = X; i <= Y; ++i) S -= i;
        puts(S == 0 ? "No mistake" : "Mistake");
    }
}
