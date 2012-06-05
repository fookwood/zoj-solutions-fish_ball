#include <queue>
#include <functional>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    
    int     S,  W,  C,  K,  M;
        
    // 一个重要的优化条款是收集同时等待的农民，压缩队列总数
    // 另一个重要的优化条款是按状态分开两个工作队列 
    
    // Q 是从工厂去矿区的队列，P 是从矿区回工厂的队列 
    priority_queue<int, vector<int>, greater<int> >  Q,  P;
    
    while( scanf( "%d%d%d%d%d", &S, &W, &C, &K, &M ) != EOF ) {
        
        while( !Q.empty() ) Q.pop();
        while( !P.empty() ) P.pop();
        
        int NowTime;
        int WaitingNum = 0;
        int MineTime = 0;
        int Resource = 10000;
        
        for( int i = 1; i <= K; ++i )
            Q.push( i * M + S );

        while( Resource > 0 ) {
            
            if(   WaitingNum > 0 &&
                ( P.empty() || MineTime <= P.top() ) &&
                ( Q.empty() || MineTime <= Q.top() ) ) {
                --WaitingNum;
                MineTime += W;
                P.push( MineTime + S );
            }
            
            else if( P.empty() || Q.top() < P.top() ) {
                NowTime = Q.top();
                Q.pop();
                if( NowTime < MineTime )
                    ++WaitingNum;
                else {
                    MineTime = NowTime + W;
                    P.push( MineTime + S );
                }
            }
            
            else if( Q.empty() || P.top() < Q.top() ) {
                NowTime = P.top();
                P.pop();
                Resource -= C;
                Q.push( NowTime + S );
            }
        
        }
        
        printf( "%d\n", NowTime );
        
    }
    
}
