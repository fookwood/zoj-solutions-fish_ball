// 2871488 2008-04-26 16:03:59 Accepted 1666 C++ 00:00.17 852K 呆滞的慢板 
// 简单的搜索，次序不错问题也就不大

#include <iostream>
using namespace std;

const int A[] = { 1,   4,   9,  16,  25,  36,  49,  64,  81,
                     100, 121, 144, 169, 196, 225, 256, 289 };
const int SZ = sizeof A / sizeof *A;

int DFS( const int& remain, const int& pos ) {
    if( remain == 0 )       return  1;
    if( pos < 0 )           return  0;
    if( remain < A[pos] )   
        return  DFS( remain, pos - 1 );
    else
        return  DFS( remain, pos - 1 ) +
            DFS( remain - A[pos], pos );
}

int main() {
    int     N;
    while( ( cin >> N ) && N )
        cout << DFS( N, SZ - 1 ) << endl;
}
