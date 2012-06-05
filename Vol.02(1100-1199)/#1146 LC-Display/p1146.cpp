// ´ôÖÍµÄÂý°å 

#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct    digit {
    digit( int N, char num );
    void    add( digit x ); 
    void    disp();
    vector<string>    A; 
};

digit :: digit( int N, char num ) {
    A.resize( 2 * N + 3 );
    // " ----- "
    string    temp1( N + 2, '-' ); 
    temp1[0] = temp1[N + 1] = ' ';
    // "       "
    string    temp2( N + 2, ' ' );
    // "|      "
    string    temp3 = temp2;
    temp3[0] = '|';
    // "      |"
    string    temp4 = temp2;
    temp4[N + 1] = '|';
    // "|     |" 
    string    temp5 = temp2;
    temp5[N + 1] = temp5[0] = '|';
    switch( num ) {
        case '0':    for( int i = 0; i < 2 * N + 3; i++ )
                    A[i] = temp5;
                A[0] = A[2 * N + 2] = temp1;
                A[N + 1] = temp2;
                break;
        case '1':    for( int i = 0; i < 2 * N + 3; i++ )
                    A[i] = temp4;
                A[0] = A[N + 1] = A[2 * N + 2] = temp2;
                break;
        case '2':    for( int i = 1; i <= N; i++ )
                    A[i] = temp4;
                for( int i = N + 2; i < 2 * N + 3; i++ )
                    A[i] = temp3;
                A[0] = A[N + 1] = A[2 * N + 2] = temp1;
                break;
        case '3':    for( int i = 1; i < 2 * N + 3; i++ )
                    A[i] = temp4;
                A[0] = A[N + 1] = A[2 * N + 2] = temp1;
                break;
        case '4':    for( int i = 1; i <= N; i++ )
                    A[i] = temp5;
                for( int i = N + 2; i < 2 * N + 3; i++ )
                    A[i] = temp4;
                A[0] = A[2 * N + 2] = temp2;
                A[N + 1] = temp1;
                break;                
        case '5':    for( int i = 1; i <= N; i++ )
                    A[i] = temp3;
                for( int i = N + 2; i < 2 * N + 3; i++ )
                    A[i] = temp4;
                A[0] = A[N + 1] = A[2 * N + 2] = temp1;
                break;
        case '6':    for( int i = 1; i <= N; i++ )
                    A[i] = temp3;
                for( int i = N + 2; i < 2 * N + 3; i++ )
                    A[i] = temp5;
                A[0] = A[N + 1] = A[2 * N + 2] = temp1;
                break;
        case '7':    for( int i = 1; i < 2 * N + 3; i++ )
                    A[i] = temp4;
                A[0] = temp1;
                A[N + 1] = A[2 * N + 2] = temp2;
                break;
        case '8':    for( int i = 0; i < 2 * N + 3; i++ )
                    A[i] = temp5;
                A[0] = A[N + 1] = A[2 * N + 2] = temp1;
                break;
        case '9':    for( int i = 1; i <= N; i++ )
                    A[i] = temp5;
                for( int i = N + 2; i < 2 * N + 3; i++ )
                    A[i] = temp4;
                A[0] = A[N + 1] = A[2 * N + 2] = temp1;
                break;
    } 
} 

void digit :: add( digit x ) {
    for( int i = 0; i < A.size(); i++ )
        A[i] = A[i] + " " + x.A[i];
}

void digit :: disp() {
    for( int i = 0; i < A.size(); i++ )
        cout << A[i] << endl;
    cout << endl;
}

int main() {
    int    N;
    string    s;
    while( cin >> N >> s ) {
        if( !N ) break;
        digit    x( N, s[0] );
        for( int i = 1; i < s.size(); i++ )
            x.add( digit( N, s[i] ) );
        x.disp();
    } 
} 
