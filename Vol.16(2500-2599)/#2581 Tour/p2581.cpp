// 3011714 2008-07-29 09:39:22 Accepted 2581 C++ 00:00.00 396K 呆滞的慢板 

// 题意这样：找出一条欧几里德图的最短周游回路，满足如下限制：

// 起点和终点必须在最左边的点，周游分两个阶段：
// 第一个阶段从起点往最右边的点走，只能往右边走
// 第二阶段，到达最右边的点后，只能往左走，回到起点
// 路径覆盖所有顶点，而且没有重复，找出这样的最短路
// 输入已经按 x 排好序，没有两个点具有相同 x 值

// 下面是一个 O(n) 的贪心算法：

// 修改问题的描述方式：
// 设最左边的点为源点 s，最右边的为汇点 t 
// 求 s 到 t 有且只有两条路径的情况下，最短的路径总长

// 称两条路径为 "上线" 和 "下线"，
// 这两条路径起点和终点均为 s-t
// 分别记录他们的总长度，以及两条路径除 t 外倒数第二个点
// 总长度 dist，最新的点为 p1(x1, y1)，p2(x2, y2) 

// 1. 初始化两条路径为 s 直接到 t dist = 2*D(s-t)，p1 = p2 = s 
// 2. 从左到右枚举除 s 和 t 外所有顶点 p
// 3. 每枚举到一个顶点，分别将它独立加到路径的倒数第二个位置
// 4. 取操作后总路径最短的方案，将这个点更新到路径中
// 5. 最后的 dist 即为所求 


#include <cmath>
#include <cstdio>

int     N;

double  X[50],    Y[50];

double  px1,    px2,    py1,    py2,    dist;

int main() {
    
    while( scanf( "%d", &N ) != EOF ) {
        
        for( int i = 0; i < N; ++i )
            scanf( "%lf%lf", X + i, Y + i );
            
        dist = 2.0 * hypot( X[0]-X[N-1], Y[0]-Y[N-1] );
        px1 = px2 = X[0];
        py1 = py2 = Y[0];
        
        for( int i = 1; i < N - 1; ++i ) {
            
            double  d1 = dist - hypot( X[N-1]-px1, Y[N-1]-py1 ),
                    d2 = dist - hypot( X[N-1]-px2, Y[N-1]-py2 );
            
            d1 += hypot( X[N-1]-X[i], Y[N-1]-Y[i] ) +
                  hypot( px1-X[i], py1-Y[i] );
            d2 += hypot( X[N-1]-X[i], Y[N-1]-Y[i] ) +
                  hypot( px2-X[i], py2-Y[i] );
                  
            if( d1 < d2 ) {
                dist = d1;
                px1 = X[i];
                py1 = Y[i];
            }
            else {
                dist = d2;
                px2 = X[i];
                py2 = Y[i];
            }
                    
        }
        
        printf( "%.2lf\n", dist ); 
         
    }
    
}
