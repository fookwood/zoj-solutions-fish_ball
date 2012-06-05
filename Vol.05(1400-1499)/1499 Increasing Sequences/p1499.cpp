#include <iostream>
#include <string>
#include <deque>
using namespace std;

int     pre[81],    val[81];

string  digits;

int main() {
    
    while( cin >> digits && digits != "0" ) {
        
        memset( val, -1, sizeof( val ) );
        memset( pre, -1, sizeof( pre ) );
        
        val[0] = 0;
        
        for( int i = 1; i <= digits.size(); ++i ) {
            for( int j = 0; j < i; ++j ) {
                if( val[j] != -1 ) {
                    int now = atoi(digits.substr(j,i-j).c_str());
                    if( now > val[j] ) {
                        if( val[i] == -1 || val[i] > now ) {
                            val[i] = now;
                            pre[i] = j;
                        }
                        if( val[i] == now ) {
                            deque<int> p1( 0 ), p2( 0 );
                            int pos = i;
                            p1.push_front( now );
                            while( pos != 0 ) {
                                pos = pre[pos];
                                p1.push_front( val[pos] );
                            }
                            pos = j;
                            p2.push_front( now );
                            p2.push_front( val[j] );
                            while( pos != 0 ) {
                                pos = pre[pos];
                                p2.push_back( val[pos] );
                            }
                            if( p2 > p1 )   pre[i] = j;
                        }
                    }
                }
            }
        }
        
        int pos = digits.size();
        deque<string>   Q( 0 );
        while( pos != 0 ) {
            Q.push_front( digits.substr( pre[pos], pos - pre[pos] ) );
            pos = pre[pos];
        }
        
        cout << Q[0];
        for( int i = 1; i < Q.size(); ++i )
            cout << ',' << Q[i];
        puts( "" );
        
    }
    
}
