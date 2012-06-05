// 简单的几何问题，由于规模极小，所以随便搞搞枚举就行了 
// 这个完全可以不用浮点的，那就不要用了，免得精度问题
// 2889960 2008-05-05 01:06:05 Accepted 1704 C++ 00:00.00 840K 呆滞的慢板  

#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

struct Point {
    
    int     x,  y;
    char    label;

    bool inside( const Point& A,
                 const Point& B,
                 const Point& C ) {
        int p1 = ( A.x - B.x ) * ( y - B.y ) -
                 ( A.y - B.y ) * ( x - B.x );
        int p2 = ( B.x - C.x ) * ( y - C.y ) -
                 ( B.y - C.y ) * ( x - C.x );
        int p3 = ( C.x - A.x ) * ( y - A.y ) -
                 ( C.y - A.y ) * ( x - A.x );
        return  p1 >= 0 && p2 >= 0 && p3 >= 0 ||
                p1 <= 0 && p2 <= 0 && p3 <= 0;
    }

};

int area( const Point& p1,
          const Point& p2,
          const Point& p3 ) {
    return  abs( ( p3.y - p1.y ) * ( p2.x - p1.x ) -
                 ( p2.y - p1.y ) * ( p3.x - p1.x ) );
}

int main() {
    
    int     N,  Area;
    Point   P[15];
    char    T[4] = "???";
    
    while( ( cin >> N ) && N ) {
        
        for( int i = 0; i < N; ++i )
            cin >> P[i].label >> P[i].x >> P[i].y;
        
        Area = 0;
        for( int i = 2; i < N; ++i ) {
            
            for( int j = 1; j < i; ++j ) {
                
                for( int k = 0; k < j; ++k ) {
                    
                    int now = area( P[k], P[j], P[i] );
                    
                    if( now <= Area )
                        continue;
                        
                    bool valid = true;
                    
                    for( int t = 0; t < N; ++t ) {
                        
                        if( t == i || t == j || t == k )
                            continue;
                            
                        if( P[t].inside( P[i], P[j], P[k] ) ) {
                            valid = false;
                            break;
                        }
                        
                    }
                    
                    if( valid && now > Area ) {
                        Area = now;
                        T[0] = P[k].label;
                        T[1] = P[j].label;
                        T[2] = P[i].label;
                    }
                    
                }
                
            }
            
        }
        
        sort( T, T + 3 );
        
        cout << T << endl;
        
    }
    
} 
