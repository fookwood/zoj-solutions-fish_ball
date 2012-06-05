#include <cstdio>
#include <cmath>
using namespace std;

int Sign( const double& num ) {
    if( fabs( num ) < 1e-5 ) return 0;
    if( num > 1e-5 )         return 1;
    if( num < -1e-5 )        return 2;
}

int main() {
    
    double  DP[21][2],  R[21][3],   S[3][3];
    double  mean;
    
    double  P[3][3] =
    { { .0625,  .125, .0625 },
      {  .125,   .25,  .125 },
      { .0625,  .125, .0625 } };
    
    double  C[3][3] =
    { {  1.0,  2.0,  3.0 },
      { -1.0,  0.0,  1.0 },
      { -3.0,  0.0,  1.0 } };
    
    for( int i = 1; i < 21; ++i ) {

        for( int x = 0; x < 3; ++x ) {
            for( int y = 0; y < 3; ++y ) {
                S[x][y] = mean + C[x][y];
                switch( Sign( S[x][y] ) ) {
                    case 1:
                        R[i][0] += P[x][y];
                    break;
                    case -1:
                        R[i][1] += P[x][y];
                    break;
                    case 0:
                        R[i][2] += P[x][y];
                
                }
            }
        }

    }
    
}
