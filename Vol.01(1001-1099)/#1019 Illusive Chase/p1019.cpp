// 3010907 2008-07-28 18:32:35 Accepted 1019 C++ 00:00.02 932K 呆滞的慢板 

// 题目大意是机器人有一系列的指令，向四个方向走。 
// 但是走的步数可以是一个区间里面的值。 
// 地图上有若干个障碍物，问从那些点开始，有可能不碰到障碍物。 
// 输出这样的点的个数。 

// 用 DP 来解决这个问题：
// 用一个队列维护可行点，开始的时候，这个队列里面装有所有没有障碍物的点
// 然后，从最后一个指令开始，扫描队列中所有元素，得到上一轮合法的点击
// 一直做到最后，剩下的合法点个数即为输出
// 由于队列元素不能重复，因此采用 set 容器 

#include <iostream>
#include <set>
#include <cstdio> 
using namespace std; 

int     T,  M,  N;

bool    B[100][100];

int     X[100], Y[100], K;

char    D[101];

set<pair<int, int> >    S,  R;
set<pair<int, int> >::iterator  iter;

int main() {
    
    for( scanf( "%d", &T ); T--; ) {
        
        scanf( "%d%d", &M, &N );
        
        S.clear();
        
        for( int i = 0; i < M; ++i ) {
            for( int j = 0; j < N; ++j ) {
                cin >> B[i][j];
                if( !B[i][j] ) S.insert( make_pair( i, j ) );
            }
        }
        
        K = 0;
        while( scanf( "%d%d", X + K, Y + K ) && ( X[K] || Y[K] ) )
            cin >> D[K++];
            
        while( --K >= 0 ) {
        
            R.clear();
        
            int dx, dy, x,  y,  px, py;
            
            switch( D[K] ) {
                case 'D': dx = -1; dy =  0; break;
                case 'U': dx =  1; dy =  0; break;
                case 'R': dx =  0; dy = -1; break;
                case 'L': dx =  0; dy =  1; break;
            }
            
            for( iter = S.begin(); iter != S.end(); ++iter ) {
                x = iter -> first;  y = iter -> second;
                for( int i = 1; i <= Y[K]; ++i ) {
                    px = x + i * dx;
                    py = y + i * dy;
                    if( px < 0 || px >= M || py < 0 || py >= N 
                               || B[px][py] )   break;
                    if( i >= X[K] ) R.insert( make_pair( px, py ) );
                }
            }
            
            S = R;
            
        }
        
        cout << S.size() << endl;
            
    }
    
} 
