//////////////////////////////////////////////////////
//            最小公共祖先(LCA)模板 v1.0            //
///////////////////Documentation//////////////////////
//                                                  //
// 1. H:            模板参数，最大规模的二对数;     //
// 2. init:         构造新树，输入树具有的结点数;   //
// 3. insert:       插入一条树边;                   //
// 4. run:          运行预处理(之后才可以查询);     //
// 5. operator():   查询;                           //
//                                                  //
//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std; 

template<int H> 
class LCA {

    int     size,   height;
    vector<int> G[(1<<H)+1];
    int     lca[H+1][(1<<H)+1];
    int     depth[(1<<H)+1];
    
    void dfs( int v, int dph ) {
        if( height < ( depth[v] = dph ) )
            height = dph;
        for( int i = 0; i < G[v].size(); ++i )
            dfs( G[v][i], dph + 1 );
    }
    
public: 
    
    void init( int sz ) {
        size = sz;
        for( int i = 0; i < size; ++i )
            G[i].clear();
    }
    
    void insert( int x, int y ) { G[x].push_back( y ); }
    
    void run() {
        memset( lca[0], -1, sizeof( lca[0] ) );
        for( int i = 0; i <= size; ++i )
            for( int j = 0; j < G[i].size(); ++j )
                lca[0][G[i][j]] = i;
        for( int i = 0; i <= size; ++i ) {
            if( lca[0][i] == -1 && G[i].size() ) {
                depth[i] = 0;
                dfs( i, 0 );
                break;
            }
        }
        for( int i = 1; 1 << i <= height; ++i ) {
            for( int j = 0; j <= size; ++j ) {
                if( lca[i-1][j] != -1 )
                        lca[i][j] = lca[i-1][lca[i-1][j]];
                else    lca[i][j] = -1;
            }
        }
    }
    
    int operator() ( int x, int y ) const {
        if( depth[x] > depth[y] )   swap( x, y );
        int dif = depth[y] - depth[x];
        for( int i = 0; 1 << i <= dif; ++i )
            if( ( 1 << i ) & dif )
                y = lca[i][y];
        for( dif = 0; 1 << dif < depth[y]; ++dif );
        if( x == y )    return  x;
        while( dif-- ) {
            if( lca[dif][x] != lca[dif][y] ) {
                x = lca[dif][x];
                y = lca[dif][y];
            }
        }
        return  lca[0][x]; 
    }
    

}; 

//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////
