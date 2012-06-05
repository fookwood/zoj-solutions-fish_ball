// 3019857 2008-08-03 19:42:47 Accepted 1985 C++ 00:00.32 2408K 呆滞的慢板 

// O(n) 求出每个方块左边第一个比它矮的和右边第一个比它矮的
// 然后枚举各个方块，求出最大面积，O(n)

// 至于怎么 O(n) 求出每个方块左边第一个比它矮的和右边第一个比它矮的
// 可以用一个栈，过程类似凸包的 Graham 扫描法 

#include <iostream>
#include <vector>
using namespace std;

int L[100002],  R[100002],  N;

long long H[100002];

vector<int> stk;

int main() {
    
    while( cin >> N && N ) {
        
        for( int i = 1, x; i <= N; ++i )
            scanf( "%lld", H+i );
        
        H[0] = H[N + 1] = -1;
        
        stk.clear();
        stk.push_back( 0 );
        for( int i = 1; i <= N; ++i ) {
            while( H[stk.back()] >= H[i] )
                stk.pop_back();
            L[i] = stk.back();
            stk.push_back( i );
        }
        
        stk.clear();
        stk.push_back( N + 1 );
        for( int i = N; i > 0; --i ) {
            while( H[stk.back()] >= H[i] )
                stk.pop_back();
            R[i] = stk.back();
            stk.push_back( i );
        }
        
        long long mx = 0;
        
        for( int i = 1; i <= N; ++i )
            if( mx < H[i] * ( R[i] - L[i] - 1 ) )
                mx = H[i] * ( R[i] - L[i] - 1 );
                
        cout << mx << endl;
        
    }
    
}
