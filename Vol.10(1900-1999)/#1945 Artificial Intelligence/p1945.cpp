// 3016073 2008-08-01 01:27:23 Accepted 1945 C++ 00:00.00 876K 呆滞的慢板 

// 有官方数据，如果有什么 trouble 的话看看数据就知道了，有个地方很 WS 

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    int T;
    
    cin >> T;
    
    string  input;
    
    vector<string>  V;
    
    getline( cin, input );
    
    double  x,  y;

    for( int t = 1; t <= T; ++t ) {
        
        printf( "Problem #%d\n", t );
        
        getline( cin, input );
        
        istringstream   is( input );
        
        V.clear();
        
        while( is >> input ) {
            if( input.find( '=' ) != string::npos )
                V.push_back( input );
        }
        
        sort( V.begin(), V.end() );
     
        input = V[0].substr( V[0].find( '=' ) + 1 );
        sscanf( input.c_str(), "%lf", &x );
        if( input.find( 'k' ) != string::npos )  x *= 1e3;
        if( input.find( 'M' ) != string::npos )  x *= 1e6;
        if( input.find( 'm' ) != string::npos )  x /= 1e3;
        
        input = V[1].substr( V[1].find( '=' ) + 1 );
        sscanf( input.c_str(), "%lf", &y );
        if( input.find( 'k' ) != string::npos )  y *= 1e3;
        if( input.find( 'M' ) != string::npos )  y *= 1e6;
        if( input.find( 'm' ) != string::npos )  y /= 1e3;
        
        if( V[0][0] == 'I' && V[1][0] == 'P' )
            printf( "U=%.2lfV\n", y / x );
        if( V[0][0] == 'I' && V[1][0] == 'U' )
            printf( "P=%.2lfW\n", y * x );
        if( V[0][0] == 'P' && V[1][0] == 'U' )
            printf( "I=%.2lfA\n", x / y );
        
        puts( "" );
        
    }

}
