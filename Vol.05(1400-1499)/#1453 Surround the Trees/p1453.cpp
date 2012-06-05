// 3012524 2008-07-29 16:35:49 Accepted 1453 C++ 00:00.42 860K 呆滞的慢板 

// 凸包问题，Graham 扫描法 
// 见算法导论中文版 p585 
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


struct Point {

    int x,  y;

    Point() {}
    
    Point( const int& x, const int& y ) :
        x( x ), y( y ) {}

    void getPoint() { cin >> x >> y; }

};

Point p0;

bool icmp( const Point& p1, const Point& p2 ) {
    return  ( p1.x - p0.x ) * ( p2.y - p0.y ) -
            ( p2.x - p0.x ) * ( p1.y - p0.y ) > 0;
}

double wrap( const double& p ) {
    return  round( p * 100.0 ) / 100.0 + 1e-10;
}

double dist( const Point& p1, const Point& p2 ) {
    return  hypot( p1.x - p2.x, p1.y - p2.y );
}


int main() {
    
    int     N;
    vector<Point>   V,  S;
    
    cout.setf( ios::fixed );
    cout.precision( 2 );
    
    while( ( cin >> N ) && N ) {

        V.resize( N );
        S.clear();
        for_each( V.begin(), V.end(),
            mem_fun_ref( &Point::getPoint ) );

        if( N == 1 ) { puts( "0.00" ); continue; }
        if( N == 2 ) { cout << wrap( dist( V[0], V[1] ) * 2.0 ) << endl; continue; }

        int min_pos = 0;

        for( int i = 1; i < N; i++ ) {
            if( V[i].y <  V[min_pos].y ||
                V[i].y == V[min_pos].y &&
                V[i].x <  V[min_pos].x )
                min_pos = i;
        }

        swap( V[0], V[min_pos] );
        
        p0 = V[0];
        sort( V.begin() + 1, V.end(), icmp );

        S.push_back( V[0] );
        S.push_back( V[1] );
        S.push_back( V[2] );
        
        for( int i = 3; i < N; i++ ) {
            while( 1 ) {
                p0 = *( S.end() - 2 );
                if( icmp( S.back(), V[i] ) )
                    break;
                else    S.pop_back();
            } 
            S.push_back( V[i] );
        }

        double ans = dist( S.back(), S.front() );
        for( int i = 1; i < S.size(); i++ )
            ans += dist( S[i - 1], S[i] );

        cout << wrap( ans ) << endl;
        
    }
    
}
