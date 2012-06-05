// 1759848 2009-02-07 01:03:44 Accepted  1072 C++ 0 176 呆滞的慢板 

// 模拟指令机器，纯粹模拟，把我调戏得好痛苦啊~~

#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

int val( char x ) {
    switch( x ) {
        case '0': return 0x0;
        case '1': return 0x1;
        case '2': return 0x2;
        case '3': return 0x3;
        case '4': return 0x4;
        case '5': return 0x5;
        case '6': return 0x6;
        case '7': return 0x7;
        case '8': return 0x8;
        case '9': return 0x9;
        case 'A': case 'a': return 0xA;
        case 'B': case 'b': return 0xB;
        case 'C': case 'c': return 0xC;
        case 'D': case 'd': return 0xD;
        case 'E': case 'e': return 0xE;
        case 'F': case 'f': return 0xF;
    }
}

char code( char x ) {
    if( x < 10 )
        return '0' + x;
    return 'A' + x - 10;
}

int getAddr( char* begin ) {
    return val( *( begin + 1 ) ) + ( val( *begin ) * 16 );
}

int main() {
    char M[257] = {};
    int pc, ad;
    int A, B, temp;
    while( true ) {
        ad = 0;
        while( ad <= 0xFF ) {
            M[ad] = getchar();
            if( isalnum( M[ad] ) ) ad++;
        }
        if( *M == '8' ) break;
        pc = 0;
        A = 0;
        B = 0;
        while( M[pc] != '8' ) {
            // OLE ASSERT
            if( pc >= 0xF0 ) {
                while(1) puts("fuck!!");
                break;
            }

            switch( M[pc] ) {
                case '0':
                    ad = getAddr( M + pc + 1 );
                    A = val( M[ad] );
                    pc += 3;
                break;
                case '1':
                    ad = getAddr( M + pc + 1 );
                    M[ad] = code( A );
                    pc += 3;
                break;
                case '2':
                    swap(A, B);
                    pc += 1; 
                break;
                case '3':
                    A += B;
                    B = A / 16;
                    A %= 16;
                    pc += 1;
                break;
                case '4':
                    A = ( A + 1 ) % 16;
                    pc += 1;
                break;
                case '5':
                    A = ( A + 15 ) % 16;
                    pc += 1;
                break;
                case '6':
                    if(A == 0) pc = getAddr( M + pc + 1 );
                    else pc += 3;
                break;
                case '7':
                    pc = getAddr( M + pc + 1);
                break;
                case '8':
                break;
            }
        }
        puts(M);
    }
}
