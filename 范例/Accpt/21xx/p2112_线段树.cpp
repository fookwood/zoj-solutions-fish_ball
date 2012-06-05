#include <stdio.h>
#include <algorithm>

using    namespace std;

const    int maxn = 50001;

int      N , Q , Num [18] [maxn];
int      Key , Ls , Rs , a , b;

void     InputInfo ( int Left , int Right , int depth = 0 )
{
         if ( Left == Right ) {
              scanf ( "%d" , &Num [depth] [Left] );
              return;
         }
         int  mid = ( Left + Right ) / 2;
         InputInfo ( Left , mid , depth + 1 ) , InputInfo ( mid + 1 , Right , depth + 1 );
         merge ( &Num [depth + 1] [Left] , &Num [depth + 1] [mid + 1] , &Num [depth + 1] [mid + 1] , &Num [depth + 1] [Right + 1] , &Num [depth] [Left] );
}

int      GetRank ( int Left , int Right , int depth = 0 )
{
         if ( Left >= Ls && Right <= Rs ) {
                   if ( Num [depth] [Left] > Key ) return 0;
                   if ( Num [depth] [Right] < Key ) return Right - Left + 1;
                   int  low = Left , high = Right + 1 , mid;
                   while  ( low + 1 < high ) {
                          mid = ( low + high ) / 2;
                          if ( Num [depth] [mid] <= Key ) low = mid;
                          else high = mid;
                   }
                   return low - Left + 1;
         }
         if ( Right < Ls || Left > Rs || Left == Right ) return 0;
         int       Mid = ( Left + Right ) / 2 , Ret = 0;
         if ( Ls <= Mid ) Ret += GetRank ( Left , Mid , depth + 1 );
         if ( Mid + 1 <= Rs ) Ret += GetRank ( Mid + 1 , Right , depth + 1 );
         return   Ret;
}

int      Ask ( int k )
{
         int Low = 0 , High = N , Mid;
         while ( Low + 1 < High ) {
               Mid = ( Low + High ) / 2;
               Key = Num [0] [Mid];
               if ( GetRank ( 0 , N - 1 ) < k ) Low = Mid;
               else High = Mid;
         }
         return Num [0] [++ Low];
}

int      change ( int Left = 0 , int Right = N - 1 , int depth = 0 )
{
         int    Ret;
         if ( Left == Right ) { Ret = Num [depth] [Left]; Num [depth] [Left] = b; return Ret; }
         int  mid = ( Left + Right ) / 2;
         Ret = a <= mid ? change ( Left , mid , depth + 1 ) : change ( mid + 1 , Right , depth + 1 );

         int    low = Left , high = Right + 1 , i;
         while ( low + 1 < high ) {
               mid = ( low + high ) / 2;
               if ( Num [depth] [mid] <= Ret ) low = mid;
               else high = mid;
         }
         if ( Ret < b )
              for ( i = low; i < Right && Num [depth] [i + 1] < b; i ++ ) Num [depth] [i] = Num [depth] [i + 1];
         else
              for ( i = low; i > Left && Num [depth] [i - 1] > b; i -- ) Num [depth] [i] = Num [depth] [i - 1];
         Num [depth] [i] = b;
         return Ret;
}

main ()
{
     int total , k;
     char ch;
     for ( scanf ( "%d" , &total ); total; total -- ) {
         scanf ( "%d%d\n" , &N , &Q );
         InputInfo ( 0 , N - 1 );scanf ( "\n" );
         
         for ( int q = 0; q < Q; q ++ ) {
             scanf ( "%c" , &ch );
             if ( ch == 'Q' ) scanf ( "%d%d%d\n" , &Ls , &Rs , &k ) , Ls -- , Rs -- , printf ( "%d\n" , Ask ( k ));
                else scanf ( "%d%d\n" , &a , &b ) , a -- , change ();
         }
     }
}
