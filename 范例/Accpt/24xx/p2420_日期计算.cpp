#include <stdio.h>

const    int dday [13] = { 31 , 28, 31 , 30 ,31 ,30 ,31 ,31, 30, 31, 30,31 , 1};

int      N;

bool     moreyear ( int );
void     solve ();

main ()
{
     while ( scanf ( "%d" , &N ) , N != -1 )
           solve ();
}

void solve ()
{
     int   year = 2000 , s , month , day;
     for ( s = 0; s <= N; year ++ )
         s += moreyear ( year ) ? 366 : 365;
     
     year --;
     s -= moreyear ( year ) ? 366 : 365;
     
     for ( month = 0; s <= N; month ++ )
         if ( month == 1 && moreyear ( year ) ) s += 29;
         else s += dday [month];
     month --;
     if ( month == 1 && moreyear ( year )) s -= 29;
     else s -= dday [month];
     
     day = N - s;
     printf ( "%d-%02d-%02d " , year , month + 1 , day + 1 );
     switch ( N % 7 ) {
            case 0 : printf ( "Saturday\n" ); break;
            case 1 : printf ( "Sunday\n" ); break;
            case 2 : printf ( "Monday\n" ); break;
            case 3 : printf ( "Tuesday\n" ); break;
            case 4 : printf ( "Wednesday\n" ); break;
            case 5 : printf ( "Thursday\n" ); break;
            case 6 : printf ( "Friday\n" ); break;
     }
}

bool moreyear ( int K )
{
     return K % 100 ? K % 4 == 0 : K % 400 == 0;
}
