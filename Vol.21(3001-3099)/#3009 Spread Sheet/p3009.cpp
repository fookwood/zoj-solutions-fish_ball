// 3007053 2008-07-26 19:16:07 Accepted 3009 C++ 00:00.78 5468K ´ôÖÍµÄÂý°å 

// ±äÌ¬Ä£Äâ£¬µÝ¹é + ¼ÇÒä 

#include <iostream>
#include <string>
using namespace std;

string  cell[200][702];

bool    ready[200][702];

int     val[200][702];

int     T,  M,  N;

void get_pos( string s, int& x, int& y ) {

    int pos = x = 0;
    
    while( isalpha( s[pos] ) )  pos++;
    
    for( int i = 0; i < pos; ++i ) {
        x *= 26;
        x += ( s[i] - 'A' + 1 );
    }
    
    --x;
    
    y = atoi( s.substr( pos ).c_str() ) - 1;
    
}

int parse( string s ) {
    
    if( s == "" )   return  0;
    
    s.erase( 0, 1 );
    
    string  t;
    
    int pos = s.find( '+' );
    
    if( pos == string::npos ) {
        t = s;
        s.erase();
    }
    else {
        t = s.substr( 0, pos );
        s.erase( 0, pos );
    }
    
    int x, y;
    
    get_pos( t, y, x );
    
    if( !ready[x][y] ) {
        ready[x][y] = true;
        val[x][y] = parse( cell[x][y] );
    }
    
    return  val[x][y] + parse( s );
    
}

int main() {    
    
    for( cin >> T; T--; ) {
        
        cin >> M >> N;
        
        memset( ready, 0, sizeof( ready ) );
        
        for( int i = 0; i < N; ++i ) {
            for( int j = 0; j < M; ++j ) {
                cin >> cell[i][j];
                if( cell[i][j][0] != '=' ) {
                    val[i][j] = atoi( cell[i][j].c_str() );
                    ready[i][j] = true;
                }
            }
        }
        
        for( int i = 0; i < N; ++i ) {
            for( int j = 0; j < M; ++j ) {
                if( !ready[i][j] ) {
                    ready[i][j] = true;
                    val[i][j] = parse( cell[i][j] );
                }
                cout << val[i][j];
                if( j + 1 < M ) putchar( ' ' );
            }
            puts( "" );
        }
        
        puts( "" );
        
    }
    
}
