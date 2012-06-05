// 迭代改进算法，很有点贪心的意思。
// WA, Hang on..

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Eps {
    double  val;
    int     index;
public:
    int getIndex() { return  index; }
    void setVal( double v, int i )
        { val = v; index = i; }
    friend bool operator < ( const Eps& e1, const Eps& e2 )
        { return  e1.val < e2.val; }
};

int main() {
    int     T;
    cin >> T;
    while( T-- ) {
        int     N,  M,  Y;
        cin >> N >> M >> Y;
        vector<int> K( N );
        vector<int> X( N );
        vector<Eps> E( N );
        int     sum = M;
        for( int i = 0; i < N; i++ ) {
            cin >> K.at( i );
            X.at( i ) = M * K.at( i ) / Y;
            double eps1 = double( K.at( i ) ) / double( M ) -
                          double( X.at( i ) ) / double( Y ); 
            double eps2 = double( X.at( i ) + 1 ) / double( Y ) - 
                          double( K.at( i ) ) / double( M );
            E.at( i ).setVal( eps2 - eps1, i );
            sum -= X.at( i );
        }
        sort( E.begin(), E.end() );
        for( int i = 0; i < sum; i++ )
            X.at( E.at( i ).getIndex() )++;
        cout << X.at( 0 );
        for( int i = 1; i < N; i++ )
            cout << ' ' << X.at( i );
        cout << endl;
        if( T ) cout << endl;
    }
}
