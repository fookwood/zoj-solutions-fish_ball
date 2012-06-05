#include <stdio.h>
#include <string.h>

const    int dx [4] = { 0 , 0 , -1 , 1 };
const    int dy [4] = { -1 , 1 , 0 , 0 };

int   N , M , Total;
char  map [6] [7];
bool  Searched [6] [6];


bool  init ()
{
      scanf ( "%d%d\n" , &N , &M );
      if ( N == 0 ) return false;
      for ( int i = Total = 0; i < N; i ++ ) {
          gets ( map [i] );
          for ( int j = 0; j < M; j ++ ) if ( map [i] [j] == '.' ) Total ++;
      }
      return true;
}

bool  range ( int x ,int y )
{
      return  x >= 0 && x < N && y >= 0 && y < M;
}

bool  Search ( int x , int y , int depth )
{
      if ( depth == Total ) return true;
      int  i , px , py;
      for ( i = 0; i < 4; i ++ ) {
          px = x + dx [i] , py = y + dy [i];
          if ( !range ( px , py ) || map [px] [py] == 'S' || Searched [px] [py] ) continue;
          Searched [px] [py] = true;
          if ( Search ( px , py , depth + 1 ) ) return true;
          Searched [px] [py] = false;          
      }
      return false;
}

main ()
{
     while ( init () ) {
           if ( map [0] [0] == 'S' ) {
                printf ( "NO\n" );
                continue;
           }
           
           memset ( Searched , 0 , sizeof ( Searched ));
           Searched [0] [0] = true;
           if ( Search ( 0 , 0 , 1 )) printf ( "YES\n" );
           else printf ( "NO\n" );
     }
}
