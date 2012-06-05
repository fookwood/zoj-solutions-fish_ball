// 2955064 2008-06-23 00:25:34 Accepted 2994 C++ 00:00.01 848K 呆滞的慢板 

// 分成 3 种基本形状，削减法递推（这里倒放了一下，意会即可）: 
// A: ---- , B: -||- , C: --||
// 然后，各种形状都可由这三种状态的前几项递推得出，那就可以 DP 了 

#include <iostream>
using namespace std;

int A[1001], B[1000], C[1000];

int main() {
    
    A[0] = 1;
    A[1] = 1;
    B[0] = 0;
    B[1] = 1;
    C[0] = 0;
    C[1] = 1;
    
    for( int i = 2; i <= 1000; ++i ) {
        A[i] = A[i-2] + A[i-1] + B[i-1] + 2 * C[i-1];
        B[i] = A[i-1] + B[i-2];
        C[i] = A[i-1] + C[i-1];
    }
    
    int T,  N;
    
    cin >> T;
    
    for( int t = 1; t <= T; ++t ) {
        cin >> N;
        cout << t << ' ' << A[N] << endl;
    }
    
    
}
