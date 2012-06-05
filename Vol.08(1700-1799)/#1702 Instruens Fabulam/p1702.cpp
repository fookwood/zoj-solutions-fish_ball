// 2956874 2008-06-26 20:23:48 Accepted 1702 C++ 00:00.00 860K 呆滞的慢板 

// 模拟题，要用动态数组，有点烦

// 注意要先统计出来字段的最长长度之后才可以开始制表 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline bool isFormat( char x ) {
    return  x == '<' || x == '>' ||
            x == '=' || x == '*';
}

void disp( string s, int len, char type ) {
    
    switch( type ) {
        
        case '<':
            cout << ' ' << s 
                 << string( len - s.size() + 1, ' ' )
                 << '|';
        break;
        
        case '>':
            cout << string( len - s.size() + 1, ' ' )
                 << s << " |";
        break;
                 
        case '=':
            cout << string( ( len - s.size() ) / 2, ' ' )
                 << ' ' << s
                 << string( ( len - s.size() + 1 ) / 2, ' ' )
                 << " |";
        break;
    
    }
    
}

int main() {
    
    string  input;
    getline( cin, input );
    
    while( input[0] != '*' ) {
        
        string  format = input;
        int     D = input.length();
        vector<vector<string> > V;
        vector<int>     L( D, 0 );
        V.resize( 0 );
        
        while( getline( cin, input ) ) {
            
            if( isFormat( input[0] ) )  break;
            V.resize( V.size() + 1 );
            
            for( int i = 0; i < D; ++i ) {
                int pos = input.find( '&' );
                if( pos == string::npos )
                    V.back().push_back( input );
                else {
                    V.back().push_back( input.substr( 0, pos ) );
                    input.erase( 0, pos + 1 );
                }
                if( L[i] < V.back()[i].length() )
                    L[i] = V.back()[i].length();
            }
            
            
        }
        
            putchar( '@' );
            for( int i = 0; i < D; ++i ) {
                if( !i )
                    cout << string( L[i] + 2, '-' );
                else
                    cout << string( L[i] + 3, '-' );
            }
            puts( "@" );
            
            putchar( '|' );
            for( int i = 0; i < D; ++i )
                disp( V[0][i], L[i], format[i] );
            putchar( '\n' );
            
            putchar( '|' );
            for( int i = 0; i < D; ++i ) {
                if( i ) putchar( '+' );
                cout << string( L[i] + 2, '-' );
            }
            puts( "|" );
            
            for( int i = 1; i < V.size(); ++i ) {
                putchar( '|' );
                for( int j = 0; j < D; ++j )
                    disp( V[i][j], L[j], format[j] );
                putchar( '\n' );
            }

            putchar( '@' );
            for( int i = 0; i < D; ++i ) {
                if( !i )
                    cout << string( L[i] + 2, '-' );
                else
                    cout << string( L[i] + 3, '-' );
            }
            puts( "@" );
        
    }
    
    
}
