// 2895475 2008-05-07 12:13:40 Accepted 1360 C++ 00:00.15 888K 呆滞的慢板 

// 经典的贪心题！！不注意必然 WA
// 下面我就不自己写了，引用一段话：

/*      下面内容来自 希赛博客 某位高手的博客
 
题目描述：以x轴为边界，x轴以上为海域，以下为大陆。
        海域里有多个点，给出点的位置。
        给出检测范围成圆形的雷达，范围半径d
        求至少要多少个雷达，才能把海域里的点全部同时检测。

题目分析：
1）贪心
2）从极端的情况开始贪心，从而构成最优解。
3）重点在：对应每个点，求出点在雷达圆上、点在圆心左侧的时候，圆心的坐标。
        从这些雷达圆心中的x轴最极端的圆心为起点（如x最小），进行贪心。

所犯错误：
1）由于是专题训练，知道了该贪心而贪心，若不知道的话就凭感觉……
2）从极端情况开始贪心。
        直观上是把点按x轴排序，以极端的点的坐标来确立贪心的起点。
        这样犯了最大错误，严重忽略了对点的y坐标的关注。

///////////  因此，排序准则应改为一个岛圆与海岸线交点 X 坐标  ////////////// 

总结：贪心算法，大胆假设，小心求证~想得容易，实现困难，一不留神，WA到你哭~ */ 

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Point { int  x,  y; double pos; };

double dist( const double& X, const Point& p ) {
    return  hypot( double( p.x ) - X, double( p.y ) );
}

bool operator < ( const Point& p1, const Point& p2 ) {
    return  p1.pos < p2.pos;
}

int main() {

    vector<Point>   V;
    int     N,  D,  C,  T = 0;
    double  X;

    while( ( cin >> N >> D ) && ( D || N ) ) {

        V.resize( N );

        bool valid = true;
        
        for( int i = 0; i < N; ++i ) {
            cin >> V[i].x >> V[i].y;
            if( V[i]. y > D )  valid = false;
            V[i].pos = double( V[i].x ) + sqrt( double( D * D - V[i].y * V[i].y ) );
        }
        
        cout << "Case " << ++T << ": ";
        
        if( !valid ) { puts( "-1" ); continue; }

        sort( V.begin(), V.end() );

        C = 1;
        X = V[0].pos;
        
        for( int i = 1; i < N; ++i ) {
            
            if( dist( X, V[i] ) > double( D ) + 1e-5 ) {
                ++C;
                X = V[i].pos;
            }
            
        }

        cout << C << endl;

    }
    
}
