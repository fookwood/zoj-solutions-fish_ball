// 3014797 2008-07-30 23:05:39 Accepted 1958 C++ 00:00.00 864K 呆滞的慢板 

// 集合运算，STL 的特长，主要难度在于中缀表达式的运算 

#include <string>
#include <iostream>
#include <vector>
#include <iterator> 
using namespace std;

class Op {
    char type;
public:
    Op( char c ) : type( c ) {};
    string operator() ( string s1, string s2 ) {
        char    s3[100];
        sort( s1.begin(), s1.end() );
        sort( s2.begin(), s2.end() );
        if( type == '+' )
            *set_union( s1.begin(), s1.end(), s2.begin(), s2.end(), s3 ) = 0;
        else if( type == '*' )
            *set_intersection( s1.begin(), s1.end(), s2.begin(), s2.end(), s3 ) = 0;
        else if( type == '-' )
            *set_difference( s1.begin(), s1.end(), s2.begin(), s2.end(), s3 ) = 0;
        return  s3; 
    } 
}; 

int main() {
    
    vector<string>  V,  W;
    vector<char>    OP, OP2; 
    string  input,  ans;
    
    while( getline( cin, input ) ) {
        if( input == "" ) continue;
        int pos = 0;
        V.clear(); 
        OP.clear(); 
        input = '(' + input + ')';
        while( pos < input.size() ) { 
            if( input[pos] == ' ' ) continue;
            if( input[pos] == '{' ) {
                ans.erase();
                while( input[++pos] != '}' )
                    ans += input[pos];
                V.push_back( ans );
                while( OP.size() && OP.back() == '*' ) {
                    string  s1 = V.back();  V.pop_back();
                    string  s2 = V.back();  V.pop_back();
                    V.push_back( Op( OP.back() )( s1, s2 ) );
                    OP.pop_back();
                }
                ++pos;
            }
            else if( input[pos] == ')' ) {
                W.clear();
                OP2.clear();
                W.push_back( V.back() );
                V.pop_back();
                while( OP.size() && OP.back() != '(' ) {
                    OP2.push_back( OP.back() );
                    W.push_back( V.back() );
                    V.pop_back();
                    OP.pop_back();
                }
                while( OP2.size() ) {
                    string  s1 = W.back();  W.pop_back();
                    string  s2 = W.back();  W.pop_back();
                    W.push_back( Op( OP2.back() )( s1, s2 ) );
                    OP2.pop_back();
                }
                V.push_back( W.back() );
                OP.pop_back();
                while( OP.size() && OP.back() == '*' ) {
                    string  s1 = V.back();  V.pop_back();
                    string  s2 = V.back();  V.pop_back();
                    V.push_back( Op( OP.back() )( s1, s2 ) );
                    OP.pop_back();
                }
                ++pos;
            }
            else OP.push_back( input[pos++] );
        }
        cout << '{' << V.back() << '}' << endl;
    } 
    
} 
