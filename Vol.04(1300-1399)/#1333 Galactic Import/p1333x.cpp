// 3063424 2008-09-08 12:16:47 Accepted 1333 C++ 00:00.00 392K 呆滞的慢板 

// 这个数据明显有问题而且很弱...不说啥，不说啥，啥都不说了... 

#include <cstdio>

double  mx, now;

char    skip[30];

int     N,  pos;

int main() {
    
    while( scanf( "%d", &N ) != EOF ) {
        
        pos = 30;
        mx = 0.0;
        
        while( N-- ) {
            scanf( "%s%lf%s", skip, &now, skip+1 );
            if( now > mx || now == mx && pos > *skip ) {
                mx = now;
                pos = *skip - 'A';
            }
        }
        
        printf( "Import from %c\n", 'A' + pos );
        
    }
    
}
