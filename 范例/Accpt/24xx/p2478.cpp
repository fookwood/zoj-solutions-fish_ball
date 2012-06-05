#include <stdio.h>
#include <string.h>

int      N;
char     Data [255];

int main(int argc, char *argv[])
{
    char     ch;
    int      last , len , i;
    for ( scanf ( "%d" , &N ); N; N -- ) {
        scanf ( "%s" , Data );
        ch = '*';
        len = strlen ( Data );
        Data [len ++] = '*';
        for ( i = 0; i < len; i ++ ) if ( Data [i] != ch ) {
            if ( ch != '*' ) {
                 if ( last > 1 ) printf ( "%d" , last );
                 printf ( "%c" , ch );
            }      
            ch = Data [i] , last = 1;
        } else last ++;
        
        printf ( "\n" );
    }
}
