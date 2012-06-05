// Floyd!!
// 规模很小，因此很好处理 
// 2822103 2008-04-04 01:15:04 Accepted 1221 C++ 00:00.01 840K 呆滞的慢板 
#include <iostream>
using namespace std;

int main() {
    int     A[21][21],  T = 1,  N;
    while( cin >> N ) {
        for( int i = 1; i <= 20; i++ )
            for( int j = 1; j <= 20; j++ )
                A[i][j] = 0;
        int     x,  y;
        for( int x = 1; x < 20; x++ ) {
            if( x > 1 )cin >> N;
            while( N-- ) {
                cin >> y;
                A[x][y] = A[y][x] = 1;
            }
        }
        for( int k = 1; k <= 20; k++ ) {
            for( int i = 1; i <= 20; i++ ) {
                for( int j = 1; j <= 20; j++ ) {
                    if( A[i][k] && A[k][j] &&
                            ( !A[i][j] || A[i][k] + 
                            A[k][j] < A[i][j] ) ) {
                        A[i][j] = A[i][k] + A[k][j];
                    }
                }
            }
        }
        cin >> N;
        cout << "Test Set #" << T++ << endl;
        while( N-- ) {
            cin >> x >> y;
            cout << x << " to " << y << ": " << A[x][y] << endl;
        }
        cout << endl;
    }
}
