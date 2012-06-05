// DP 的方法 
// 2846089 2008-04-15 20:26:12 Accepted 1095 C++ 00:00.51 928K 呆滞的慢板

#include <iostream>
using namespace std;

typedef long long xlong;

int main() {
    xlong   N,  H[5843] = { 0, 1 };
    xlong   A[4] = { 2, 3, 5, 7 };
    for( int i = 1; i < 5842; i++ ) {
        H[i + 1] = H[i] * 2;
        for( int j = i - 1; j > 0; j-- ) {
            for( int k = 0; k < 4; k++ ) {
                xlong    prod = A[k] * H[j];
                if( prod > H[i] ) {
                    if( prod < H[i + 1] )
                        H[i + 1] = prod;
                    break;
                }
            }
            if( H[j] * A[3] <= H[i] )  break;
        }
    }
    while( ( cin >> N ) && N ) {
        cout << "The " << N ;
        if( N % 100 > 10 && N % 100 < 19) cout << "th";
        else if( N % 10 == 1 ) cout << "st";
        else if( N % 10 == 2 ) cout << "nd";
        else if( N % 10 == 3 ) cout << "rd";
        else cout << "th"; 
        cout << " humble number is " << H[N] << ".\n"; 
    }
}
