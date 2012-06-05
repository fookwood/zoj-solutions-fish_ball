// 3025221 2008-08-06 19:59:57 Accepted 1157 C++ 00:00.25 1032K 呆滞的慢板 

// 每个插头有一个类型，每个插孔有一个类型 
// 而适配器对应着类型可转换的传递闭包，生成这个传递闭包
 
// 要拿插头和插孔找最大匹配 
// 生成二分图，如果某个插头在适配器中可达某个插孔的类型，那么存在一条边 


//////////////////////////////////////////////////////////
//                 二分匹配算法类模板 v1.0              //
//////////////////////////////////////////////////////////
//                                                      //
// 求一个无权二分图的最大匹配                           //
// 1. init:     构造空匹配关系表;                       //
// 2. insert:   插入一个新的匹配关系;                   //
// 3. run:      在确定大小和匹配关系后运行计算;         //
// 4. matchCnt: 返回最大匹配数;                         // 
//                                                      //
//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////

#include <vector>
#include <algorithm>
using namespace std;
 
class BinMatch {
    
    int     X,  Y,  M; 
    vector<vector<int> >   G;
    vector<int>     back;
    vector<bool>    mark;
    
    bool find( int v ) {
        for( int i = 0, w; i < G[v].size(); ++i ) {
            w = G[v][i]; 
            if( !mark[w] ) {
                mark[w] = true;
                if( back[w] == -1 || find( back[w] ) ) {
                    back[w] = v;
                    return  true;
                }
            }
        } 
        return  false;
    }
    
public:
    
    void init( int x, int y ) {
        X = x;  Y = y; 
        G.assign( X + 1, vector<int>( 0 ) );
    } 
    
    void insert( int v, int w ) { G[v].push_back( w ); }
    
    void run() {
        back.assign( Y + 1, -1 );
        for( int v = M = 0; v <= X; ++v ) {
            mark.assign( Y + 1, false ); 
            M += find( v );
        }
    } 
    
    int matchCnt() const { return M; }
    
}; 

//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <map>
using namespace std;

BinMatch    binmatch;

int     T,  x,  y;
int     type_cnt,   receptacle_cnt,
        device_cnt, adapter_cnt;

map<string, int>    type;

string  input;

int     receptacle[100],    device[100];

bool    adapter[400][400];

int getIndex( string name ) {
    if( type.find( name ) == type.end() )
            return  type[name] = type_cnt++;
    else    return  type[name];
}

int main() {
    
    for( cin >> T; T--; ) {
        
        type_cnt = 0;
        type.clear();
        
        cin >> receptacle_cnt;
        for( int i = 0; i < receptacle_cnt; ++i ) {
            cin >> input;
            receptacle[i] = getIndex( input );
        }
        
        cin >> device_cnt;
        for( int i = 0; i < device_cnt; ++i ) {
            cin >> input >> input;
            device[i] = getIndex( input );
        }
        
        cin >> adapter_cnt;
        memset( adapter, 0, sizeof( adapter ) );
        
        for( int i = 0; i < adapter_cnt; ++i ) {
            cin >> input;
            x = getIndex( input );
            cin >> input;
            y = getIndex( input );
            adapter[x][y] = true;
        }

        // 传递闭包 
        for( int i = 0; i < type_cnt; ++i )
            for( int j = 0; j < type_cnt; ++j )
                for( int k = 0; k < type_cnt; ++k )
                    if( adapter[j][i] && adapter[i][k] )
                        adapter[j][k] = true;

        for( int i = 0; i < type_cnt; ++i )
            adapter[i][i] = true;
        
        binmatch.init( device_cnt, receptacle_cnt );
        
        for( int i = 0; i < device_cnt; ++i )
            for( int j = 0; j < receptacle_cnt; ++j )
                if( adapter[device[i]][receptacle[j]] )
                    binmatch.insert( i, j );
                    
        binmatch.run();
        
        cout << device_cnt - binmatch.matchCnt() << endl; 
        
        if( T ) puts( "" ); 

    }
    
}
