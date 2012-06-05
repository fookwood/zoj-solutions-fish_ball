// 2893409 2008-05-06 16:43:39 Accepted 2734 C++ 00:00.00 836K 呆滞的慢板 

// 规模极小的搜索，一搞即过 

#include <vector>
#include <iostream>
using namespace std;

int     val[10], num[10],   N,  T = 0;
int     total,   cnt; 

void DFS( const int& i ) {
    
    if( total == 0 )  cnt++;
    if( total <= 0 )  return;
    if( i == N )      return;
    
    if( num[i] ) {
        total -= val[i];
        --num[i];
        DFS( i );
        ++num[i];
        total += val[i];
    }
    
    DFS( i + 1 );
    
}

int main() {
    
    while( cin >> total >> N ) {
        
        if( T++ )   putchar( '\n' );
        
        for( int i = 0; i < N; ++i )
            cin >> val[i] >> num[i];
            
        cnt = 0;
        DFS( 0 );
        
        cout << cnt << endl;
        
    }
    
}
