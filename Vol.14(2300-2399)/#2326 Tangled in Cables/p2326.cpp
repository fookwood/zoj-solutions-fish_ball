// MST, Kruscal
// 对精度问题要有发神经般的敏感！！
// 2824818 2008-04-05 16:18:34 Accepted 2326 C++ 00:00.02 860K 呆滞的慢板 

#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

class Edge {
    int     X,  Y;
    double  LEN;
public:
    double getLen() { return LEN; }
    void getNode( int& XX, int& YY )
        { XX = X; YY = Y; }
    void setVal( int XX, int YY, double L )
        { X = XX;   Y = YY;   LEN = L; }
    friend bool operator < ( const Edge& e1, const Edge& e2 )
        { return e1.LEN < e2.LEN; }
};

int main() {
    double  total;
    int     V,  E;
    cin >> total;
    cin >> V;
    vector<int> vertex( V );
    vector<string>  name( V );
    for( int v = 0; v < V; v++ ) {
        vertex.at( v ) = v;
        cin >> name.at( v );
    }
    cin >> E;
    vector<Edge> edge( E );
    for( int e = 0; e < E; e++ ) {
        string  s1, s2;
        int     x = 0,  y = 0;
        double  val;
        cin >> s1 >> s2 >> val;
        while( name.at( x ) != s1 ) x++;
        while( name.at( y ) != s2 ) y++;
        edge.at( e ).setVal( x, y, val );
    }
    sort( edge.begin(), edge.end() );
    double  sum = 0.0;
    int     count = 0;
    for( int e = 0; e < E; e++ ) {
        int     p1, p2;
        edge.at( e ).getNode( p1, p2 );
        int     p3 = p2;
        while( vertex.at( p1 ) != p1 )
            p1 = vertex.at( p1 );
        while( vertex.at( p2 ) != p2 )
            p2 = vertex.at( p2 );
        if( p1 == p2 )
            continue;
        vertex.at( p2 ) = p1;
        while( vertex.at( p3 ) != p3 ) {
            p2 = p3;
            p3 = vertex.at( p3 );
            vertex.at( p2 ) = p1;
        }
        sum += edge.at( e ).getLen();
        count++;
        if( count == V - 1 )
            break;
    }
    cout.setf( ios :: fixed );
    cout.precision( 1 );
    if( total < sum || fabs( total - sum ) < 1e-5 )
        cout << "Not enough cable" << endl;
    else
        cout << "Need " 
             << round( sum * 10.0 ) / 10.0 + 1e-5
             << " miles of cable" << endl;
}
