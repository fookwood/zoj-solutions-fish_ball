//     这道题就是要求 Sigma( i * Ci ) (i = 1 .. n) 的值最小
// { Ci } 是节点费用的一个排列，同时要满足父节点要出现在子节点前面。

//     如果没有父节点出现在子节点前面这个限制，那么答案很明显:
// 当{ Ci }按降序排列的时候，Sigma 的值是最小的。

//     当有这个限制的时候情况也是类似的。考虑某一个可行解，
// 就是{ Ci }的某一个排列。找到其中的最大值，比如为 Ck，
// 它有一个父节点比如 Cp。显然 Cp 要出现在 Ck 之前。更进一步，
// Cp 就应该出现在Ck的前一个位置。只有这样才有可能Sigma的值最小。
// 不然我们可以将Ck位置向前移动，得到一个更小的Sigma值，
// 并且不破坏上面的约束。既然Cp就出现在Ck的前一个位置，
// 那么它们其实就是连在一起的，可以最为一个整体来看。
// 这样问题的规模就有n减小到n-1。然后重复这一过程，直到所有的位置都确定下来。
// 这样我们就找到了最优解。

// 合并后的节点用他们的平均值代替 

#include <queue>
#include <iostream>
#include <vector>
using namespace std;

int     N,  R,  x,  y;
int     C[1001], A[1001], D[1001]; 
double  B[1001];
int     tot,    cnt;

priority_queue<pair<double, int> >  hp;

vector<int> V[1001];

void DFS( int v ) {
    A[v] = 1;
    D[v] = C[v];
    for( int i = 0; i < V[v].size(); ++i ) {
        DFS( V[v][i] );
        A[v] += A[V[v][i]];
        D[v] += D[V[v][i]];
    }
    B[v] = double( D[v] ) / double( A[v] );
}

int main() {
    
    while( cin >> N >> R && N ) {
    
        for( int i = 1; i <= N; ++i ) {
            cin >> C[i];
            V[i].clear();
        }

        for( int i = 1; i < N; ++i ) {
            cin >> x >> y;
            V[x].push_back( y );
        }
        
        DFS( R );

        while( !hp.empty() ) hp.pop();
        tot = cnt = 0;
        
        tot += C[R] * ++cnt;
        while( 1 ) {
            for( int i = 0; i < V[R].size(); ++i )
                hp.push( make_pair( B[V[R][i]], V[R][i] ) );
            if( hp.empty() ) break;
            R = hp.top().second;
            hp.pop();
            tot += C[R] * ++cnt;
        }
        
        cout << tot << endl;
    
    }
    
}
