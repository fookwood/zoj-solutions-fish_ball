// 2891820 2008-05-05 21:31:18 Accepted 2397 C++ 00:00.59 848K 呆滞的慢板

// 贪心，看别人的解题报告过的，贪心的方案在 algorithm.txt 上有。
// AC 之前自己也想用贪心，但正确性没有论证结果是无穷无尽的 WA
// 以后用贪心一定要经过严格的论证！！ 

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int     N,  A[1000],    B[1000];
    
    int     pA, pB, qA, qB, win, lose;
    
    while( ( cin >> N ) && N ) {
    
        for( int i = 0; i < N; ++i )
            cin >> A[i];
    
        for( int i = 0; i < N; ++i )
            cin >> B[i];
    
        sort( A, A + N );
        sort( B, B + N );
    
        pA = pB = 0;
        qA = qB = N;
        win = lose = 0;
    
        while( pA < qA ) {
            
            if( A[pA] > B[pB] ) {
                ++win;
                ++pB;
                ++pA;
            }
            else if( A[pA] < B[pB] ) {
                ++lose;
                --qB;
                ++pA;
            }
            else {
                if( A[qA - 1] > B[qB - 1] ) {
                    ++win;
                    --qA;
                    --qB;
                }
                else if( A[pA] < B[qB - 1] ) {
                    ++lose;
                    ++pA;
                    --qB;
                }
                else {
                    ++pA;
                    --qB;
                }

            }

        }

        printf( "%d\n", 200 * (win - lose) );
    }
}
