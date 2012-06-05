#include <iostream>

using namespace std;

long long A , B , C , Fib [50];

void init ();
void solve ();
void change_int ( char * , long long & );
void change_fib ( char * , long long );

main ()
{
     init ();
     solve ();
}

void change_int ( char *p , long long & d )
{
     int len = strlen ( p );
     d = 0;
     for ( int i = 0; i < len; i ++ ) if ( p [i] == '1' )
         d += Fib [len - i - 1];
}

void change_fib ( char *p , long long d )
{
     if ( d == 0 ) { p [0] = '0'; p [1] = '\0'; return; }
     int len;
     for ( len = 0; Fib [len] <= d; len ++ );
//     printf ( "len = %d\n" , len );
     for ( int i = len - 1; i >= 0; i -- ) if ( d >= Fib [i] )
         p [len - i - 1] = '1' , d -= Fib [i];
     else p [len - i - 1] = '0';
     p [len] = '\0';
}

void solve ()
{
     char  Num1 [100] , Num2 [100] , Num3 [100];
     int   p;
     while ( cin >> Num1 >> Num2 ) {
           change_int ( Num1 , A );
           change_fib ( Num1 , A );
           change_int ( Num2 , B );
           change_fib ( Num2 , B );
           C = A + B;
           change_fib ( Num3 , C );
           p = strlen ( Num3 ) - strlen ( Num1 );
           for ( int i = 0; i < p + 2; i ++ ) cout << ' ';
           cout << Num1 << endl;
           p = strlen ( Num3 ) - strlen ( Num2 );
           cout << '+';
           for ( int i = 0; i < p + 1 ; i ++ ) cout << ' ';
           cout << Num2 << endl;
           cout << "  ";
           p = strlen ( Num3 );
           for ( int i = 0; i < p; i ++ ) cout << '-'; cout << endl;
           cout << "  " << Num3 << endl << endl;
     }
}

void init ()
{
     Fib [0] = 1, Fib [1] = 2;
     for ( int i = 2; i < 45; i ++ ) Fib [i] = Fib [i - 1] + Fib [i - 2];
}
// 1668020 2006-03-08 19:22:20 Accepted 2306 C++ 00:00.01 840K AndyZhau 
