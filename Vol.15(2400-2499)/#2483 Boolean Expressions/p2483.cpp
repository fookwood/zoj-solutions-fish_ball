// 2917107 2008-05-15 21:50:21 Accepted 2483 C++ 00:00.00 852K 呆滞的慢板 

// 用个栈搞啊搞啊的，注意数据里有 !!!!V 这样连否的例子 

#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {
    
    string  input;
    
    vector<char>    oper;
    
    int     T = 1;
    
    char    last;
    
    while( getline( cin, input ) ) {
    
        cout << "Expression " << T++ << ": ";

        oper.clear();
        
        input = "(" + input + ")";

        for( int i = 0; i < input.size(); ++i ) {
            
            if( input[i] == ' ' )
                continue;
            
            switch( input[i] ) {
                
                case '(':
                    oper.push_back( '(' );
                break;
                
                case 'V':
                    if( oper.back() == '!' ) {
                        oper.pop_back();
                        if( oper.back() == '&' )
                            oper.pop_back();
                        oper.push_back( 'F' );
                    }
                    else
                        oper.push_back( 'V' );
                break;
                
                case 'F':
                    if( oper.back() == '!' ) {
                        oper.pop_back();
                        if( oper.back() == '&' )
                            oper.pop_back();
                        else
                            oper.push_back( 'V' );
                    }
                    else
                        oper.push_back( 'F' );
                break;
                
                case '!':
                    last = 1;
                    while( input[i+1] == ' ' )   ++i;
                    while( input[i+1] == '!' ) {
                        while( input[i+1] == ' ' )   ++i;
                        ++i;
                        last = !last;
                    }
                    if( last )  oper.push_back( '!' );
                break;
                
                case '|':
                    oper.push_back( '|' );
                break;                
                
                case '&':
                    while( input[i+1] == ' ' )  ++i;
                    if( input[i+1] == 'F' ||
                        input[i+1] == 'V' ) {
                        if( input[++i] == 'F' )
                            last = 'F';
                        else
                            last = oper.back();
                        oper.back() = last;
                    }
                    else    oper.push_back( '&' );
                break;
                
                case ')':
                    if( oper.back() == '(' ) {
                        oper.pop_back();
                        break;
                    }
                    last = oper.back();
                    oper.pop_back();
                    while( oper.back() != '(' ) {
                        oper.pop_back();
                        last = last == 'V' ? 'V' : oper.back();
                        oper.pop_back();
                    }
                    oper.pop_back();
                    if( !oper.empty() && oper.back() == '!' ) {
                        last = last == 'V' ? 'F' : 'V';
                        oper.pop_back();
                    }
                    if( !oper.empty() && oper.back() == '&' ) {
                        oper.pop_back();
                        last = last == 'F' ? 'F' : oper.back();
                        oper.pop_back();
                    }
                    oper.push_back( last );
                break;
            
            }
            
        }
        
        cout << oper.back() << endl;
        
    }
    
    
}
