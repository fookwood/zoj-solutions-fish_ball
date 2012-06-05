#include <cstdio>
#include <cstdlib>
#include <vector>
using std::vector;

struct  Point {
    int     x,  y;
    bool    B[16];
    int     remain;
    Point(int x = 0, int y = 0) :
        x(x), y(y), remain(0)
        { memset( B, 1, 16 ); }
};

char    A[16][17];

vector<Point>   V;

bool    finish;

inline bool same( const Point& p1, const Point& p2 ) {
    return  p1.x == p2.x || p1.y == p2.y ||
            p1.x / 4 == p2.x / 4 && p1.y / 4 == p2.y / 4;
}

void DFS( int grade ) {
    
    if( grade == V.size() ) {
        finish = true;
        return;
    }
    
    int     pos = -1;
    
    for( int i = 0; i < V.size(); i++ )
        if( A[V[i].x][V[i].y] == '-' &&
            ( pos == -1 || V[i].remain < V[pos].remain ) )
                pos = i;

    for( int i = 0; i < 16; i++ ) {
        vector<int> trace( 0 );
        if( V[pos].B[i] ) {
            A[V[pos].x][V[pos].y] = 'A' + i;
            for( int j = 0; j < V.size(); j++ ) {
                if( A[V[j].x][V[j].y] == '-' && same( V[j], V[pos] ) ) {
                    if( V[j].B[i] ) {
                        trace.push_back( j );
                        V[j].B[i] = false;
                        V[j].remain--;
                    }
                }
            }
            DFS( grade + 1 );
            if( finish )    return;
            for( int j = 0; j < trace.size(); j++ ) {
                V[trace[j]].B[i] = true;
                V[trace[j]].remain++;
            }
            A[V[pos].x][V[pos].y] = '-';
        }
    }
}

int main() {
    
    int     T;
    
    scanf( "%d", &T );
    
    while( T-- ) {
        
        for( int i = 0; i < 16; i++ )
            scanf( "%s", A[i] );

        V.resize( 0 );
        for( int i = 0; i < 16; i++ ) {
            for( int j = 0; j < 16; j++ ) {
                if( A[i][j] == '-' ) {
                    V.push_back( Point( i, j ) );
                    for( int m = 0; m < 16; m++ ) {
                        if( A[i][m] != '-' )
                            V.back().B[A[i][m]-'A'] = false;
                        if( A[m][j] != '-' )
                            V.back().B[A[m][j]-'A'] = false;
                    }
                    int posx = i - i % 4;
                    int posy = j - j % 4;
                    for( int m = 0; m < 4; m++ )
                        for( int n = 0; n < 4; n++ )
                            if( A[posx+m][posy+n] != '-' )
                                V.back().B[A[posx+m][posy+n]-'A'] = false;
                    for( int m = 1; m < 16; m++ )
                        V.back().remain += V.back().B[m];
                }
            }
        }

        finish = false;
        DFS( 0 );

        for( int i = 0; i < 16; i++ )
            puts(A[i]);
    }
}
