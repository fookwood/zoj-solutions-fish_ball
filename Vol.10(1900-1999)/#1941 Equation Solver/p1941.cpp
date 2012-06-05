// 3014979 2008-07-31 09:58:07 Accepted 1941 C++ 00:00.01 844K 呆滞的慢板 

// 中缀表达式处理，栈操作 

#include <string>
#include <vector> 
#include <iostream>
#include <algorithm>
using namespace std; 

struct Num {
    int     re,  im;
    Num( int r = 0, int i = 0 ) : 
        re( r ), im( i ) {}
};

class Op {
    char type;
public:
    Op( char c ) : type( c ) {}
    Num operator() ( Num a, Num b ) {
        if( type == '*' && b.im )  swap( a, b );
        switch( type ) {
            case '*': a.re *= b.re; a.im *= b.re; break;
            case '+': a.re += b.re; a.im += b.im; break;
            case '-': a.re -= b.re; a.im -= b.im; break;
        }
        return  a;
    }
};

Num parse( string input ) {
    vector<char>    OP;
    vector<Num>     V;
    string          temp;
    input = '(' + input + ')';
    for( int pos = 0; pos < input.size(); ) {
        if( input[pos] == '(' ||
            input[pos] == '+' ||
            input[pos] == '-' ||
            input[pos] == '*' ) {
            OP.push_back( input[pos++] );
        }
        else if( input[pos] == 'x' ) {
            V.push_back( Num( 0, 1 ) );
            while( OP.size() && OP.back() == '*' ) {
                Num a = V.back();  V.pop_back();
                Num b = V.back();  V.pop_back();
                V.push_back( Op( '*' )( a, b ) );
                OP.pop_back();
            }
            ++pos;
        }
        else if( isdigit( input[pos] ) ) {
            Num c;
            while( isdigit( input[pos] ) ) {
                c.re *= 10;
                c.re += ( input[pos++] - '0' );
            }
            V.push_back( c );
            while( OP.size() && OP.back() == '*' ) {
                Num a = V.back();  V.pop_back();
                Num b = V.back();  V.pop_back();
                V.push_back( Op( '*' )( a, b ) );
                OP.pop_back();
            }
        }
        else if( input[pos] == ')' ) {
            vector<char>    OP2;
            vector<Num>     V2;
            V2.push_back( V.back() );
            V.pop_back();
            while( OP.back() != '(' ) {
                OP2.push_back( OP.back() );
                OP.pop_back();
                V2.push_back( V.back() );
                V.pop_back();
            }
            while( OP2.size() ) {
                Num a = V2.back();  V2.pop_back();
                Num b = V2.back();  V2.pop_back();
                V2.push_back( Op( OP2.back() )( a, b ) );
                OP2.pop_back();
            }
            V.push_back( V2.back() );
            OP.pop_back();
            while( OP.size() && OP.back() == '*' ) {
                Num a = V.back();  V.pop_back();
                Num b = V.back();  V.pop_back();
                V.push_back( Op( '*' )( a, b ) );
                OP.pop_back();
            }
            ++pos;
        }
    }
    return  V.back();
}

int main() {
    
    string  input,  leq,    req;
    Num     lval,   rval;
    
    for( int T = 1; cin >> input; T++ ) {
        
        printf( "Equation #%d\n", T );
        
        leq = input.substr( 0, input.find( '=' ) );
        req = input.substr( input.find( '=' ) + 1 );
        
        lval = parse( leq );
        rval = parse( req );
        
        lval = Op( '-' )( lval, rval );
        if( lval.im == 0 ) {
            if( lval.re == 0 )
                puts( "Infinitely many solutions." );
            else
                puts( "No solution." );
        }
        else printf( "x = %.6lf\n",
            -double( lval.re ) / double( lval.im ) );
        puts( "" );
        
    }

}
