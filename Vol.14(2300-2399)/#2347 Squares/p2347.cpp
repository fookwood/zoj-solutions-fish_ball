// 2992254 2008-07-20 20:50:15 Accepted 2347 C++ 00:03.31 852K 呆滞的慢板 

// 对所有点进行排序，枚举两个点，生成另外两个点二分查找

// 注意有序性的问题，查找后两个点必须大于前两个点，否则会计重 

#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> Point;

Point   P[1000];

Point operator + ( Point p1, Point p2 ) {
    return  make_pair( p1.first + p2.first, p1.second + p2.second );
}

Point operator - ( Point p1, Point p2 ) {
    return  make_pair( p1.first - p2.first, p1.second - p2.second );
}

Point operator - ( Point p1 ) {
    return  make_pair( -p1.first, -p1.second );
}

inline void rot( Point& p ) {
    swap( p.first, p.second );
    if( p.first >= 0 )
            p.second = -p.second;
    else    p.first = -p.first;
}

int main() {
    
    int     T,  N;
    
    for( scanf( "%d", &T ); T--; ) {
    
        while( scanf( "%d", &N ) && N ) {
        
            for( int i = 0; i < N; ++i )
                scanf( "%d%d", &P[i].first, &P[i].second );
                
            int cnt = 0;
            
            sort( P, P + N );
                
            for( int i = 1; i < N; ++i ) {
                for( int j = 0; j < i; ++j ) {
                    
                    Point   p = P[i] - P[j];
                    
                    rot( p );
                    
                    if( binary_search( P + i + 1, P + N, P[i] + p ) &&
                        binary_search( P + i + 1, P + N, P[j] + p ) )
                        ++cnt;

                }
            }
            
            printf( "%d\n", cnt );
            
        }
        
        if( T ) puts( "" );
    
    }
    
}
