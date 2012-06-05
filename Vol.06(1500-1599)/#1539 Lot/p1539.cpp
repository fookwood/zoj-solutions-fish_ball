// 直接递归搞就行了
// 由于只要求 3 人队的种数
// 而每次分离都是独立的，因此有
// F(N) -> F(N/2), F((N+1)/2) 
// 2844731 2008-04-15 10:23:37 Accepted 1539 C++ 00:00.33 836K 呆滞的慢板 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int     count;

void gao( const int& N ) {
    if( N == 3 ) count++;
    if( N <= 3 ) return;
    gao( N / 2 );
    gao( ( N + 1 ) / 2 );
}

int main() {
    int     N;
    while( cin >> N ) {
        count = 0;
        gao( N );
        cout << count << endl;
    }
}
