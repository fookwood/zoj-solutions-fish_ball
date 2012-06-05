#include <stdio.h>
#include <string.h>

int      N , M , Start , ReachStep [100] [100];
char     map [100] [100];

bool     init ()
{
 scanf ( "%d%d%d\n" , &N , &M , &Start );
 if ( N == 0 ) return false;
 for ( int i = 0; i < N; i ++ ) scanf ( "%s" , map [i] );
 return true;              
}

bool    range ( int x , int y )
{
 return x >= 0 && x < N && y >= 0 && y < M;        
}

void    Work ()
{
 memset ( ReachStep , 0xff , sizeof ( ReachStep ));
 int    x = 0 , y = Start - 1 , step;
 for ( step = 0; ReachStep [x] [y] == -1; step ++ ) {
     ReachStep [x] [y] = step;
     switch ( map [x] [y] ) {
            case 'E'  : y += 1; break;
            case 'W'  : y -= 1; break;
            case 'N'  : x -= 1; break;
            case 'S'  : x += 1; break;
     }
     if ( !range ( x , y ) ) {
        printf ( "%d step(s) to exit\n" , ++ step );
        return;
     }
 }
 printf ( "%d step(s) before a loop of %d step(s)\n" , ReachStep [x] [y] , step - ReachStep [x] [y] );
}

int main(int argc, char *argv[])
{
    while ( init () )
          Work ();
}
