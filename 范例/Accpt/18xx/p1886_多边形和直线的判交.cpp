#include <stdio.h>
#include <cmath>
#include <vector>
#define  eps      1e-7

using namespace std;


struct TPoint;
struct TLine;
double Area ();

struct TPoint {
       double x , y;
//     bool   operator == ( const TPoint & );
       TLine  operator - ( const TPoint & );
       TLine  operator + ( const TPoint & );
};

struct TLine {
       double a , b , c;
       TPoint operator * ( const TLine & );
       double operator () ( const TPoint & );
};

vector <TPoint> Points;

main ()
{
     Points.clear ();
     TPoint Q;
     Q.x = 0  , Q.y = 0  , Points.push_back ( Q );
     Q.x = 10 , Q.y = 0  , Points.push_back ( Q );
     Q.x = 10 , Q.y = 10 , Points.push_back ( Q );
     Q.x = 0  , Q.y = 10 , Points.push_back ( Q );
  
     int   Size;
     char  Str [30];
     TPoint Last , Now;
     TLine  Vertical;
     double WValue;
     vector <TPoint> Tmp;
     
     
     Last.x = Last.y = 0;
     while ( scanf ( "%lf%lf%s" , &Now.x , &Now.y , Str ) != EOF ) {
           Size = Points.size ();
           if ( Size == 0 || Str [0] == 'S' ) {
                Points.clear ();
                puts ( "0.00" );
                continue;
           }
           
           Vertical = Last + Now;
           WValue = Str [0] == 'H' ? Vertical ( Now ) : Vertical ( Last );
           
           Tmp.clear ();
           
           Points.push_back ( Points [0] );
           for ( int i = 0; i < Size; i ++ )
               if ( Vertical ( Points [i] ) * WValue > -eps )
                    Tmp.push_back ( Points [i] );
               else {
                    TLine         T;
                    TPoint        D;
                    T = Points [i] - Points [( i + Size - 1 ) % Size];
                    D = Vertical * T ;
                    if ( Vertical ( Points [( i + Size - 1 ) % Size] ) * WValue > eps )
                         Tmp.push_back ( Vertical * ( Points [i] - Points [( i + Size - 1 ) % Size] ));
                    if ( Vertical ( Points [( i + 1 ) % Size] ) * WValue > eps )
                         Tmp.push_back ( Vertical * ( Points [i] - Points [( i + 1 ) % Size] ));
               }
           Points = Tmp;
           Last = Now;
           printf ( "%.2lf\n" , Area ());
     }
}


double TLine :: operator () ( const TPoint & M )
{
       return a * M.x + b * M.y + c;
}


TLine  TPoint :: operator - ( const TPoint & M )
{
       TLine  Ret;
       Ret.a = y - M.y , Ret.b = M.x - x , Ret.c = - ( Ret.a * x + Ret.b * y );
       return  Ret;
}

TLine  TPoint :: operator + ( const TPoint & M )
{
       TLine  Ret;
       Ret.a = M.x - x , Ret.b = M.y - y , Ret.c = - ( Ret.a * ( x + M.x ) + Ret.b * ( y + M.y ) ) / 2;
       return  Ret;
}

/*
bool   TPoint :: operator == ( const TPoint & b )
{
       return fabs ( x - b.x ) < eps && fabs ( y - b.y ) < eps;
}
*/

TPoint TLine :: operator * ( const TLine & M )
{
       TPoint   Ret;
       Ret.x = - ( c * M.b - b * M.c ) / ( a * M.b - b * M.a );
       Ret.y = - ( a * M.c - c * M.a ) / ( a * M.b - b * M.a );
       return  Ret;
}

double Area ()
{
       int  Size = Points.size ();
       if ( Size < 3 ) return 0;
       double    Ret = 0;
       for ( int i = 0; i < Size; i ++ )
           Ret += Points [i].x * Points [(i + 1) % Size].y - Points [i].y * Points [(i + 1) % Size].x;
       return Ret / 2;
}
