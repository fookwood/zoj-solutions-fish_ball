#include <stdio.h>
#include <list>
#include <algorithm>
#define MAXN 40
#define S    9

using namespace std;

struct TInfo {
       int len , s [4] , value;
       int & operator [] ( const int Index ) { return s [Index]; }
       int operator [] ( const int Index ) const { return s [Index]; }
       bool operator < ( const TInfo & B ) const {
            int t = len * ( len - 1 ) * value - B.len * ( B.len - 1 ) * B.value;
            return t == 0 ? len < B.len : t > 0;
       }
       void init ();
};

struct TState {
       int    Tot_Coe;
       TInfo  SubInfo [S];
       TState ();
       TInfo & operator [] ( const int Index ) { return SubInfo [Index]; }
       TInfo   operator [] ( const int Index ) const { return SubInfo [Index]; }
       void    print ();
};

typedef list <TInfo*> TList;

int    N , Sum [MAXN];
TInfo  Info [MAXN];
TState State , Ans;
TList  List [5];

bool   init ();
void   Search ( int , int );

main ()
{
     while ( init () ) {
/*           for ( int i = 0; i < N; i ++ ) {
               printf ( "%d %d " , Info [i].len , Info [i].value);
               for ( int j = 0; j < Info [i].len;j ++ ) printf ( " %d" , Info [i] [j] );
               printf ( "\n" );
           }
           printf ( "\n\n" );
*/
           Search ( 0 , Info [0].len );
           Ans.print ();
     }
}

void Search ( int depth , int p )
{
//     printf ( "Coe == %d\n" , State.Tot_Coe );
//     State.print ();
//     printf ( "\n" );
     if ( depth == N ) {
          if ( State.Tot_Coe > Ans.Tot_Coe )
             Ans = State;
          return;
     }
     int  i , j , k;
     TInfo * d;
     
     for ( i = p; i; i -- ) {
         for ( j = i; j < 5; j ++ ) if ( !List [j].empty () ) break;
         if ( j >= 5 ) continue;
         d = List [j].front ();
         List [j - i].push_front ( d );
         List [j].pop_front ();
         State.Tot_Coe += Info [depth].value * i * ( i - 1 );
         
         for ( k = 1; k <= i; k ++ )
             (*d) [j - k] = Info [depth] [p - k];
         
         if ( p - i && State.Tot_Coe + Sum [depth] > Ans.Tot_Coe ) Search ( depth , p - i );
         else if ( State.Tot_Coe + Sum [depth + 1] > Ans.Tot_Coe ) Search ( depth + 1 , Info [depth + 1].len );
         
         d = List [j - i].front ();
         List [j].push_front ( d );
         List [j - i].pop_front ();
         State.Tot_Coe -= Info [depth].value * i * ( i - 1 );
         for ( k = 1; k <= i; k ++ )
             (*d) [j - k] = 0;
     }
}

bool init ()
{
     if ( scanf ( "%d" , &N ) != 1 ) return false;
     for ( int i = 0; i < N; i ++ ) Info [i].init ();
     sort ( Info , Info + N );
     for ( int i = 0; i < 5; i ++ ) List [i].clear ();
     State = TState ();
     Ans.Tot_Coe = -1;
     for ( int i = 0; i < S; i ++ ) List [4].push_back ( & State [i] );
     for ( int i = 0; i < N; i ++ ) Sum [i] = Info [i].len * ( Info [i].len - 1 ) * Info [i].value;
     Sum [N] = 0;
     for ( int i = N - 1; i >= 0; i -- ) Sum [i] += Sum [i + 1];
     return true;
}

void TInfo :: init ()
{
     scanf ( "%d%d" , &len , &value );
     for ( int i = 0; i < len; i ++ ) scanf ( "%d" , &s [i] );
}

TState :: TState ()
{
       Tot_Coe = 0;
       memset ( SubInfo , 0 , sizeof ( SubInfo ));
}

void   TState :: print ()
{
       printf ( "%d\n" , Tot_Coe );
       for ( int i = 0; i < 9; i ++ ) {
           for ( int j = 0; j < 4; j ++ ) {
               if ( j ) printf ( " " );
               printf ( "%d" , (*this) [i] [j] );
           }
           printf ( "\n" );
       }
       printf ( "\n" );
}
