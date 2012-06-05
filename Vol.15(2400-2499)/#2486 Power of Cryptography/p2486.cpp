// 2941726 2008-06-04 15:54:44 Accepted 2486 C++ 00:00.00 844K 呆滞的慢板 

// 相当 ym，原来用 double 可以输入一个很长很长的数的 

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    double  x,  y;
    
    while( cin >> x >> y )
        cout << round( exp( log( y ) / x ) ) << endl;
    
}
