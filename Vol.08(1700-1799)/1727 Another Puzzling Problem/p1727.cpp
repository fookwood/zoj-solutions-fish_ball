#include <string>
#include <vector>
#include <iostream>
using namespace std;


struct Image {

    vector<string>  V;
    int     P[4];

    void input( int sz ) {
        V.resize( sz );
        for( int x = 0; x < sz; x++ )
            getline( cin, V[x] );
        cin >> P[0] >> P[1] >> P[2] >> P[3];
        while( getchar() != '\n' );
        while( getchar() != '\n' );
    }
    
};


Image*  G[10][10];
vector<Image> Piece;
vector<bool>  Flag;
int     X,  Y,  D,  D2;


bool DFS( const int& x, const int& y ) {

    if( x == D + 1 ) return  true;

    int topBound  = ( x == 0 ? 0 : G[x-1][y] -> P[2] );
    int leftBound = ( y == 0 ? 0 : G[x][y-1] -> P[3] );
    int xNext = x + ( y + 1 ) / D;
    int yNext = ( y + 1 ) % D;
    
    for( int i = 0; i < D2; i++ ) {
        if( !Flag[i] && Piece[i].P[0] ==  -topBound &&
                        Piece[i].P[1] == -leftBound ) {
            Flag[i] = true;
            G[x][y] = &Piece[i];
            if( DFS( x + ( y + 1 ) / D,
                         ( y + 1 ) % D ) )
                return  true;
            Flag[i] = false;
        }
    }
    
    return  false;
    
}


int main() {

    while( cin >> D >> X >> Y ) {

        getchar();
        D2 = D * D;
        Piece.resize( D2 );
        Flag.resize( D2, false );

        for( int i = 0; i < D2; i++ ) 
            Piece[i].input( X );

        DFS( 0, 0 );

        for( int i = 0; i < D; i++ )
            for( int x = 0; x < X; x++, putchar( '\n' ) )
                for( int j = 0; j < D; j++ )
                    cout << G[i][j] -> V[x];

    }

}
