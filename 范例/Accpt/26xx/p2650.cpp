#include <math.h>
#include <stdio.h>
#include <string.h>
#define  eps       1e-8

double   W ( int N , double Money )
{
         double  Ret = 0;
         for ( int i = 1; i <= N; i ++ ) Ret += (Money * N) / i;
         return    Ret;
}

main ()
{
     char Str [100];
     int  N , len , i;
     double Money , Next;
     while ( scanf ( "%s%d" , Str , &N ) != EOF ) {
           len = strlen ( Str );
           for ( Money = 0 , i = 0; i < len && Str [i] != '.'; i ++ ) Money = Money * 10 + Str [i] - '0';
           for ( Next = 0 , i ++ ; i < len && Str [i] != '.'; i ++ ) Next = Next * 10 + Str [i] - '0';
           Money += Next / 17;
           for ( Next = 0 , i ++ ; i < len; i ++ ) Next = Next * 10 + Str [i] - '0';
           Money += Next / 17 / 29;
           Money = W ( N , Money );
           Money = ceil ( Money - eps ) + eps;
           printf ( "%.lf\n" , Money );
     }
}

