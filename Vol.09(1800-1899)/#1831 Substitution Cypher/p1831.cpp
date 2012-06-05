// 超简单，注意输入中止条件就行
// 2862975 2008-04-23 13:49:39 Accepted 1831 C++ 00:00.01 844K 呆滞的慢板  
#include <string>
#include <iostream>
using namespace std;

int main() {
    char    C[256] = { 0 };
    string  X,  Y;
    getline( cin, X );
    getline( cin, Y );
    puts( Y.c_str() );
    puts( X.c_str() );
    for( int i = 0; i < X.size(); ++i )
        C[X[i]] = Y[i];
    while( getline( cin, X ) ) {
        for( int i = 0; i < X.size(); ++i )
            if( C[X[i]] )   putchar( C[X[i]] );
            else            putchar( X[i] );
        putchar( '\n' );
    }
}
