// PERFORMER: ELF
// DATE: Dec. 9th, 2007
// TITLE: P,MTHBGWB(PROBLEM_B)

// Refactored on 2008-5-21

#include <iostream>
#include <string>
using namespace std;

// 密码表 
string code[]={ ".-",   "-...", "-.-.", "-..",  ".",
                "..-.", "--.",  "....", "..",   ".---",
                "-.-",  ".-..", "--",   "-.",   "---",
                ".--.", "--.-", ".-.",  "...",  "-",
                "..-",  "...-", ".--",  "-..-", "-.--",
                "--..", "..--", "---.", ".-.-", "----" };

// 原字符表 
char letter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.,?";

// 密码段长度表 
int list[]={ 2, 4, 4, 3, 1,
             4, 3, 4, 2, 4,
             3, 4, 2, 2, 3,
             4, 4, 3, 3, 1,
             3, 4, 3, 4, 4,
             4, 4, 4, 4, 4 };

// 整数数组反转 
void reverse( int* segment, int len ) {
    int     a[100];
    for( int i = 0; i < len; i++ ) a[len - 1 - i] = segment[i];
    for( int i = 0; i < len; i++ ) segment[i] = a[i]; 
}

// 原字符串翻译成密码串 
string encrypt( const string& a ) {

    string  s( "" );

    for( int j = 0; j < a.length(); j++ ) {

        for( int i = 0; i < 30; i++ ) {

            if( letter[i]==a[j] ) {
                s += code[i];
                break;
            }

        }

    }
    
    return s;

}

// 原字符串生成密码分段表 
void seg( string a, int b[] ) {
    
    for( int j = 0; j < a.length(); j++ ) {
    
        for( int i = 0; i < 30; i++ ) {
    
            if( letter[i] == a[j] ) {
                b[j] = list[i];
                break;
            }
    
        }
    
    }
    
}

// 从密码串前端提取n个字符 
string cut( string &a, int n ) {
    
    string  b = a.substr( 0, n );
    
    a.erase( 0, n );
    
    return b;

}

// 单个密码翻译 
char reset(string a) {
    
    for( int i = 0; i < 30; i++ )
    
        if( a == code[i] )
    
            return letter[i];

}

// 从密码串和分段表还原原字符串 
string recover( int b[], string &code, int n ) {
    
    string  a( "" );
    
    for( int i = 0; i < n; i++ )
    
        a += reset( cut( code, b[i] ) );
    
    return a;

}

int main() {
    
    string  buf,    code,   text;
    
    int line,   b[100];
    
    cin >> line;
    
    for( int i = 1; i <= line; ++i ) {
    
        cin >> buf;

        code = encrypt( buf );

        seg( buf, b );

        reverse( b, buf.length() );
        
        text = recover( b, code, buf.length() );

        cout << i << ": " << text << endl;

    }

}
