// 崩溃了，就这破题居然害我无数 WA
// 原因就是，结束数字是任意一个负整数，而不是 -1
// 不能怪他阴险，怪自己没看好 

#include <iostream>
using namespace std;

int main() {
    int N,  A[12];
    A[0] = A[1] = 1;
    for( int i = 1; i < 12; i++ )
        A[i + 1] = ( i + 1 ) * A[i];
    while( ( cin >> N ) && N >= 0 ) {
        if( !N ) {
            cout << "NO" << endl;
            continue;
        }
        for( int i = 11; i >= 0; i-- )
            if( N >= A[i] )
                N -= A[i];
        if( N ) cout << "NO" << endl;
        else    cout << "YES" << endl;
    }
}
