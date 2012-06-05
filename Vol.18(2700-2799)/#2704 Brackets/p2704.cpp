// 看似不难，做下来不容易
// 先是 TLE 然后 WA
// 必须注意效率以及逻辑的正确性，

#include <cstring>
#include <cstdio>

#define LEN 100010

// 用于压栈记录 
struct Record {
    Record( char c = 0, int x = 0 ) : bracket( c ), index( x ) {} 
    char    bracket;
    int    index; 
};

inline char pair( char c ) {
    switch( c ) {
        case '(': return ')';
        case ')': return '(';
        case '[': return ']';
        case ']': return '['; 
    } 
    return    0; 
} 

int main() {
    char   str[100002];
    int       label[100002]; 
    Record stk[100002];
    int    top,    len,    longest;
    int    head,    rear; 
    while( scanf( "%s", str ) != EOF ) {
        longest = top = head = rear = 0;
        len = strlen( str );
        memset( label, 0, len * sizeof( int ) ); 
        for( int i = 0; i < len; i++ ) {
            switch( str[i] ) {
                case '[': case '(':
                    stk[top++] = Record( str[i], i ); break; 
                case ']': case ')':
                    if( !top || stk[top - 1].bracket != pair( str[i] ) ) top = 0;
                    else {
                        int    x = stk[top - 1].index;
                        while( x && label[x - 1] < 0 )
                            x = -label[x - 1] - 1;
                        label[x] = i + 1;
                        label[i] = -( x + 1 );
                        if( longest < i - x ) {
                            longest = i - x;
                            head = x;
                            rear = i + 1; 
                        }
                        top--; 
                    }
            }
        } 
        for( int i = head; i < rear; i++ )    putchar( str[i] );
        printf( "\n\n" ); 
    }
}
