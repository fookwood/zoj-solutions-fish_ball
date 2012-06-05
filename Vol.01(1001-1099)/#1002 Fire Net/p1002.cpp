// »ù´¡ DFS
// 2840332 2008-04-12 17:27:43 Accepted 1002 C++ 00:00.00 836K ´ôÖÍµÄÂý°å  

#include <iostream>
using namespace std;

int     N,  maxVal;
char    A[4][5];

void DFS( const int& x, const int& y, const int& count ) {
    maxVal = count > maxVal ? count : maxVal;
    if( x >= N )            return;
    if( A[x][y] == 'X' )    DFS( x+(y+1)/N, (y+1)%N, count );
    else {
        bool    yes = true;
        for( int i = x - 1; i >= 0 && A[i][y] != 'X'; i-- )
            if( A[i][y] == 'Y' )
                yes = false;
        for( int j = y - 1; j >= 0 && A[x][j] != 'X'; j-- )
            if( A[x][j] == 'Y' )
                yes = false;
        for( int i = x + 1; i < N && A[i][y] != 'X'; i++ )
            if( A[i][y] == 'Y' )
                yes = false;
        for( int j = y + 1; j < N && A[x][j] != 'X'; j++ )
            if( A[x][j] == 'Y' )
                yes = false;
        if( yes ) {
            A[x][y] = 'Y';
            DFS( x+(y+1)/N, (y+1)%N, count + 1 );
            A[x][y] = '.';
        }
        DFS( x+(y+1)/N, (y+1)%N, count );
    }
}

int main() {
    while( ( cin >> N ) && N ) {
        for( int i = 0; i < N; i++ )
            cin >> A[i];
        maxVal = 0;
        DFS( 0, 0, 0 );
        cout << maxVal << endl;
    }
}
