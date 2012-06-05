// ±ê×¼ BFS 

#include <deque>
#include <iostream>
using namespace std;

struct Move {
    Move() {}
    Move( int xx, int yy, int zz, int s ) :
        x(xx), y(yy), z(zz), step(s) {}
    int     x,  y,  z;
    int     step;
};

int     X,  Y,  Z;
int     sX, sY, sZ;
int     eX, eY, eZ;
char    A[30][30][31];
Move    temp,   next;

inline bool isFinish( const Move& mv ) {
    return  mv.x == eX && mv.y == eY && mv.z == eZ;
}

bool isValid( const Move& mv ) {
    if( mv.x < 0 || mv.x >= X ||
        mv.y < 0 || mv.y >= Y ||
        mv.z < 0 || mv.z >= Z )
        return  false;
    return  A[mv.x][mv.y][mv.z] != '#';
}

inline void mark( const Move& mv ) {
    A[mv.x][mv.y][mv.z] = '#';
}

int main() {
    deque<Move> Q;
    while( ( cin >> X >> Y >> Z ) && ( X || Y || Z ) ) {
        for( int i = 0; i < X; i++ ) {
            for( int j = 0; j < Y; j++ ) {
                cin >> A[i][j];
                for( int k = 0; k < Z; k++ ) {
                   if( A[i][j][k] == 'E' ) {
                        eX = i;
                        eY = j;
                        eZ = k;
                    }
                    if( A[i][j][k] == 'S' ) {
                        sX = i;
                        sY = j;
                        sZ = k;
                    }
                }
            }
        }
        Q.resize( 0 );
        Q.push_back( Move( sX, sY, sZ, 0 ) );
        A[sX][sY][sZ] = '#';
        while( !Q.empty() ) {
            temp = Q.front();
            Q.pop_front();
            if( isFinish( temp ) ) break;
            next = Move( temp.x + 1, temp.y, temp.z, temp.step + 1 );
            if( isValid( next ) ) { Q.push_back( next ); mark( next ); }
            next = Move( temp.x - 1, temp.y, temp.z, temp.step + 1 );
            if( isValid( next ) ) { Q.push_back( next ); mark( next ); }
            next = Move( temp.x, temp.y + 1, temp.z, temp.step + 1 );
            if( isValid( next ) ) { Q.push_back( next ); mark( next ); }
            next = Move( temp.x, temp.y - 1, temp.z, temp.step + 1 );
            if( isValid( next ) ) { Q.push_back( next ); mark( next ); }
            next = Move( temp.x, temp.y, temp.z + 1, temp.step + 1 );
            if( isValid( next ) ) { Q.push_back( next ); mark( next ); }
            next = Move( temp.x, temp.y, temp.z - 1, temp.step + 1 );
            if( isValid( next ) ) { Q.push_back( next ); mark( next ); }
        }
        if( isFinish( temp ) )
            cout << "Escaped in " << temp.step << " minute(s)." << endl;
        else
            cout << "Trapped!" << endl;
    }
}
