#include <iostream>
#include <string>
using namespace std;

int main() {

    int     bean[26];
    int     share[26];
    int     totNum, totShare, totGuess;
    int     count,  guess,  T = 0;
    char    temp,   c;
    string  B;

    while( cin >> B ) {

        if( T++ )   putchar( '\n' );
        for( int i = 0; i < 26; ++i )
            bean[i] = share[i] = 0;

        for( int i = 0; B[i]; ++i )
            ++bean[B[i] - 'a'];

        cin >> totNum >> ws;
        totShare = 0;
        totGuess = 0;

        for( int i = 0; i < totNum; ++i ) {
            cin >> temp;
            count = 0;
            while( getchar() != '\n' ) {
                ++totGuess;
                cin >> ws >> c;
                getchar();
                cin >> guess;
                if( guess == bean[c - 'a'] - 1 ) ++count;
                if( guess == bean[c - 'a'] + 1 ) ++count;
                if( guess == bean[c - 'a'] )   ++++count;
            }
            share[temp - 'A'] = count;
            totShare += count;
        }
/*
printf("totShare = %d\n",totShare);
for( int i = 0; i < 26; ++i ) {
    printf( "%c ", 'A' + i );
}   putchar('\n');
for( int i = 0; i < 26; ++i ) {
    printf( "%d ", share[i] );
}   putchar('\n');
printf("totNum = %d\n",totNum);
*/
        for( int i = 0; i < 26; ++i ) {
            if( share[i] ) {
                printf( "%c %.2lf\n", 'A' + i,
                    2.0 * totGuess / totShare * share[i] );
            }
        }

    }

}
