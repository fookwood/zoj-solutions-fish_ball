// 3048138 2008-08-24 00:51:37 Accepted 1455 C++ 00:00.65 1000K 呆滞的慢板 

// 差分约束，把一个任务的开头和结尾都作为节点考虑
// 等号的限制分拆成两个不等号的限制 

#include <iostream>
#include <string>
using namespace std;

struct Edge { int v, w, l; };

int     N,  M,  X,  Y,  T = 0;

Edge    E[10000];

int     D[10000];

string  type;

bool bellman_ford() {
    
    memset( D, 0, sizeof( D ) );
    
    for( int t = 1; t < 2 * N; ++t ) {
        
        bool quit = true;
        
        for( int i = 0; i < M; ++i ) {
            if( D[E[i].w] > D[E[i].v] + E[i].l ) {
                quit = false;
                D[E[i].w] = D[E[i].v] + E[i].l;
            }
        }
        
        if( quit ) break;
        
    }
    
    for( int i = 0; i < M; ++i )
        if( D[E[i].w] > D[E[i].v] + E[i].l )
            return  false;
        
    int mn = D[0];
    for( int i = 1; i < N * 2; ++i )
        mn <?= D[i];
        
    for( int i = 0; i < N * 2; ++i )
        D[i] -= mn;
        
    return  true;
    
}

int main() {
    
    while( cin >> N && N ) {
        
        for( int i = 0; i < N; ++i ) {
            cin >> X;
            E[2 * i].v = 2 * i;
            E[2 * i].w = 2 * i + 1;
            E[2 * i].l = X;
            E[2*i+1].v = 2 * i + 1;
            E[2*i+1].w = 2 * i;
            E[2*i+1].l = -X;
        }
        
        M = 2 * N;
        while( cin >> type && type != "#" ) {
            cin >> X >> Y;
            --X;    --Y;
            if( type == "SAS" ) {
                E[M].v = 2 * X;
                E[M].w = 2 * Y;
                E[M].l = 0;
            }
            else if( type == "SAF" ) {
                E[M].v = 2 * X;
                E[M].w = 2 * Y + 1;
                E[M].l = 0;
            }
            else if( type == "FAS" ) {
                E[M].v = 2 * X + 1;
                E[M].w = 2 * Y;
                E[M].l = 0;
            }
            else if( type == "FAF" ) {
                E[M].v = 2 * X + 1;
                E[M].w = 2 * Y + 1;
                E[M].l = 0;
            }
            M++;
        }
        
        printf( "Case %d:\n", ++T );
        
        if( !bellman_ford() )
            puts( "impossible" );
        
        else for( int i = 0; i < N; ++i )
            cout << i + 1 << ' ' << D[i*2] << endl;
        
        puts( "" );
        
    }
    
}
