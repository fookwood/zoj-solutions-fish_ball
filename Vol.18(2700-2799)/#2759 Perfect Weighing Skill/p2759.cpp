// 2938304 2008-05-31 16:08:51 Accepted 2759 C++ 00:00.94 844K 呆滞的慢板 

// 精彩的数制转换，三进制，看解题报告 

#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    int         V[30];
    long long   B[20];
    int     N,  L,  P;
    
    B[0] = 1;
    for( int i = 1; i < 20; ++i )
        B[i] = B[i - 1] * 3;
    
    while( cin >> N ) {
        
        P = L = 1;
        
        while( P > 0 && P <= N ) {
            ++L;
            P *= 3;
        }
        
        memset( V, 0, sizeof( V ) );
        
        for( int i = 0; i < L; ++i ) {
            V[i] = N % 3;
            N /= 3;
        }
/*
        for( int i = 0; i < L; ++i )
            cout << V[i] << ' ';
        cout << endl;
*/
        vector<long long>   X,  Y;
        
        for( int i = 0; i + 1 < L; ++i ) {
            if( V[i] == 2 ) {
                X.push_back( B[i] );
                V[i] = 0;
                int j = i + 1;
                while( V[j] == 2 ) {
                    V[j] = 0;
                    ++j;
                }
                ++V[j];
            }
        }
        
        for( int i = 0; i < L; ++i )
            if( V[i] == 1 )
                Y.push_back( B[i] );
        
        if( X.size() == 0 )
            cout << -1 << endl;
        else {
            cout << X[0];
            for( int i = 1; i < X.size(); ++i )
                cout << ' ' << X[i];
            cout << endl;
        }
        
        cout << Y[0];
        for( int i = 1; i < Y.size(); ++i )
            cout << ' ' << Y[i];
        cout << endl << endl;
        
    }
    
}
