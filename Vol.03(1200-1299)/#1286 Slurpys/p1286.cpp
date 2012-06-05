// 2905255 2008-05-11 00:06:28 Accepted 1286 C++ 00:00.00 840K 呆滞的慢板 

// 模拟题，不是难题，先从尾部剪掉一个最长的 slump，
// 然后检查前面的是不是一个 slimp，注意逻辑的等价性和完全性即可 

#include <iostream>
#include <string>
using namespace std;

int     T,  N;
string  str;
    
bool isSlump( const int& pos ) {
    for( int i = pos + 1; i < N - 1; i += 2 ) {
        while( str[i] == 'F' )  ++i;
        if( i == N - 1 )    return  true;
        if( str[i] != 'D' && str[i] != 'E' ||
            i == N - 2 )    return  false;
    }
    return  true;
}

int main() {
    
    puts( "SLURPYS OUTPUT" );
    
    for( cin >> T; T--; ) {
        
        cin >> str;
        N = str.size();
        
        if( str[0] != 'A' || str[N-1] != 'G' ) {
            puts( "NO" );
            continue;
        }
        
        int     pos = 0;
        for( pos = 0; pos < N; ++pos ) {
            if( ( str[pos] == 'D' || str[pos] == 'E' ) &&
                  isSlump( pos ) )
                break;
        }
        
        str.erase( pos );
        N = pos;
        
        bool    yes = true;
        
        while( str.size() ) {

            if( str == "AH" )   break;

            if( str[0] != 'A' || str[N-1] != 'C' || N <= 3 ) {    
                yes = false;
                break;
            }
            
            if( str[1] == 'B' ) {
                str.erase( N - 1 );
                str.erase( 0, 2 );
                N -= 3;
                continue;
            }
            
            else {
                str.erase( N - 1 );
                str.erase( 0, 1 );
                N -= 2;
                yes = isSlump( 0 );
                break;
            }
            
        }
        
        puts( yes ? "YES" : "NO" );
    }
    
    puts( "END OF OUTPUT" );
    
}
