// 2900818 2008-05-09 13:16:11 Accepted 1011 C++ 00:00.00 844K 呆滞的慢板

// 很经典的一道数据结构 + 搜索题，有人说用 DP，其实搜索效率更高 
// 详细解答见解题报告 

#include <cstdio>
#include <vector>
using namespace std;

vector<pair<int, int> > List[15][10];

char    Tree[3000];

int     NTA = 0;
int     N,  M,  K,  L;
int     totNode;

inline bool isValid( const int d ) {
    return  d + M >= N;
}

bool DFS( const int& signal, const int& node ) {
    
    if( node > totNode || Tree[node] == '*' )
        return  isValid( signal );

    int left = node * 2, right = node * 2 + 1;

    for( int i = 0; i < List[signal][Tree[node] - 'a'].size(); ++i ) {
        if( DFS( List[signal][Tree[node]-'a'][i].first, left ) &&
            DFS( List[signal][Tree[node]-'a'][i].second, right ) ) {
            return  true;
        }
    }
    
    return  false;
}


int main() {

    while( scanf( "%d%d%d", &N, &M ,&K ) &&
         ( N || M || K ) ) {
        
        if( NTA )   putchar( '\n' );
        printf( "NTA%d:\n", ++NTA );
        
        int     x,  y;
        for( int i = 0; i < N; ++i ) {
            for( int j = 0; j < K; ++j ) {
                List[i][j].clear();
                scanf( "%d%d", &x, &y );
                List[i][j].push_back( make_pair( x, y ) );
                while( getchar() != '\n' ) {
                    scanf( "%d%d", &x, &y );
                    List[i][j].push_back( make_pair( x, y ) );
                }
            }
        }        
        
        while( scanf( "%d", &L ) && L != -1 ) {
            
            totNode = 0;
            for( int i = 0, k = 1; i <= L; ++i ) {
                totNode += k;
                k *= 2;
            }
            
            for( int i = 1; i <= totNode; ++i ) {
                char    input[2];
                scanf( "%s", input );
                Tree[i] = *input;
            }
        
            puts( DFS( 0, 1 ) ? "Valid" : "Invalid" );
        
        }
        
    }

}
