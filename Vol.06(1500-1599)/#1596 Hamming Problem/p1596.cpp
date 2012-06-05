// 丑数，好无耻啊！！
// long long WA 无穷次，然后改成 unsigned long long 就 AC
// 不是说好了在 1e18 以内的吗？ 
// 2844898 2008-04-15 12:20:50 Accepted 1596 C++ 00:00.12 1628K 呆滞的慢板 

#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long xlong;

int main() {
    xlong   A[3],   H[100000];
    int     N;
    while( cin >> A[0] >> A[1] >> A[2] >> N ){
        int n = 1;
        sort( A, A + 3 );
        H[0] = 1;
        for( int k = 0; k < N; k++ ) {
            xlong   m = H[n - 1] * A[0];
            for( int i = n - 2; i >= 0 && H[i] * A[3] > H[n - 1]; i-- ) {
                for( int j = 0; j < 3; j++ ) {
                    if( A[j] * H[i] > H[n - 1] && A[j] * H[i] < m ) {
                        m = A[j] * H[i];
                        break;
                    }
                }
            }
            H[n++] = m;
        }
        cout << H[N]<< endl;
    }
}
