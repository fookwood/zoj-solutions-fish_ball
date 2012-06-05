#include <stdio.h>
#include <string.h>
#define  MAXN 110
#define  MaxLen 400

int  N , M , Con_N , K;
int  map [MAXN] [MAXN] , CNum [MAXN];
int  List [MAXN] , LSize , mk [MAXN] , Num [MAXN] , Deg1 [MAXN] , Deg2 [MAXN] , P [MAXN];


struct HP {
       int len , s [MaxLen];
       HP operator + ( const HP & );
       HP operator * ( const int & );
       HP operator * ( const HP & );
       HP operator / ( const int & );
       void  print ();
};

HP   Opt [MAXN] [MAXN];

bool init ();
void CalConnect ();
void DFS1 ( int );
void DFS2 ( int );
HP   c ( int , int );
void solve ();

main ()
{
     while ( init () ) {
           CalConnect ();
           solve ();
     }
     
}

void solve ()
{
     for ( int i = 0; i <= M; i ++ ) for ( int j = 0; j <= K; j ++ ) Opt [i] [j].len = 1 , Opt [i] [j].s [0] = 0;
     
     for ( int i = 0; i <= K; i ++ ) Opt [0] [i] = c ( CNum [0] , i );
     for ( int i = 1; i <= M; i ++ )
         for ( int j = i; j <= K; j ++ )
             for ( int k = 1; k <= j && k <= CNum [i]; k ++ )
                 Opt [i] [j] = c ( CNum [i] , k ) * Opt [i - 1] [j - k] + Opt [i] [j];// , printf ( "i = %d j = %d k = %d -- " , i , j , k ) , Opt [i] [j].print ();
     
/*     for (int i = 0; i <= M; i++ )
         for ( int j = 0; j <= K; j ++ )
             printf ( "%d %d ----- " , i , j ) , Opt [i] [j].print ();
*/
     Opt [M] [K].print ();
     printf ( "\n" );
}

void DFS1 ( int k )
{
     mk [k] = true;
     for ( int i = 1; i <= N; i ++ ) if ( !mk [i] && map [k] [i] ) DFS1 ( i );
     List [-- LSize] = k;
}

void DFS2 ( int k )
{
     mk [k] = true , Num [k] = Con_N;
     for ( int i = 1; i <= N; i ++ ) if ( !mk [i] && map [i] [k] ) DFS2 ( i );
}

void CalConnect ()
{
     LSize = N , Con_N = 0;
     memset ( mk , 0 , sizeof ( mk ));
     for ( int i = 1; i <= N; i ++ ) if ( !mk [i] ) DFS1 ( i );
     memset ( mk , 0 , sizeof ( mk ));
     for ( int i = 0; i < N; i ++ ) if ( !mk [List [i]] ) Con_N ++ , DFS2 ( List [i] );
     
     memset ( Deg1 , 0 , sizeof ( Deg1 ));
     memset ( Deg2 , 0 , sizeof ( Deg2 ));
     for ( int i = 1; i <= N; i ++ )
         for ( int j = 1; j <= N; j ++ ) if ( map [i] [j] && Num [i] != Num [j] )
             Deg1 [Num [i]] ++ , Deg2 [Num [j]] ++;
     memset ( P , 0 , sizeof ( P ));
     for ( int i = 1; i <= N; i ++ ) P [Num [i]] ++;
     M = 0;
     memset ( CNum , 0 , sizeof ( CNum )) , CNum [0] = N;
     for ( int i = 1; i <= Con_N; i ++ ) if ( !Deg1 [i] || !Deg2 [i] )
         CNum [++ M] = P [i] , CNum [0] -= P [i];
     
//     printf ( "%d\n" , M );
//     for ( int i = 0; i <= M; i ++ ) printf ( "%d " , CNum [i] ); printf ( "\n" );

}

bool init ()
{
     int  M , a , b;
     if ( scanf ( "%d%d%d" , &N , &M , &K ) != 3 ) return false;
     memset ( map , 0 , sizeof ( map ));
     for ( int i = 0; i < M; i ++ )
         scanf ( "%d%d" , &a , &b ) , map [a] [b] = true;
     return true;
}

HP HP :: operator + ( const HP & B )
{
      HP Ret;
      int    i , j;
      for ( i = j = 0; i < len || i < B.len; i ++ ) {
          if ( i < len ) j += s [i];
          if ( i < B.len ) j += B.s [i];
          Ret.s [i] = j % 10 , j /= 10;
      }
      for ( ; j ; j /= 10 ) Ret.s [i ++] = j % 10;
      for ( Ret.len = i; Ret.len > 1 && Ret.s [Ret.len - 1] == 0; Ret.len -- );
      return Ret;
}

HP HP :: operator * ( const int & B )
{
      HP Ret;
      int i , j;
      for ( i = j = 0; i < len; i ++ )
          j += s [i] * B , Ret.s [i] = j % 10 , j /= 10;
      for ( ; j ; j /= 10 ) Ret.s [i ++] = j % 10;
      for ( Ret.len = i; Ret.len > 1 && Ret.s [Ret.len - 1] == 0 ; Ret.len -- );
      return Ret;
}

HP HP :: operator / ( const int & B )
{
      HP Ret;
      int i , j;
      for ( i = len - 1 , j = 0; i >= 0; i -- )
          j = j * 10 + s [i] , Ret.s [i] = j / B , j %= B;
      for ( Ret.len = len; Ret.len > 1 && Ret.s [Ret.len - 1] == 0; Ret.len -- );
      return Ret;
}

HP c ( int a , int b )
{
     HP Ret;
     if ( a < b || a < 0 || b < 0 ) { Ret.len = 1 , Ret.s [0] = 0; return Ret; }
     Ret.len = 1 , Ret.s [0] = 1;
     if ( a - b < b ) b = a - b;
     for ( int i = 1; i <= b; i ++ ) Ret = Ret * ( a - i + 1 ) / i;
     return Ret;
}

void HP :: print ()
{
     for ( int i = len - 1; i >= 0; i -- ) printf ( "%d" , s[i] );
     printf ( "\n" );
}

HP HP :: operator * ( const HP & B )
{
      HP  Ret;
      int i , j;
      Ret.len = len + B.len - 1;
      for ( i = 0; i < Ret.len; i ++ ) Ret.s [i] = 0;
      for ( i = 0; i < len; i ++ )
          for ( j = 0; j < B.len; j ++ )
              Ret.s [i + j] += s [i] * B.s [j];
      for ( i = j = 0; i < Ret.len; i ++ )
          j += Ret.s [i] , Ret.s [i] = j % 10 , j /= 10;
      for ( ; j; j /= 10 ) Ret.s [Ret.len ++] = j % 10;
      for ( ; Ret.len > 1 && Ret.s [Ret.len - 1] == 0; Ret.len -- );
      return Ret;
}
