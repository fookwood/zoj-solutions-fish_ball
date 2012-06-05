// 2893252 2008-05-06 15:35:22 Accepted 1149 C++ 00:00.01 848K 呆滞的慢板 

// 实际上是个背包，不过直接搞数太大，这样来：
// 如果有一种珠子数量大于 20，那如果奇数变成 19，偶数变成 20
// 原因如下：假如某种珠子很多，可能需要用它来填平其他珠子造成的不平衡
// 但是实际可能要不了那么多
// 而我个人觉得，能造成的不平衡，如果用 20 个珠子还消不掉，那么就歇菜了吧 
// 还是过了... 说明数据的脆弱性是可以掩盖算法论证的脆弱性的... ym
 
// 而网上流传的模 30 太狠了，明显欺负数据，就 30 0 0 1 0 1 都可以搞掉 

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {

    set<int> S;
    set<int>::iterator  iter;
    vector<int> V;
    
    int A[7];
    
    for( int T = 1; ; ++T ) {
        
        for( int i = 1; i <= 6; ++i )
            cin >> A[i];
            
        if( !( A[1] || A[2] || A[3] ||
               A[4] || A[5] || A[6] ) ) break;
        
        cout << "Collection #" << T << ":\n";
        
        int sum = 0;
        for( int i = 1; i <= 6; ++i ) {
            if( A[i] > 20 )
                A[i] = A[i] % 2 ? 19 : 20;
            sum += A[i] * i;
        }
        
        if( sum % 2 ) {
            puts( "Can't be divided.\n" );
            continue;
        }
        
        sum /= 2;
        S.clear();
        S.insert( 0 );
        bool  div = false;

        for( int i = 6; i; --i ) {
            while( A[i]-- ) {
                V.clear();
                for( iter = S.begin(); iter != S.end(); ++iter ) {
                    if( *iter + i <= sum )
                        V.push_back( *iter + i );
                    if( *iter + i == sum ) {
                        div = true;
                        break;
                    }
                }
                if( div )   break;
                S.insert( V.begin(), V.end() );
            }
            if( div )   break;
        }
        
        puts( div ? "Can be divided.\n"
                  : "Can't be divided.\n" );
        
    }

}
