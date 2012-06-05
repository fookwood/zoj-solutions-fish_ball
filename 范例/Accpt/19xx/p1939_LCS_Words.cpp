#include <iostream>
#include <string>
#define  max(a,b) (a>b?a:b)
using    namespace std;


bool     first;
string   Words1 [101] , Words2 [101];
int      N1 , N2 , Opt [101] [101];

void     PrintAns ( int x = N1 , int y = N2 )
{
         if ( x == 0 || y == 0 ) return;
         if ( Words1 [x - 1] == Words2 [y - 1] ) {
              PrintAns ( x - 1 , y - 1 );
              if ( first ) first = false; else cout << ' ';
              cout << Words1 [x - 1];
              return;
         }
         if ( Opt [x - 1] [y] == Opt [x] [y] ) PrintAns ( x - 1 , y );
            else PrintAns ( x , y - 1 );
}

main ()
{
     memset ( Opt , 0 , sizeof ( Opt ));
     
     while ( N1 = N2 = 0 , cin >> Words1 [N1 ++] ) {
           while ( ( cin >> Words1 [N1 ++] ) && Words1 [N1 - 1] [0] != '#' ); N1 --;
           while ( ( cin >> Words2 [N2 ++] ) && Words2 [N2 - 1] [0] != '#' ); N2 --;
           for ( int i = 1; i <= N1; i ++ )
               for ( int j = 1; j <= N2; j ++ )
                   if ( Words1 [i - 1] == Words2 [j - 1] ) Opt [i] [j] = Opt [i - 1] [j - 1] + 1;
                   else Opt [i] [j] = max ( Opt [i - 1] [j] , Opt [i] [j - 1] );
           first = true;
           PrintAns ();
           cout << endl;
     }
}
