// 2896474 2008-05-07 18:42:08 Accepted 2132 C++ 00:01.56 840K ´ôÖÍµÄÂý°å 
// ÓÃ map µÄµä·¶£¬³¬Ë¬... 

#include <cstdio>
#include <map>
using namespace std;

int main() {

    int     L,  N;
    int     now_count, max_val, max_count;
    map<int, int> M;

    while( scanf( "%d", &L ) != EOF ) {

        M.clear();
        max_count = 0;
    
        for( int i = 0; i < L; ++i ) {
            scanf( "%d", &N );
            now_count = ++M[N];
            if( now_count > max_count ) {
                max_count = now_count;
                max_val = N;
            }
        }
        
        printf( "%d\n", max_val );
    
    }

}
