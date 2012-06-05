// Common BFS, Exhaustive
// 2831543 2008-04-08 18:43:24 Accepted 2097 C++ 00:00.01 852K ´ôÖÍµÄÂý°å 

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int     A[8][8];
int     sta[8][8][4];

struct Move {
    int x,  y;
    int sum;
    int status;
    Move( int x = 0, int y = 0, int sum = 0, int status = 1 ) :
        x(x), y(y), sum(sum), status(status) {}
    bool isInside(){ return  x >= 0 && x < 8 && y >= 0 && y < 8; }
    bool isValid() { return  sum < sta[x][y][status - 1]; }
};

int main() {
    int     x1, y1, x2, y2;
    while( ( cin >> x1 >> y1 >> x2 >> y2 ) &&
           ( x1 || x2 || y1 || y2 ) ) {
        for( int i = 0; i < 8; i++ ) {
            for( int j = 0; j < 8; j++ ) {
                cin >> A[i][j];
                for( int s = 0; s < 4; s++ )
                    sta[i][j][s] = 0x7fffffff;
            }
        }
        x1--; y1--; x2--; y2--;
        deque<Move> Q( 1, Move( x1, y1, 0, 1 ) );
        sta[x1][y1][0] = 0;
        const int step[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        while( !Q.empty() ) {
            Move now = Q.front(),   temp;
            int cost;
            Q.pop_front();
            for( int i = 0; i < 4; i++ ) {
                temp = now;
                temp.x += step[i][0];
                temp.y += step[i][1];
                if( temp.isInside() ) {
                    temp.sum += ( cost = A[temp.x][temp.y] * temp.status );
                    temp.status = cost % 4 + 1;
                    if( temp.isValid() ) {
                        Q.push_back( temp );
                        sta[temp.x][temp.y][temp.status - 1] = temp.sum;
                    }
                }
            }
        }
        cout << min( min( sta[x2][y2][0], sta[x2][y2][1] ),
                     min( sta[x2][y2][2], sta[x2][y2][3] ) ) << endl;
    }
}
