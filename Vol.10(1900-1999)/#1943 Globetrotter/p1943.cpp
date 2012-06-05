// 3016023 2008-08-01 00:21:45 Accepted 1943 C++ 00:00.01 852K 呆滞的慢板 

// 求两点间球面距，直接转三维直角坐标两点距，代入大圆弦转弧
// 字符串 map 就好了 

#include <cmath>
#include <iostream>
#include <map>
#include <string> 
using namespace std;

const double PI = acos( -1.0 );
const double R = 6378.0; 

struct Point {
    double  x,  y,  z;
    Point( double p1 = 0, double p2 = 0 ) {
        x = R * cos( p1 / 180.0 * PI ) * cos( p2 / 180.0 * PI );
        y = R * cos( p1 / 180.0 * PI ) * sin( p2 / 180.0 * PI );
        z = R * sin( p1 / 180.0 * PI ); 
    }
}; 

double dist( Point a, Point b ) {
    double x = a.x-b.x, y = a.y-b.y, z = a.z-b.z;
    return R * asin( sqrt( x*x + y*y + z*z ) / 2.0 / R ) * 2.0;
} 

map<string, Point >  M;
map<string, Point >::iterator   iter1,  iter2;

int main() {
    
    string  s1, s2;
    
    double  lati,   longi;   
    
    while( cin >> s1 && s1 != "#" ) {
        cin >> lati >> longi;
        M[s1] = Point( lati, longi ); 
    } 
    
    while( cin >> s1 >> s2 && s2 != "#" ) {
        iter1 = M.find( s1 );
        iter2 = M.find( s2 );
        cout << s1 << " - " << s2 << endl;
        if( iter1 == M.end() || iter2 == M.end() )
            puts( "Unknown" );
        else 
            cout << round( dist( iter1->second, iter2->second ) )
                 << " km\n";
    } 
    
} 
