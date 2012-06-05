// 2893320 2008-05-06 16:13:46 Accepted 1737 C++ 00:00.01 840K 呆滞的慢板 

// 解密题，模拟即可，STL 用得超爽 

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

void inc( char& c ) {
    if( c == '9' )  c = '0';
    else if( isdigit( c ) ) ++c;
}

void dec( char& c ) {
    if( c == '0' )  c = '9';
    else if( isdigit( c ) ) --c;
}

int main() {
    
    int     T;
    cin >> T;
    string  seq,    msg;
    
    while( T-- ) {
        
        cin >> seq >> msg;
        
        for( int i = seq.size() - 1; i >= 0; --i ) {
            
            switch( seq[i] ) {
                
                case 'C':
                    rotate( msg.begin(),
                            msg.begin() + 1,
                            msg.end() );
                break;
                
                case 'J':
                    rotate( msg.begin(),
                            msg.end() - 1,
                            msg.end() );
                break;
                
                case 'E':
                    swap_ranges( msg.begin(),
                                 msg.begin() + msg.size() / 2,
                                 msg.end() - msg.size() / 2 );
                break;
                
                case 'A':
                    reverse( msg.begin(), msg.end() );
                break;
                
                case 'P':
                    for( int i = 0; i < msg.size(); ++i )
                        dec( msg[i] );
                break;
                
                case 'M':
                    for( int i = 0; i < msg.size(); ++i )
                        inc( msg[i] );
                break;
                
            }
            
        }
        
        cout << msg << endl;
        
    }
    
}
