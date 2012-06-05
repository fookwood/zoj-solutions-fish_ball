// map Ì× map µÄ°æ±¾£¬TLE 

#include <iostream>
#include <map>
using namespace std;

char input[50];

int x,  y,  z,  t;

map<int, map<int, int>* > MP;
map<int, map<int, int>* >::iterator out_iter;
map<int, int>::iterator in_iter;

int main() {
    
    while( ( *input = getchar() ) != EOF ) {
        
        getchar();
        
        for( out_iter = MP.begin(); out_iter != MP.end(); ++out_iter )
            delete  out_iter->second;

        MP.clear();

        while( *input != 'E' ) {
            
            if( *input == 'I' ) while( 1 ) {
                gets( input );
                if( isalpha( *input ) ) break;
                sscanf( input, "%d%d%d", &x, &y, &z );
                if( MP.find( x ) == MP.end() )
                        (*(MP[x] = new map<int, int>))[y] += z;
                else    (*MP[x])[y] += z;
            }
        
            else while( 1 ) {
                gets( input );
                if( isalpha( *input ) ) break;
                int ans = 0;
                sscanf( input, "%d%d%d%d", &x, &y, &z, &t );
                for( out_iter = MP.lower_bound( x );
                        out_iter != MP.end() && out_iter->first <= y;
                        ++out_iter ) {
                    for( in_iter = out_iter->second->lower_bound( z );
                            in_iter != out_iter->second->end() && in_iter->first <= t;
                            ++in_iter ) {
                        ans += in_iter->second;
                    }
                }
                printf( "%d\n", ans );
            }
        
        }
    
    }
    
}
