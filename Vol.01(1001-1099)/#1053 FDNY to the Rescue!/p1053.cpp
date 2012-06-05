// 3004581 2008-07-25 15:54:29 Accepted 1053 C++ 00:00.01 884K 呆滞的慢板 

// 最短路，带路径保存的 Floyd 

// 两个很 ws 的地方：
// 1. 两点间距离 P[i][j] 即使 i != j 也会等于 0
// 2. 所有分隔用 '\t' 包括第一行 

#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int T,  N,  X,  Y;

int P[21][21],  C[21][21];

struct Path {
    int v,  w,  t;
    vector<int> path;
};

bool operator < ( Path p1, Path p2 ) {
    return  p1.t < p2.t;
}

vector<Path>    V;

int main() {
    
    for( cin >> T; T--; ) {
        
        cin >> N;
        
        for( int i = 1; i <= N; ++i ) {
            for( int j = 1; j <= N; ++j ) {
                cin >> P[i][j];
                C[i][j] = j;
            }
        }
    
        for( int k = 1; k <= N; ++k )
            for( int i = 1; i <= N; ++i )
                for( int j = 1; j <= N; ++j )
                    if( P[i][k] >= 0 && P[k][j] >= 0 &&
                       ( P[i][j] == -1 || P[i][j] > P[i][k] + P[k][j] ) ) {
                        P[i][j] = P[i][k] + P[k][j];
                        C[i][j] = C[i][k];
                    }
                    
        V.clear();
        
        cin >> X;
        string  input;
        getline( cin, input );
        istringstream is( input );
        
        while( is >> Y ) {
            V.push_back( Path() );
            V.back().v = Y;
            V.back().w = X;
            V.back().t = P[Y][X];
            V.back().path.push_back( Y );
            while( Y != X ) {
                Y = C[Y][X];
                V.back().path.push_back( Y );
            }
            while( cin.peek() == ' ' ) getchar();
        }
        
        sort( V.begin(), V.end() );
        
        puts( "Org\tDest\tTime\tPath" );
        for( int i = 0; i < V.size(); ++i ) {
            cout << V[i].v << '\t';
            cout << V[i].w << '\t';
            cout << V[i].t;
            for( int j = 0; j < V[i].path.size(); ++j )
                cout << '\t' << V[i].path[j];
            puts( "" );
        }
        
        if( T ) puts( "" );
        
    }
    
}
