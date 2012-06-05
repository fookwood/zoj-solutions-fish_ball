#include <stdio.h>
#include <string.h>
#define MaxLen 200

struct   HP {
         int len , s [MaxLen];
         HP () {}
         HP ( int d ) { len = 1 , s [0] = d; }
         bool  operator <= ( const HP & B ) const {
               if ( len != B.len ) return len < B.len;
               for ( int i = len - 1; i >= 0; i -- ) if ( s [i] != B.s [i] ) return s [i] <= B.s [i];
               return true;
         }
         HP  operator - ( const HP & B );
         HP  operator / ( const HP & B );
         HP  operator % ( const HP & B );
         void  print ();
};

bool     init ();
void     solve ();
HP       Gcd ( HP , HP );

HP       A , B;

main ()
{
     bool  first = true;
     while ( init () ) {
           if ( first ) first = false; else printf ( "\n" );
           solve ();
     }
}

HP  Gcd ( HP A , HP B )
{
    if ( B.len == 1 && B.s [0] == 0 ) return A;
    return Gcd ( B , A % B );
}

void solve ()
{
     HP gcd;
     if ( A <= B ) { gcd = A; A = B; B = gcd; }
     gcd = Gcd ( A , B );
     gcd.print ();
}

bool init ()
{
     char Str1 [200] , Str2 [200];
     int  len1 , len2;
     if ( scanf ( "%s%s" , Str1 , Str2 ) == EOF ) return false;
     len1 = strlen ( Str1 ) , len2 = strlen ( Str2 );
     A.len = len1 , B.len = len2;
     
     for ( int i = 0; i < len1; i ++ ) A.s [len1 - i - 1] = Str1 [i] - '0';
     for ( int i = 0; i < len2; i ++ ) B.s [len2 - i - 1] = Str2 [i] - '0';
     return true;
}

HP HP :: operator % ( const HP & B )
{
      int i ,j; HP d ( 0 );
      for ( i = len - 1; i >=0; i -- ) {
          if ( ! ( d.len == 1 && d .s [0] == 0 )) {
               for ( j = d.len - 1; j >= 0; j -- ) d.s [j + 1] = d.s [j];
               d.len ++;
          }
          d.s [0] = s [i];
          while ( B <= d )
                d = d - B;
      }
      return d;
}

HP HP :: operator / ( const HP & B )
{
      int i , j;
      HP d ( 0 ) , c ( 0 );
      for ( i = len - 1; i >= 0; i -- ) {
          if ( ! ( d.len == 1 && d.s [0] == 0 ) ) {
               for ( j = d.len - 1; j >= 0; j -- ) d.s [j + 1] = d.s [j];
               d.len ++;
          }
          d.s [0] = s [i];
          c.s [i] = 0;
          while ( B <= d ) {
                d = d - B;
                c.s [i] ++;
          }
      }
      c.len = len; while ( c.len > 1 && c.s [c.len - 1] == 0 ) c.len --;
      return c;
}

HP HP :: operator - ( const HP & B )
{
      int i , j; 
      HP c;
      for ( i = 0 , j = 0; i < len; i ++ ) {
          c.s [i] = s [i] - j;
          if ( i < B.len ) c.s [i] -= B.s [i];
          if ( c.s [i] < 0 ) { j = 1; c.s [i] += 10; } else j = 0;
      }
      c.len = len; while ( c.len > 1 && c.s [c.len - 1] == 0 ) c.len --;
      return c;
}

void HP :: print ()
{
     for ( int i = len - 1; i >= 0; i -- ) printf ( "%d" , s [i] );
     printf ( "\n" );
}
