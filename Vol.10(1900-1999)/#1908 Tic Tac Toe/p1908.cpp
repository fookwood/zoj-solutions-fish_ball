// 3014337 2008-07-30 18:19:18 Accepted 1908 C++ 00:00.00 840K 呆滞的慢板 

// 井字过三关，弱智题

// 4 个判据：
// 1. X == O || X == O + 1
// 2. X 和 O 不能同时有连 
// 3. X 有连的时候，X == O + 1
// 4. O 有连的时候，X == O 

#include <iostream>
using namespace std; 

int     N; 

char    C[3][4]; 

int connect( char c ) {
    int ans = 0; 
    for( int i = 0; i < 3; ++i ) { 
        if( C[0][i] == c && C[1][i] == c && C[2][i] == c ) ++ans; 
        if( C[i][0] == c && C[i][1] == c && C[i][2] == c ) ++ans; 
    } 
    if( C[0][0] == c && C[1][1] == c && C[2][2] == c ) ++ans; 
    if( C[0][2] == c && C[1][1] == c && C[2][0] == c ) ++ans;
    return  ans; 
} 

int cnt( char c ) {
    int ans = 0;
    for( int i = 0; i < 3; ++i )
        for( int j = 0; j < 3; ++j ) 
            ans += ( C[i][j] == c );
    return  ans; 
} 


int main() { 

    for( cin >> N; N--; ) {
        
        cin >> C[0] >> C[1] >> C[2];
        
        if( connect( 'O' ) && connect( 'X' ) ) {
            puts( "no" );
            continue; 
        }
        
        if( connect( 'O' ) && cnt( 'O' ) != cnt( 'X' ) ) {
            puts( "no" );
            continue; 
        }     
            
        if( connect( 'X' ) && cnt( 'O' ) + 1 != cnt( 'X' ) ) {
            puts( "no" );
            continue; 
        } 
        
        if( cnt( 'O' ) > cnt( 'X' ) ||
            cnt( 'O' ) + 1 < cnt( 'X' ) ) {
            puts( "no" );
            continue; 
        } 
        
        puts( "yes" );
        
    } 
    
} 
