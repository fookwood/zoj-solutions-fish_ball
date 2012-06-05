// 2996150 2008-07-22 13:39:42 Accepted 1731 C++ 00:00.12 560K 呆滞的慢板 

// 所有没用过的日期用一个类似于并查集的结构来维护，具有更高的效率

// 貌似没什么改进，关键下界在于排序 

#include <cstdio>
#include <algorithm>
using namespace std;

pair<int, int>  V[10001];

int     N;

int U[10001],   rem;

int find_set( int x ) {
    if( U[x] == x ) return  x;
    return  U[x] = find_set( U[x] );
}

int main() {
    
    while( scanf( "%d", &N ) != EOF ) {
    
        int mx = 0;
        
        for( int i = 0; i < N; ++i ) {
            scanf( "%d%d", &V[i].first, &V[i].second );
            if( V[i].second > mx )
                mx = V[i].second;
        }
        
        rem = mx;
        
        for( int i = 0; i <= mx; ++i )  U[i] = i;
        
        sort( V, V + N );
        
        int cnt = 0,    pos;
        
        for( int i = N - 1; i >= 0; --i ) {
            if( rem == 0 ) break;
            pos = find_set( V[i].second );
            if( !pos ) continue;
            cnt += V[i].first;
            U[pos] = pos - 1;
        }
        
        printf( "%d\n", cnt );
    
    }
    
}
