// 3042713 2008-08-20 11:48:59 Accepted 1693 C++ 00:00.04 872K 呆滞的慢板 

// 模拟...有一定的规则:
    
// 记录整个图的邻接表，记录每个顶点的剩余度

// 记录各个高度的顶点，然后在线更新...

// 先插入第一个点

// 如果输入为正，在当前最高的顶点后面接一个顶点

// 如果输入为负，在当前最高节点与他的第 -x 个祖先连一条边

// 注意维护剩余度表 
 
// 然后，每次输入之后，弹出所有当前没有剩余度的最高顶点 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int     T,  now;

vector<vector<int> >    V;

vector<int>     deg,    hgt;

int main() {
    
    for( cin >> T; T--; ) {
        
        cin >> now;
        
        V.assign( 1, vector<int>( 0 ) );
        
        deg.assign( 1, now );
        
        hgt.assign( 1, 0 );
        
        while( cin >> now && now ) {
            
            if( now > 0 ) {
                V.push_back( vector<int>( 0 ) );
                deg[hgt.back()] -= 1;
                deg.push_back( now - 1 );
                V.back().push_back( hgt.back() );
                V[hgt.back()].push_back( V.size() - 1 );
                hgt.push_back( V.size() - 1 );
            }

            else {
                V[hgt.back()].push_back( hgt[hgt.size() - 1 + now] );
                V[hgt[hgt.size() - 1 + now]].push_back( hgt.back() );
                deg[hgt.back()] -= 1;
                deg[hgt[hgt.size() - 1 + now]] -= 1;
            }
            
            while( hgt.size() && deg[hgt.back()] == 0 )
                hgt.pop_back();

        }
        
        for( int i = 0; i < V.size(); ++i ) {
            cout << i + 1;
            sort( V[i].begin(), V[i].end() );
            for( int j = 0; j < V[i].size(); ++j )
                cout << ' ' << V[i][j] + 1;
            puts( "" );
        }
        
    }
    
}
