#include <stdio.h>
#include <map>
#include <algorithm>
#define MAXN 1000

using namespace std;

const int days [13] = { 0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };

struct TDate {
       int year , month , day;
       bool operator < ( const TDate & ) const;
       bool operator == ( const TDate & ) const; 
       TDate operator + ( const int );
       TDate operator - ( const int );
       void init ();
       void print () const ;
};

typedef map < TDate , int > TMap;

int    N1 , N2 , N , Tot;
TDate  Add1 [MAXN] , Add2 [MAXN] , Sub1 [MAXN] , Sub2 [MAXN] , Info [MAXN] , Start [MAXN] , Finish [MAXN];
TMap   Map;
bool   Line [MAXN] , Point [MAXN];

bool isleap ( int );
bool isgood ( TDate );
bool init ();
void solve ();
bool check ();

main ()
{
     int p = 0;
     for ( ; init (); ) {
         if ( p ) printf ( "\n" );
         printf ( "Case %d:\n" , ++ p );
         solve ();
         if ( !check () ) for (;;);
     }
}

bool check ()
{
     for ( int i = 0; i < N2; i ++ )
         if ( !isgood ( Add1 [i] ) || !isgood ( Add2 [i] ) ) return false;
     for ( int i = 0; i < N1; i ++ )
         if ( !isgood ( Sub1 [i] ) || !isgood ( Sub2 [i] )) return false;
     for ( int i = 0; i < Tot; i ++ )
         if ( !isgood ( Start [i] ) || !isgood ( Finish [i] )) return false;
     return true;
}

void solve ()
{
     int a , b , i , j;
     
     memset ( Line , 0 , sizeof ( Line ));
     memset ( Point , 0 , sizeof ( Point ));
     
     for ( i = 0; i < N2; i ++ ) {
         a = Map [Add1 [i]] , b = Map [Add2 [i]];
         for ( j = a; j < b; j ++ ) Line [j] = Point [j] = true; Point [b] = true;
     }
     for ( i = 0; i < N1; i ++ ) {
         a = Map [Sub1 [i]] , b = Map [Sub2 [i]];
         for ( j = a; j < b; j ++ ) Line [j] = Point [j] = false; Point [b] = false;
     }
     for ( i = 0; i + 1 < N; i ++ )
         if ( Info [i] + 1 == Info [i + 1] ) Line [i] = true;
     
     
//     for ( int i = 0; i < N; i ++ ) printf ( "%d " ,Line [i] ); printf ("\n" );
//     for ( int i = 0; i < N; i ++ ) printf( "%d " , Point [i] ); printf ("\n" );
     
     for ( i = Tot = 0; i < N; i ++ ) if ( Point [i] || Line [i] ) {
         if ( Point [i] ) Start [Tot] = Info [i]; else Start [Tot] = Info [i] + 1;
         Point [i] = true;
         for ( ; Point [i] && Line [i]; i ++ );
         if ( Point [i] ) Finish [Tot ++] = Info [i]; else Finish [Tot ++] = Info [i] - 1;
         if ( Finish [Tot - 1] < Start [Tot - 1] ) Tot --;
         Point [i --] = false;
     }
     for ( i = 0; i < Tot; i ++ ) {
         if ( Start [i] == Finish [i] ) Start [i].print ();
         else Start [i].print () , printf ( " to " ) , Finish [i].print ();
         printf ( "\n" );
     }
     if ( Tot == 0 ) printf ( "No additional quotes are required.\n" );
}

bool init ()
{
     scanf ( "%d%d" , &N1 , &N2 ); 
     if ( N1 == 0 && N2 == 0 ) return false;
     
     N = 0;
     for ( int i = 0; i < N1; i ++ ) Sub1 [i].init () , Sub2 [i].init () , Info [N ++] = Sub1 [i] , Info [N ++] = Sub2 [i];
     for ( int i = 0; i < N2; i ++ ) Add1 [i].init () , Add2 [i].init () , Info [N ++] = Add1 [i] , Info [N ++] = Add2 [i];
     
     sort ( Info , Info + N ) , N = unique ( Info , Info + N ) - Info;
     
     Map.clear ();
//     for ( int i = 0; i < N;i ++ ) Info [i].print (), printf ( "\n" );
     for ( int i = 0; i < N; i ++ ) Map [Info [i]] = i;
     
     return true;
}

bool isleap ( int year )
{
     return year % 100 == 0 ? year % 400 == 0 : year % 4 == 0;
}

bool TDate :: operator < ( const TDate & Cmp ) const {
     if ( year != Cmp.year ) return year < Cmp.year;
     if ( month != Cmp.month ) return month < Cmp.month;
     return day < Cmp.day;
}

bool TDate :: operator == ( const TDate & Cmp ) const {
     return year == Cmp.year && month == Cmp.month && day == Cmp.day;
}

void TDate :: init ()
{
     int Tmp;
     scanf ( "%d" , &Tmp );
     year = Tmp / 10000 , month = Tmp / 100 % 100 , day = Tmp % 100;
}

void TDate :: print () const
{
     printf ( "%d/%d/%d" , month , day , year );
}

TDate TDate :: operator + ( const int d )
{
      TDate Ret = *this;
      Ret.day ++;
      if ( Ret.day <= days [Ret.month] || Ret.day == 29 && Ret.month == 2 && isleap ( Ret.year ));
      else Ret.day = 1 , Ret.month ++;
      if ( Ret.month == 13 ) Ret.year ++ , Ret.month = 1;
      if ( d > 1 ) Ret = Ret + ( d - 1 );
      return Ret;
}

TDate TDate :: operator - ( const int d )
{
      TDate Ret = *this;
      Ret.day --;
      if ( Ret.day == 0 ) { 
           Ret.month --; 
           if ( Ret.month == 0 ) 
              Ret.year -- , Ret.month = 12; 
           Ret.day = days [Ret.month]; 
           if ( Ret.month == 2 && isleap ( Ret.year )) Ret.day ++; 
      }
      if ( d > 1 ) Ret = Ret - ( d - 1 );
      return Ret;
}

bool isgood ( TDate B )
{
     if ( B.year < 1700 || B.year > 2100 ) return false;
     if ( B.month < 1 || B.month > 12 ) return false;
     if ( B.day >= 1 && B.day <= days [B.month] ) return true;
     if ( B.month == 2 && isleap ( B.year ) && B.day == 29 ) return true;
     return false;
}
