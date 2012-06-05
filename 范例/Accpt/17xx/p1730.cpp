#include <stdio.h>

int main(int argc, char *argv[])
{
    int      total , n;
    for ( scanf ( "%d" , &total ); total; total -- )
        scanf ( "%d" , &n ) , printf ( "%d\n" , n / 2 * ( ( n - 1 ) / 2 ) );
}
