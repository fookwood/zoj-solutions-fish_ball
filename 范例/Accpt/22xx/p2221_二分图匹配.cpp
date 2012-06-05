#include <stdio.h>
#include <algorithm>
#define  MAXN     500

struct   TNode {
         int   time , x1 , y1 , x2 , y2 , finish;
}        Data [MAXN];
int      N , Line [MAXN] [MAXN] , Len [MAXN] , Link [MAXN];

bool     mk [MAXN];

void     init ()
{
         int  a , b;
         scanf ( "%d\n" , &N );
         for ( int i = 0; i < N; i ++ ) {
             scanf ( "%d:%d%d%d%d%d\n" , &a , &b , &Data [i].x1 , &Data [i].y1 , &Data [i].x2 , &Data [i].y2 );
             Data [i].time = a * 60 + b;
             Data [i].finish = Data [i].time + abs ( Data [i].x1 - Data [i].x2 ) + abs ( Data [i].y1 - Data [i].y2 );
         }
}

void     build_graph ()
{
         for ( int i = 0; i < N; i ++ )
             for ( int j = Len [i] = 0; j < N; j ++ )
                 if ( abs ( Data [i].x2 - Data [j].x1 ) + abs ( Data [i].y2 - Data [j].y1 ) < Data [j].time - Data [i].finish )
                    Line [i] [Len [i] ++] = j;
}

bool     find ( int k )
{
         int  t;
         for ( int i = 0; i < Len [k]; i ++ ) if ( !mk [Line [k] [i]] ) {
             mk [Line [k] [i]] = true;
             t = Link [Line [k] [i]];
             Link [Line [k] [i]] = k;
             if ( t == -1 || find ( t )) return true;
             Link [Line [k] [i]] = t;
             
         }
         return false;
}

int      Ans ()
{
         int    Ret = 0 , i , j , k;
         memset ( Link , 0xff , sizeof ( Link ));
         for ( int i = 0; i < N; i ++ ) {
             memset ( mk , 0 , sizeof ( mk ));
             if ( find ( i )) Ret ++;
         }
         return      N - Ret;
}

main ()
{
     int total;
     for ( scanf ( "%d\n" , &total ); total; total -- ) {
         init ();
         build_graph ();
         printf ( "%d\n" , Ans ());
     }
}
