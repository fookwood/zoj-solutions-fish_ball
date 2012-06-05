#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int>    val;

bool P[256] = { false };

void init_map() {
    
    val["one"]      = 1;    val["two"]      = 2;    val["three"]    = 3;
    val["four"]     = 4;    val["five"]     = 5;    val["six"]      = 6;
    val["seven"]    = 7;    val["eight"]    = 8;    val["nine"]     = 9;
    val["ten"]      = 10;   val["eleven"]   = 11;   val["twelve"]   = 12;
    val["thirteen"] = 13;   val["fourteen"] = 14;   val["fifteen"]  = 15;
    val["sixteen"]  = 16;   val["seventeen"]= 17;   val["eighteen"] = 18;
    val["nineteen"] = 19;   val["twenty"]   = 20;   val["thirty"]   = 30;
    val["forty"]    = 40;   val["fifty"]    = 50;   val["sixty"]    = 60;
    val["seventy"]  = 70;   val["eighty"]   = 80;   val["ninety"]   = 90;
    val["zero"]     = 0;

    P['('] = P[')'] = P[','] =
    P['.'] = P['!'] = P[':'] =
    P['?'] = P[';'] = true;

}

int main() {
        
    init_map();
    
    string  input;
    
    while( getline( cin, input ) ) {
        
        if( input == "" ) {
            putchar( '\n' );
            continue;
        }
                
        int     num( 0 );
        int     grade( 0 );
        bool    keep( false );
        string  word( "" );
        
        for( int pos = 0; pos < input.size(); ++pos ) {
            
            if( input[pos] == ' ' || input[pos] == '\t' ) {
                
                if( !keep )
                    putchar( input[pos] );
                
            }
            
            else if( P[input[pos]] ) {
                
                putchar( input[pos] );
            }
        
        }
        
        puts( "" );
        
    }
    
    
}
