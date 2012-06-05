// 2890174 2008-05-05 10:41:44 Accepted 2547 C++ 00:00.00 832K 呆滞的慢板 
// 找出正确的递推关系，然后 DP，详见解题报告 

#include <iostream>
using namespace std;

int main() {
    
//          k =   0, 1, 2, 3 ...
    int A[31] = { 0, 1, 0, 4 };
    int C[31] = { 1, 0, 3, 0 };

    for( int i = 4; i < 31; ++i ) {
        A[i] = C[ i - 1 ] + A[ i - 2 ];
        if( i % 2 == 0 )
            C[i] = C[ i / 2 ] * C[ i / 2 ] +
               2 * A[ i / 2 ] * A[ i / 2 ] +
                   C[ i / 2 - 1 ] * C[ i / 2 - 1 ] +
               2 * A[ i / 2 - 1 ] * A[ i / 2 - 1 ];
        else
            C[i] = 0;
    }

    while( ( cin >> A[0] ) && A[0] >= 0 )
        cout << C[A[0]] << endl;

}
