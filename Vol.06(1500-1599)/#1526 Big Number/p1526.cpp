// 求阶乘的位数，对阶乘取 log10，可以变成 log10 的和，然后就显而易见了。

// double 在这种时候用得很爽
// 不过过得好慢 *_*
// 2812284 2008-03-30 20:44:03 Accepted 1526 C++ 00:05.14 848K 呆滞的慢板  

#include <iostream>
#include <cmath>
using namespace std;

struct Factorial {
    Factorial() {}
    Factorial( double xx, double d ) :
        x(xx), digit(d) {}
    double  x;
    double  digit;
    void increase( const int& n );
};

void Factorial :: increase( const int& n ) {
    x *= double( n );
    double  d = floor( log10( x ) );
    x /= pow( 10.0, d );
    digit += d;
}

int main() {
    int     T,  N;
    Factorial   num;
    cin >> T;
    cout.setf( ios :: fixed );
    cout.precision( 0 );
    while( T-- ) {
        cin >> N;
        num = Factorial( 1.0, 1.0 );
        for( int i = 1; i <= N; i++ )
            num.increase( i );
        cout << round( num.digit ) << endl;
    }
}
