// 3049946 2008-08-25 15:33:23 Accepted 1893 C++ 00:00.01 980K 呆滞的慢板 

// 博弈，找必输点记忆化搜索，在这之前必须状态压缩

// 因为事实上所有可以达到的数都是仅有 2 3 5 7 为因子的数

// 而给出的范围内，这样的数仅仅有几千个，生成所有这些数并排序 

// 然后就可以记忆化搜索了，找后继状态的时候可以先把数生成出来在二分查找 

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long i64;

vector<i64> V( 0 );

i64 D[4] = { 2, 3, 5, 7 };

i64 MX = 4294967295ll;

void DFS( i64 x, int bg ) {
    if( x > MX )    return;
    V.push_back( x );
    for( int i = bg; i < 4; ++i )
        DFS( x * D[i], i );
}

i64     x;
    
size_t  pos;

vector<bool>    found,  win;

bool getval( int p ) {
    if( found[p] )  return  win[p];
    found[p] = true;
    if( V[p] * 9 >= x ) return  win[p] = true;
    bool ans = false;
    for( i64 i = 2; i <= 9; ++i ) {
        if( !getval( lower_bound( V.begin(), V.end(), V[p]*i ) - V.begin() ) ) {
            ans = true;
            break;
        }
    }
    return  win[p] = ans;
}

int main() {
    
    DFS( 1, 0 );
    
    sort( V.begin(), V.end() );
    
    while( cin >> x ) {
        pos = lower_bound( V.begin(), V.end(), x )
                - V.begin() - 1;
        found.assign( pos, false );
        win.assign( pos, false );
        puts( getval( 0 ) ? "Stan wins." : "Ollie wins." );
    }
    
}
