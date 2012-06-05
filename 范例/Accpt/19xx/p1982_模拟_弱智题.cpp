#include <stdio.h>
#include <string.h>

const    int      dx [4] = { 10 , 0 , -10 , 0 };
const    int      dy [4] = { 0 , -10 , 0 , 10 };

int      x , y , face;
char     Order [100];

main ()
{
     while ( gets ( Order ) ) {
           int len = strlen ( Order );
           x = 310 , y =  420 , face = 0;
           printf ( "300 420 moveto\n310 420 lineto\n" );
           for ( int i = 0; i < len; i ++ ) {
               face += Order [i] == 'A' ? 1 : 3;
               face &= 3;
               x += dx [face] , y += dy [face];
               printf ( "%d %d lineto\n" , x , y );
           }
           printf ( "stroke\nshowpage\n" );
     }
}
