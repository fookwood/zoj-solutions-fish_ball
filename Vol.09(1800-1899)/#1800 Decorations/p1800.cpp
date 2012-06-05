// 2953653 2008-06-21 00:01:47 Accepted 1800 C++ 00:01.52 1236K 呆滞的慢板 

// 字符串 + 图 + 阶段式 DP
// 必须注意 字符串长度 > L 的情况，要输出 0 

// 将各个串的关系抽象成一个无权有向图
// 如果 串 j 可以接在 串 i 后面，那么存在有向边 G[i][j]

// 然后，问题就转化为，存在长度为 L - X + 1 的不同的路径有多少条
// 这里 L 为结果串长，X 为单个串长
// 这个时候，先查看 L - X + 1 是不是 > 0，如果不是，输出 0

// 一共有 M 个串 
// 然后，记录当前阶段到达第 i 个串的路径数目为 C[i] 
// 初值为 C[i] = 1 
// 每次在线刷新一下（松弛），重复 L - X 次 
//     刷新的办法是，先令所有 D[j] = 0，如果 C[i] != 0 且 G[i][j]
//     则下一个 D[j] += C[i]，做完之后将 D 复制回 C
// 最后，C 的求和即为结果

// 这样做的复杂度为：O(M * M * ( L - X ))，可以接受 

// 另外注意特征串只有一个字符的情况，这时候选取任何字符都无所谓
// 结果应该是 pow(M, L) 

#include <iostream>
#include <string>
#include <algorithm>
#include <set> 
using namespace std;

int     N,  L,  M,  X;

bool    G[600][600];

int     C[600], D[600];

string  S[600]; 

int pw( int base, int ep ) {
    
    if( ep == 0 )
        return  1;
    
    int a = pw( base, ep >> 1 ); 
    
    if( ep & 1 )
        return  base * a * a;
        
    else
        return  a * a; 

} 

int main() {
    
    set<string> ss;
    set<string>::iterator iter; 
    
    while( cin >> N >> L >> M && N ) {
    
        // 好像没说各个特征串会不会重复，姑且认为不会
        // 实验证明没有 
        ss.clear(); 
        for( int i = 0; i < M; ++i )
            cin >> S[i];
        
        X = S[0].size(); 
        if( X == 1 ) { 
            cout << pw( M, L ) << endl;
            continue; 
        }
        
        // 这个情况必须注意，会 WA 的 
        if( L < X ) {
            puts( "0" );
            continue;
        } 
        
        for( int i = 0; i < M; ++i )
            for( int j = 0; j < M; ++j )
                G[i][j] = S[i].substr(1) == S[j].substr(0, X-1);
        
        // 这个调试信息输出生成的有向图 
        #ifndef ONLINE_JUDGE 
        for( int i = 0; i < M; ++i ) {
            for( int j = 0; j < M; ++j )
                cout << G[i][j] << ' ';
            puts("");
        } 
        #endif 
        
        fill( C, C + M, 1 );
        for( int i = X; i < L; ++i ) {
            fill( D, D + M, 0 );
            for( int i = 0; i < M; ++i ) {
                if( C[i] ) for( int j = 0; j < M; ++j ) {
                    if( G[i][j] )
                        D[j] += C[i]; 
                }
            }
            copy( D, D + M, C ); 
        }
        
        int cnt = 0;
        
        for( int i = 0; i < M; ++i )
            cnt += C[i];
            
        cout << cnt << endl; 

    } 
    
} 
