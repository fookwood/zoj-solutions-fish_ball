// 3036753 2008-08-15 16:30:49 Accepted 2747 C++ 00:00.21 844K ´ôÖÍµÄÂý°å 

#include <algorithm>
#include <iostream>
using namespace std;

struct Rect { int x1, y1, x2, y2, clr; };

int     X,  Y,  N,  T = 0;

int     C[101];

int     H[202], MH;
int     W[202], MW;

Rect    R[100];

int main() {
    
    while( cin >> X >> Y && X ) {
        
        cin >> N;
        
        for( int i = MH = MW = 0; i < N; ++i ) {
            cin >> R[i].x1 >> R[i].y1 
                >> R[i].x2 >> R[i].y2 >> R[i].clr;
            H[MH++] = R[i].x1;  H[MH++] = R[i].x2;
            W[MW++] = R[i].y1;  W[MW++] = R[i].y2;
        }
        
        sort( H, H + MH );
        sort( W, W + MW );
        
        MH = unique( H, H + MH ) - H;
        MW = unique( W, W + MW ) - W;
        
        memset( C, 0, sizeof( C ) );
        
        for( int i = 1; i < MH; ++i ) {
            for( int j = 1; j < MW; ++j ) {
                for( int k = N - 1; k >= 0; --k ) {
                    if( H[i-1] >= R[k].x1 && H[i] <= R[k].x2 &&
                        W[j-1] >= R[k].y1 && W[j] <= R[k].y2 ) {
                        C[R[k].clr] += (H[i]-H[i-1])*(W[j]-W[j-1]);
                        break;
                    }
                }
            }
        }
        
        if( T++ )   puts( "" );
        cout << "Case " << T << ":" << endl;
        
        int ans = 0;
        
        for( int i = 1; i < 101; ++i ) if( C[i] ) {
            ++ans;
            cout << i << ' ' << C[i] << endl;
        }
        
        if( ans == 1 )
                puts( "There is 1 color left on the wall." );
        else    printf( "There are %d colors left on the wall.\n", ans );
        
    }
    
}
