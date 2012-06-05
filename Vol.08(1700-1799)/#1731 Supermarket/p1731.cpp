// 2995835 2008-07-22 11:11:09 Accepted 1731 C++ 00:00.12 1160K 呆滞的慢板 

// N 个商品，每个价格为 p，保质期为 d
// 每天只能卖一个，问怎么安排，使得总收益最大，输出总收益 

// 用贪心做，先按价格排序，价格相等选时间大的 
// 然后按照从大到小枚举，标记哪几天没用过 
// 从没用过的各日期里面选取出比当前商品保质期小的当中最大的 
// 删除该天，并且总价格加上当前商品的价格

// 所有没用过的日期用一个 set 来维护，相当快 

#include <iostream>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

pair<int, int>  V[10001];

int     N;

set<int>            S;
set<int>::iterator  iter;

int main() {
    
    while( scanf( "%d", &N ) != EOF ) {
    
        int mx = 0;
        
        for( int i = 0; i < N; ++i ) {
            scanf( "%d%d", &V[i].first, &V[i].second );
            if( V[i].second > mx )
                mx = V[i].second;
        }
        
        S.clear();
        for( int i = 1; i <= mx; ++i )
            S.insert( S.end(), i );
        
        sort( V, V + N );
        
        int cnt = 0;
        
        for( int i = N - 1; i >= 0; --i ) {
            if( S.empty() ) break;
            if( *S.begin() > V[i].second ) continue;
            cnt += V[i].first;
            iter = S.upper_bound( V[i].second );
            --iter;
            S.erase( iter );
        }
        
        printf( "%d\n", cnt );
    
    }
    
}
