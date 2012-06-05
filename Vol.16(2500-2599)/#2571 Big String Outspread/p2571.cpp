// 2892637 2008-05-06 11:07:18 Accepted 2571 C++ 00:00.00 864K ´ôÖÍµÄÂý°å 

// ÓÃ×Ö·û´®µÝ¹é£¬±à³Ì±È½Ï·±Ëö 

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

string impact( char expr[], int len ) {

    if( len == 1 )  return  string( 1, *expr );
    if( len == 0 )  return  string( "" );

    string  ans( "" );

    for( int pos = 0; pos < len; ++pos ) {

        if( isalpha( expr[pos] ) ) {
            ans += expr[pos];
            continue;
        }

        if( expr[pos] == '(' ) {
            int para = 1, end = pos + 1;
            while( para ) {
                if( expr[end] == '(' )  ++para;
                if( expr[end] == ')' )  --para;
                ++end;
            }
            ans += impact( expr + pos + 1, end - pos - 2 );
            pos = end - 1;
            continue;
        }

        if( isdigit( expr[pos] ) ) {
            int  beg = pos, num = 0;
            while( isdigit( expr[beg] ) ) {
                num *= 10;
                num += ( expr[beg++] - '0' );
            }
            string  temp;
            int end = beg + 1;
            if( expr[beg] == '(' ) {
                int para = 1;
                while( para ) {
                    if( expr[end] == '(' )  ++para;
                    if( expr[end] == ')' )  --para;
                    ++end;
                }
                temp = impact( expr + beg + 1, end - beg - 2 );
            }
            else    temp = string( 1, expr[beg] );
            while( num-- )  ans += temp;
            pos = end - 1;
            continue;
        }

    }
    
    return  ans;
    
}

int main() {

    int T,  len;
    char    expr[255];
    cin >> T;
    
    while( T-- ) {
        
        cin >> expr;
        len = strlen( expr );
        cout << impact( expr, len ) << endl;
        
    }

}
