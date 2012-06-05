#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

#define eps      1e-8
#define Inf      1e20

using namespace std;

struct TPos {
       
       double x , y , l;
       
       TPos () { x = y = 0 , l = 1; }
       TPos ( double tx, double ty ) { x = tx , y = ty , l = 1; }
       inline void operator += ( const TPos & B ) { x /= l , y /= l , l = 1; x += B.getx () , y += B.gety (); }
       inline void operator -= ( const TPos & B ) { x /= l , y /= l , l = 1; x -= B.getx () , y -= B.gety (); }
       inline void operator *= ( const double B ) { x *= B , y *= B; }
       inline void operator /= ( const double B ) { x /= B , y /= B; }
       inline TPos operator + ( const TPos & ) const;
       inline TPos operator - ( const TPos & ) const;
       inline TPos operator * ( const int ) const;
       inline TPos operator / ( const int ) const;
       inline TPos operator * ( const TPos & ) const;
       inline double getx () const { return x / l; }
       inline double gety () const { return y / l; }
       inline double geta () const { return x; }
       inline double getb () const { return y; }
       inline double getl () const { return l; }
       inline double value ( const TPos & ) const;
       inline void init () { scanf ( "%lf%lf" , &x , &y ) , l = 1; }
       inline void print_line () const;
       inline void print_point () const;
};

typedef vector < TPos > TPol;
typedef TPos   TLine;

int     N , K;
double  H;
TPos    Center;
TPol    Poly;

bool    init ();
void    solve ();
void    Cut ( TPol & , TLine , TPos );
int     num_one ( int );
double  Area ( const TPol & );
void print ( TPol & );

main()
{
      while ( init () ) {
            solve ();
      }
}

void  solve ()
{
//      printf ( "\n" );
      
      TPol  CurrentPol;
      TPos  vec , A , B , Cen;
      double Tot = Area ( Poly ) , Min = Tot , CurrentArea;
      
      if ( K > N ) K = N;
      for ( int s = 1; s < ( 1 << N ); s ++ ) if ( num_one ( s ) == K ) {
          CurrentPol = Poly;
          for ( int i = 0; i < N; i ++ ) if ( s & ( 1 << i ) ) {
              vec = Poly [(i + 1) % N] - Poly [i] , swap ( vec.x , vec.y ) , vec.x = - vec.x;
              vec /= sqrt ( vec.getx () * vec.getx () + vec.gety () * vec.gety () ) , vec *= H;
              A = Poly [i] + vec , B = Poly [(i + 1 ) % N] + vec , Cen = Center + vec;
//              A.print_point () , B.print_point ();
              Cut ( CurrentPol , A * B , Cen );
          }
//          printf ( "s == %d\n" , s );
//          print ( CurrentPol );
          CurrentArea = Area ( CurrentPol );
          if ( CurrentArea < Min ) {
               Min = CurrentArea;
/*               for (int j = 0; j < N; j ++ ) if ( s & ( 1 << j ) ) printf ( " %d " , j );
               printf ( "\n" );
               print ( CurrentPol );
               printf ( "%.3lf\n" , CurrentArea );
*/
          }
      }
      printf ( "%.2lf\n" , Tot - Min );
}

void print ( TPol & Poly )
{
     int n = Poly.size ();
     for ( int i = 0; i < n; i ++ ) Poly [i].print_point ();
     printf ( "\n" );
}

double Area ( const TPol & Poly )
{
       int N = Poly.size () , j;
       double Ret = 0;
       for ( int i = 0; i < N; i ++ ) j = ( i + 1 ) % N , Ret += Poly [i].getx () * Poly [j].gety () - Poly [i].gety () * Poly [j].getx ();
       return fabs ( Ret ) / 2.0;
}

void Cut ( TPol & Poly , TLine Line , TPos Center )
{
     int N = Poly.size ();
     if ( N == 0 ) return;
     
     double Key = Line.value ( Center );
     TPol New;
     New.clear ();
     for ( int i = 0; i < N; i ++ ) if ( Line.value ( Poly [i] ) * Key < - eps ) {
         int j = ( i + N - 1 ) % N;
         if ( Line.value ( Poly [j] ) * Key > eps ) New.push_back ( Line * ( Poly [j] * Poly [i] ));
         j = ( i + 1 ) % N;
         if ( Line.value ( Poly [j] ) * Key > eps ) New.push_back ( Line * ( Poly [i] * Poly [j] ));
     } else New.push_back ( Poly [i] );
     Poly = New;
}

int num_one ( int s )
{
    int Ret = 0;
    for ( int i = 0; i < N; i ++ ) if ( s & ( 1 << i )) Ret ++;
    return Ret;
}

bool init () 
{
     TPos Tmp;
     
     scanf ( "%d%d%lf" , &N , &K , &H );
     if ( N == 0 && K == 0 ) return false;
     Poly.clear () , Center = TPos ( 0 , 0 );
     for ( int i = 0; i < N; i ++ ) 
         Tmp.init (), Poly.push_back ( Tmp ) , Center += Tmp;
     Center /= N;
     
//            printf ( "Center : " );
//            Center.print_point ();
            
//            for ( int i = 0; i < N; i ++ ) Poly [i].print_point ();
     return true;
}

TPos TPos :: operator + ( const TPos & B ) const
{
     TPos Ret = *this; Ret += B; return Ret;
}

TPos TPos :: operator - ( const TPos & B ) const 
{
     TPos Ret = *this; Ret -= B; return Ret;
}

TPos TPos :: operator * ( const int B ) const 
{
     TPos Ret = *this; Ret *= B; return Ret;
}

TPos TPos :: operator / ( const int B ) const
{
     TPos Ret = *this; Ret /= B; return Ret;
}

TPos TPos :: operator * ( const TPos & B ) const
{
     TPos    Ret;
     Ret.x =   y * B.l -  l * B.y;
     Ret.y =   l * B.x -  x * B.l;
     Ret.l =   x * B.y -  y * B.x;
     return Ret;
}

double TPos :: value ( const TPos & B ) const 
{
       return geta () * B.getx () + getb () * B.gety () + getl ();
}

void TPos :: print_point () const
{
     printf ( "( %.3lf , %.3lf )\n" , getx () , gety ());
}

void TPos :: print_line () const
{
     printf ( "Line ___ %.3lf x + %.3lf y + %.3lf == 0\n" , geta () , getb () , getl ());
}

// 4463295 	2006/03/31 10:13:16.777	Accepted	0:24.311	468	35374	C++	10117 - Nice Milk