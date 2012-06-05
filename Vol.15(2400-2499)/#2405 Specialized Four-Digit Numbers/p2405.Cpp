#include <iostream>
using namespace std;

int main()
{
    for( int N = 1000; N <= 9999; N++ ) {
        // Decimal
        int    sum1 = 0;
        int    temp = N;
        do {
            sum1 += temp % 10;
        } while( temp /= 10 );
        // Base-12
        int    sum2 = 0;
        temp = N;
        do {
            sum2 += temp % 12;
        } while( temp /= 12 );
        if( sum1 != sum2 )
          continue;
        // Hexadecimal
        sum2 = 0;
        temp = N;
        do {
            sum2 += temp % 16;
        } while( temp /= 16 );
        if(sum2 == sum1)
            cout << N << endl;
    } 
}
