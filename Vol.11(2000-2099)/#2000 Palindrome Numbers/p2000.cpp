// 掌握整数与字符串的转换方法
// 旧版的 itoa 和 atoi 并不见得好用
// 更好的选择是使用字符串流 
// 2823677 2008-04-05 00:18:28 Accepted 2000 C++ 00:00.01 876K 呆滞的慢板 

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long xLong;

string toString( const xLong& num ) {
    ostringstream   os;
    os << num;
    return  string( os.str() );
}

int main() {
    xLong   N;
    xLong   A[20] = { 0, 9, 9 };
    xLong   B[20] = { 0, 9, 18 };
    xLong   C[20] = { 1, 1, 10 };
    for( int i = 3; i < 20; i++ ) {
        A[i] = A[i - 2] * 10;
        B[i] = B[i - 1] + A[i];
        C[i] = C[i - 2] * 10;
    }
    while( ( cin >> N ) && N ) {
        int     pos;
        for( pos = 0; B[pos] < N; pos++ );
        int     M = N - B[pos - 1] + C[pos - 1] - 1;
        string  s1 = toString( M );
        string  s2( s1 );
        reverse( s2.begin(), s2.end() );
        if( pos % 2 )   s2.erase( 0, 1 );
        cout << s1 + s2 << endl;
    }
}
