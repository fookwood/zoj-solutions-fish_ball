#include <iostream>
#include <string>
#include <map>
#define MAXN 20000

using namespace std;

typedef map < string , int > TMap;

struct TFrac {
       TFrac () { up = down = 1; }
       int up , down;
       TFrac operator * ( const TFrac & );
       TFrac operator / ( const TFrac & );
};

int    N = 0 ,  Father [MAXN];
TFrac  Frac [MAXN];
TMap   Map;

int gcd ( int , int );
int find ( int );
int num ( char * );

main ()
{
     
     Map.clear ();
     for ( int i = 0; i < MAXN; i ++ ) Father [i] = i;
     
     char state , name1 [100] , name2 [100];
     int  a , b , fa , fb;
     
     TFrac Tmp;
     while ( cin >> state ) {
           if ( state == '.' ) break;
           if ( state == '!' ) {
                cin >> Tmp.down >> name1 >> state >> Tmp.up >> name2;
                
                a = num ( name1 ) , b = num ( name2 );
                
                fa = find ( a ) , fb = find ( b );
                Father [fa] = fb , Frac [fa] = Tmp * Frac [b] / Frac [a];
           }
           if ( state == '?' ) {
                cin >> name1 >> state >> name2;
                
                a = num ( name1 ) , b = num ( name2 );
                
                fa = find ( a ) , fb = find ( b );
                if ( fa != fb ) Tmp.up = Tmp.down = 0;
                else Tmp= Frac [a] / Frac [b];
                
                if ( Tmp.up == Tmp.down && Tmp.down == 0 ) cout << '?'; else cout << Tmp.down; cout << ' ';
                cout << name1 << " = ";
                if ( Tmp.up == Tmp.down && Tmp.up == 0 ) cout << '?'; else cout << Tmp.up; cout << ' ';
                cout << name2 << endl;
           }
     }
     
}

int num ( char * p )
{
    TMap :: iterator Iter = Map.find ( (string) p );
    if ( Iter == Map.end () ) Map [(string) p] = N ++ , Iter = Map.find ( (string) p );
    return Iter->second;
}

int find ( int k )
{
    TFrac Tmp , l;
    int   p , n;
    for ( p = k; Father [p] != p; p = Father [p] ) Tmp = Tmp * Frac [p];
    for ( int i = k; Father [i] != i; i = n ) n = Father [i] , Father [i] = p , l = Frac [i] , Frac [i] = Tmp , Tmp = Tmp / l;
    return p;
}

int gcd ( int a , int b )
{
    if ( a < b ) return gcd ( b , a );
    return b == 0 ? a : gcd ( b , a % b );
}

TFrac TFrac :: operator * ( const TFrac & B )
{
      TFrac Ret;
      Ret.up = up * B.up , Ret.down = down * B.down;
      int g = gcd ( Ret.up , Ret.down ); Ret.up /= g , Ret.down /= g;
      return Ret;
}

TFrac TFrac :: operator / ( const TFrac & B )
{
      TFrac Ret; Ret.up = B.down , Ret.down = B.up;
      return (*this) * Ret;
}
