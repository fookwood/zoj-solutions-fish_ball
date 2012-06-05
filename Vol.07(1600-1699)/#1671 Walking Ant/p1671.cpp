#include <iostream>
#include <deque>
using namespace std;

struct Ant {
    Ant() {}
    Ant( int x, int y, int e, int s ) : 
        posX(x), posY(y), Energy(e), Step(s) {}
    int     posX;
    int     posY;
    int     Energy;
    int     Step;
    int     Value;
};

int     A[8][8];
int     M,  N;
Ant     temp;

bool isValid( const int& x, const int& y ) {
    if( x < 0 || x >= M || y < 0 || y >= N )
        return  false;
    if( A[x][y] == 0 )
        return  false;
    if( A[x][y] < 0 && -A[x][y] >= temp.Energy - 1 )
        return  false;
    return  true;
}

int main() {
    deque<Ant>  Q;
    while( ( cin >> N >> M ) && ( M || N ) ) {
        Q.resize( 0 );
        for( int i = 0; i < M; i++ ) {
            for( int j = 0; j < N; j++ ) {
                cin >> A[i][j];
                if( A[i][j] == 2 ) {
                    Q.push_back( Ant( i, j, 6, 0 ) );
                    A[i][j] = -6;
                }
            }
        }
        while( !Q.empty() ) {
            temp = Q.front();
            Q.pop_front();
/*
cout << "x = " << temp.posX<<  endl;
cout << "y = " << temp.posY<<  endl;
cout << "Energy = " << temp.Energy<<  endl;
cout << "Step = " << temp.Step<<  endl;
cout << "Value = " << temp.Value <<  endl;
for( int i = 0; i < M; i++ ){
for( int j = 0; j < N; j++ ){
cout.width(3);
cout << A[i][j];}cout << endl;}
system("pause");
//*/
            if( temp.Value == 3 )  break;
            A[temp.posX][temp.posY] = -temp.Energy;
            if( temp.Energy == 1 )  continue;
            if( isValid( temp.posX + 1, temp.posY ) ) {
                if( A[temp.posX + 1][temp.posY] == 4 )
                    Q.push_back( Ant( temp.posX + 1, temp.posY, 6, temp.Step + 1 ) );
                else
                    Q.push_back( Ant( temp.posX + 1, temp.posY, temp.Energy - 1, temp.Step + 1 ) );
                Q.back().Value = A[temp.posX + 1][temp.posY];
                A[temp.posX + 1][temp.posY] = -Q.back().Energy;
            }
            if( isValid( temp.posX - 1, temp.posY ) ) {
                if( A[temp.posX - 1][temp.posY] == 4 )
                    Q.push_back( Ant( temp.posX - 1, temp.posY, 6, temp.Step + 1 ) );
                else
                    Q.push_back( Ant( temp.posX - 1, temp.posY, temp.Energy - 1, temp.Step + 1 ) );
                Q.back().Value = A[temp.posX - 1][temp.posY];
                A[temp.posX - 1][temp.posY] = -Q.back().Energy;
            }
            if( isValid( temp.posX, temp.posY + 1 ) ) {
                if( A[temp.posX][temp.posY + 1] == 4 )
                    Q.push_back( Ant( temp.posX, temp.posY + 1, 6, temp.Step + 1 ) );
                else
                    Q.push_back( Ant( temp.posX, temp.posY + 1, temp.Energy - 1, temp.Step + 1 ) );
                Q.back().Value = A[temp.posX][temp.posY + 1];
                A[temp.posX][temp.posY + 1] = -Q.back().Energy;
            }
            if( isValid( temp.posX, temp.posY - 1 ) ) {
                if( A[temp.posX][temp.posY - 1] == 4 )
                    Q.push_back( Ant( temp.posX, temp.posY - 1, 6, temp.Step + 1 ) );
                else
                    Q.push_back( Ant( temp.posX, temp.posY - 1, temp.Energy - 1, temp.Step + 1 ) );
                Q.back().Value = A[temp.posX][temp.posY - 1];
                A[temp.posX][temp.posY - 1] = -Q.back().Energy;
            }
        }
        if( temp.Value == 3 ) cout << temp.Step << endl;
        else            cout << -1 << endl;
    }
}
