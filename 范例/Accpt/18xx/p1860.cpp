#include <stdio.h>
#include <math.h>

char     Str [100];
double   Ax , Ay , Bx , By;

double   distance ( double X1 , double Y1 , double X2 , double Y2 )
{
 return sqrt ( ( X1 - X2 ) * ( X1 - X2 ) + ( Y1 - Y2 ) * ( Y1 - Y2 ));         
}

int main(int argc, char *argv[])
{
    bool     RunAway;
    double   X , Y , D1 , D2;
    
    while ( gets (Str) ) {
          sscanf ( Str , "%lf%lf%lf%lf" , &Ax , &Ay , &Bx , &By );
          RunAway = false;
          while ( gets ( Str ) && Str [0] ) {
                if ( RunAway ) continue;
                sscanf ( Str , "%lf%lf" , &X , &Y );
                D1 = distance ( X , Y , Ax , Ay ) , D2 = distance ( X , Y , Bx , By );
                if ( D1 * 2 <= D2 ) {
                     printf ( "The gopher can escape through the hole at (%.3lf,%.3lf).\n" , X , Y );
                     RunAway = true;
                }
          }
          if ( !RunAway ) printf ( "The gopher cannot escape.\n" );
    }
}
