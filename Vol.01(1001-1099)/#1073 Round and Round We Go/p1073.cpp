// PERFORMER: ELF
// DATE: Dec. 10th, 2007
// TITLE: Round and Round We Go

// Refactored on 2008-5-21

#include <iostream>
#include <string>
using namespace std;

class Nums {
    
    string  str;
    int     len;

public:
    
    Nums() {}
    Nums( string s ) : str( s ), len( s.size() ) {}
    bool input()    { cin >> str; len = str.size(); return !cin.eof(); }
    void output()   { cout << str; }
    friend bool operator != ( Nums a, Nums b );
    string getstr(){ return str; }
    Nums add( int i );
    Nums shift( int i );
    int getl(){ return len; }

};

bool operator != ( Nums a,Nums b) {
    for( int i = 0; i < a.len; i++ ) 
        if( a.getstr() == b.shift( i ).getstr() )
            return false;
    return true;
}

Nums Nums::shift( int i ) {
    string ss = str, tt = ss;
    ss.erase( 0, i );
    tt.erase( i );
    return  Nums( ss + tt );
}

Nums Nums::add( int i ) {
    string ss = str;
    for( int j = 0; j < i; j++ ) {
        string  tt = "";
        int     d = 0;
        for( int k = ss.size() - 1; k >= 0; k-- ) {
            int a = ss[k] - '0' + d,
                b = str[k]- '0',
                c = a + b;
                d = c / 10;
            int e = c - d * 10;
            tt = char( '0' + e ) + tt;
        }
        if( d == 0 )    ss = tt;
        else { ss = ""; break; }
    }
    return Nums( ss );
}


int main() {
    
    Nums    s;
    
    int     j;
    
    while( s.input() ) {

        for( j = 0; j < s.getl(); j++ ) {

            if( s.add(j) != s ) {

                s.output();

                puts( " is not cyclic" );

                break;

            }

        }

        if( j == s.getl() && s.getl() ) {

            s.output();

            cout<<" is cyclic"<<endl;

        }

    }

}
