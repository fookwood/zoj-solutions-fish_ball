// 3027029 2008-08-07 20:45:33 Accepted 1576 C++ 00:03.32 2864K 呆滞的慢板 

// 经典的稳定婚配问题，求婚-拒绝算法 

#include <map>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

map<string, int>    man_idx,    woman_idx;

string  man[500],   woman[500];

int man_cnt,    woman_cnt;

// M[i][j] 是第 i 个男生第 j 个优先的女生
// W[i][j] 是第 i 个女生对第 j 个男生的优先级 
int M[500][500],    W[500][500];
int m_match[500],   w_match[500];
int first[500], N,  x,  y;


int add_man( string name ) {
    if( man_idx.find( name ) == man_idx.end() ) {
        man[man_cnt] = name;
        return  man_idx[name] = man_cnt++;
    }
    return  man_idx[name];
}

int add_woman( string name ) {
    if( woman_idx.find( name ) == woman_idx.end() ) {
        woman[woman_cnt] = name;
        return  woman_idx[name] = woman_cnt++;
    }
    return  woman_idx[name];
}


int main() {
    
    while( cin >> N ) {
        
        man_idx.clear();
        woman_idx.clear();
        man_cnt = woman_cnt = 0;
        
        string  input;
        
        for( int i = 0; i < N; ++i ) {
            cin >> input;
            x = add_man( input );
            for( int j = 0; j < N; ++j ) {
                cin >> input;
                y = add_woman( input );
                M[x][j] = y;
            }
        }
        
        for( int i = 0; i < N; ++i ) {
            cin >> input;
            x = add_woman( input );
            int X[500];
            for( int j = 0; j < N; ++j ) {
                cin >> input;
                y = add_man( input );
                X[j] = y;
            }
            for( int j = 0; j < N; ++j )
                W[x][X[j]] = j;
        }
        
        memset( m_match, -1, sizeof( m_match ) );
        memset( w_match, -1, sizeof( w_match ) );
        memset( first, 0, sizeof( first ) );
        
        bool    yes = true;
        while( true ) {
            bool    mark = true;
            int     i;
            for( i = 0; i < N; ++i ) {
                if( m_match[i] == -1 ) {
                    while( first[i] < N ) {
                        int j = M[i][first[i]];
                        if( w_match[j] == -1 ) {
                            m_match[i] = j;
                            w_match[j] = i;
                            break;
                        }
                        if( W[j][i] < W[j][w_match[j]] ) {
                            m_match[w_match[j]] = -1;
                            first[w_match[j]]++;
                            m_match[i] = j;
                            w_match[j] = i;
                            break;
                        }
                        ++first[i];
                    }
                    if( m_match[i] == -1 )  mark = false;
                    break;
                }
            }
            if( i == N )    break;
            if( !mark ) {
                yes = false;
                break;
            }
        }
        
        if( !yes )  puts( "Impossible" );
        else {
            for( int i = 0; i < N; ++i )
                cout << man[i] << ' '
                     << woman[m_match[i]] << endl;
        }
        
    }
    
}
