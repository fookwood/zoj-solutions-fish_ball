#include <stdio.h>
int main(int argc, char *argv[])
{
    int      a , b , c , d , e , f;
    while ( scanf ( "%d %d%d%d%d%d" , &a , &b , &c , &d , &e , &f ) , a || b || c || d || e || f )
          printf ( "Anna's won-loss record is %d-%d.\n" , b + d - e , a + c - f );
}
