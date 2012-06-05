/////////////////////////////////////////////////
//        算术表达式中缀到后缀实现 v1.0        //
/////////////////////////////////////////////////
//  1. 该算法输入一个中缀算术表达式字符串;     //
//  2. 返回一个等价的后缀表达式字符串;         //
//  3. 输入中空格自动忽略;                     //
//  4. 输出单元以空格分界,变量为数字或字母;    //
//  5. 后缀表达式可供字符串流识别进行运算;     //
/////////////////////////////////////////////////
//          2008 CopyRight(c) by elf           //
/////////////////////////////////////////////////

#include <iostream> 
#include <string>
#include <stack>
#include <cctype>
using namespace std;

string postfix( const string& exp ) {
    
//    exp += ' ';             // Sentinel
    
    char token;             // exp 中的字符
    stack<char> opStack;    // 运算符栈
    string  postfixExp;     // 后缀表达式
    
    for( int i = 0; i < exp.length(); ++i ) {
        
        token = exp[i];

        switch( token ) {
            
            case ' ':
            break;
            
            case '(':
                opStack.push( token );
            break;
            
            case ')':
                while( opStack.top() != '(' ) {
                    postfixExp += opStack.top();
                    postfixExp += ' ';
                    opStack.pop();
                }
                opStack.pop();
            break;

            case '+': case '-': case '*': case '/': case '%':
                while( 1 ) {
                    if( opStack.empty()     ||
                        opStack.top() == '('  ||
                        ( token == '*' || token == '/' || token == '%' ) &&
                        ( opStack.top() == '+' || opStack.top() == '-' ) ) {
                        opStack.push( token );
                        break;
                    }
                    else {
                        postfixExp += opStack.top();
                        postfixExp += ' ';
                        opStack.pop();
                    }
                }
            break;

            default:        // 否则这就是操作数
                postfixExp += token;
                while( isalnum( exp[i + 1] ) )
                    postfixExp += exp[++i];
                postfixExp += ' ';

        }
        
    }
        
    while( !opStack.empty() ) {
        if( opStack.top() != '(' ) {
            postfixExp += opStack.top();
            postfixExp += ' ';
        }
        opStack.pop();
    }

        
    return  postfixExp;
    
}

// 演示，从 stdin 输入一个算术表达式，输出其后缀表示 
int main() {
    
    string s;
    while( getline( cin, s ) )
        cout << postfix( s ) << endl;
    
}
