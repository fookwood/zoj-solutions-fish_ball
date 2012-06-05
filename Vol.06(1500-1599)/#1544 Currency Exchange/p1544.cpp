// 3009011 2008-07-27 16:39:21 Accepted 1544 C++ 00:00.04 852K 呆滞的慢板 

// 负环检测，Bellman-Ford 算法，注意有平行边 

// 注意精度... 

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

struct Edge {
    int     x,  y;
    double  r,  c; 
};

vector<Edge>    E;

int     M,  N,  P,  X,  Y;
double  V[101], C;

int main() {
    
    while( scanf( "%d%d%d%lf", &M, &N, &P, &C ) !=EOF ) {
        
        for( int i = 0 ; i <= M; ++i )
            V[i] = -1000000000;
        
        V[P] = C;
        E.resize( N * 2 );
        
        for( int i = 0; i < N; ++i ) {
            cin >> X >> Y;
            E[i].x = E[N+i].y = X;
            E[i].y = E[N+i].x = Y;
            cin >> E[i].r >> E[i].c;
            cin >> E[N+i].r >> E[N+i].c;
        }
        
        while( V[P] == C ) {
            bool flag = true;
            for( int j = 0; j < 2 * N; ++j ) {
                X = E[j].x;
                Y = E[j].y;
                if( V[X] <= 0 )  continue;
                double  val = E[j].r * ( V[X] - E[j].c );
                if( V[Y] < val - 1e-5 ) {
                    V[Y] = val;
                    flag = false;
                }
            }
            if( flag ) break;
        }

        puts( V[P] > C ? "YES" : "NO" );
    
    }
    
}
