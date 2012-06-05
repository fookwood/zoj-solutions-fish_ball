// 3058804 2008-09-03 21:31:22 Accepted 3025 C++ 00:00.13 860K 呆滞的慢板 

// 中缀表达式的处理，枚举 P, Q, R 计数 

#include <vector>
#include <iostream>
#include <string>
using namespace std;

string  s;

int Neg[3] = { 2, 1, 0 };
int And[3][3] = {
    { 0, 0, 0 },
    { 0, 1, 1 },
    { 0, 1, 2 }
};
int Or[3][3] = {
    { 0, 1, 2 },
    { 1, 1, 2 },
    { 2, 2, 2 }
};

vector<char> sym;
vector<int> val;

int eval( int P, int Q, int R ) {
    sym.clear();
    val.clear();
    for( int i = 0; i < s.size(); ++i ) {
        if( s[i] == '(' )
            sym.push_back( '(' );
        else if( s[i] == ')' ) {
            vector<int> vv( 0 );
            vector<char> ss( 0 );
            vv.push_back( val.back() );
            val.pop_back();
            while( sym.back() != '(' ) {
                if( sym.back() == '+' ) {
                    ss.push_back( '+' );
                    vv.push_back( val.back() );
                    sym.pop_back();
                    val.pop_back();
                }
                else if( sym.back() == '*' ) {
                    ss.push_back( '*' );
                    vv.push_back( val.back() );
                    sym.pop_back();
                    val.pop_back();
                }
                else if( sym.back() == '-' ) {
                    vv.back() = Neg[vv.back()];
                    sym.pop_back();
                }
            }
            sym.pop_back();
            int X = vv.back();
            vv.pop_back();
            while( !ss.empty() ) {
                if( ss.back() == '*' ) {
                    X = And[X][vv.back()];
                    vv.pop_back();
                    ss.pop_back();
                }
                else if( ss.back() == '+' ) {
                    X = Or[X][vv.back()];
                    vv.pop_back();
                    ss.pop_back();
                }
            }
            val.push_back( X );
            while( sym.size() && sym.back() == '-' ) {
                sym.pop_back();
                val.back() = Neg[val.back()];
            }
        }
        else if( isalnum( s[i] ) ) {
            if( isdigit( s[i] ) )
                val.push_back( s[i] - '0' );
            else {
                if( s[i] == 'P' ) val.push_back( P );
                if( s[i] == 'Q' ) val.push_back( Q );
                if( s[i] == 'R' ) val.push_back( R );
            }
        }
        else sym.push_back( s[i] );
    }
    while( sym.size() && sym.back() == '-' ) {
        sym.pop_back();
        val.back() = Neg[val.back()];
    }
    return  val[0];
}

int main() {
    
    while( cin >> s && s != "." ) {
        int tot = 0;
        for( int P = 0; P < 3; ++P )
            for( int Q = 0; Q < 3; ++Q )
                for( int R = 0; R < 3; ++R )
                    if( eval( P, Q, R ) == 2 )
                        tot += 1;
        cout << tot << endl;
    }
    
}
