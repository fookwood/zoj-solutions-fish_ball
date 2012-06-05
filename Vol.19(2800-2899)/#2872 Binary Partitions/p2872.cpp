// 2897827 2008-05-08 08:44:07 Accepted 2872 C++ 00:00.06 8648K 呆滞的慢板 

// DP,递推关系见解题报告 

#include <iostream>
using namespace std;

int     T,  N;
int     B[2000001];

int main() {
    
    B[0] = B[1] = 1;
    
    for( int i = 2; i < 2000001; ++i ) {
        if( i % 2 ) B[i] = B[i - 1];
        else        B[i] = ( B[i - 2] + B[i / 2] ) % 1000000;
    }
    
    cin >> T;
    
    while( T-- ) {
        cin >> N;
        cout << B[N] << endl;
    }
    
}
