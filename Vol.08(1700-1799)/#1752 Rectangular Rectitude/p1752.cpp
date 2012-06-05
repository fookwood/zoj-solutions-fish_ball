// 1664170 2008-10-11 22:34:26 Accepted  1752 C++ 730 184 呆滞的慢板 

// 典型矩形切割，反向染色亦可。 

//////////////////////////////////////////////////////
//                    矩形切割 v1.0                 //
///////////////////Documentation//////////////////////
//                                                  //
// 1. struct Rect:  矩形结构体，包括矩形坐标和颜色; //
// 2. clear:        清空所有矩形;                   //
// 3. insert:       插入一个矩形;                   //
// 4. get_color:    获取所有颜色的面积统计;         // 
//                                                  //
//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////

#include <deque>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// clr >= 0 为合法颜色, clr = -1 的方块为哨兵 
struct Rect { 
    int x1, y1, x2, y2, clr;
    Rect() {}
    Rect( int a, int b, int c, int d, int clr ) :
        x1(a), y1(b), x2(c), y2(d), clr(clr) {}
    int area() const { return (y2-y1)*(x2-x1); }
};

const Rect SENTINEL( 0, 0, 0, 0, -1 );

class RectCut {
public:
    deque<Rect>     Q;
    map<int, int>   M;
    
public:
    
    // 在队列中放置一个 sentinel 
    void clear() { Q.assign( 1, SENTINEL ); M.clear(); }
    
    void insert( int a, int b, int c, int d, int clr ) {
        insert( Rect( a, b, c, d, clr ) );
    }
    
    void insert( Rect r ) {
        M[r.clr] += r.area();
        Q.push_back( r );
        while( Q.front().clr != -1 ) {
            Rect    z = Q.front();
            Q.pop_front();
            if( z.x1 >= r.x2 || z.x2 <= r.x1 ||
                z.y1 >= r.y2 || z.y2 <= r.y1 ) {
                Q.push_back( z );
                continue;
            }
            if( z.x1 < r.x1 ) {
                Q.push_back( Rect( z.x1, z.y1, r.x1, z.y2, z.clr ) );
                z.x1 = r.x1;
            }
            if( z.x2 > r.x2 ) {
                Q.push_back( Rect( r.x2, z.y1, z.x2, z.y2, z.clr ) );
                z.x2 = r.x2;
            }
            if( z.y1 < r.y1 ) {
                Q.push_back( Rect( z.x1, z.y1, z.x2, r.y1, z.clr ) );
                z.y1 = r.y1;
            }
            if( z.y2 > r.y2 ) {
                Q.push_back( Rect( z.x1, r.y2, z.x2, z.y2, z.clr ) );
                z.y2 = r.y2;
            }
            if( ( M[z.clr] -= z.area() ) == 0 ) M.erase( M.find( z.clr ) );
        }
        Q.push_back( Q.front() );
        Q.pop_front();
    } 
    
    vector<pair<int, int> > get_color() const {
        return  vector<pair<int, int> >( M.begin(), M.end() );
    }
    
};

//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////


#include <iostream>
#include <algorithm>
using namespace std;

int xl, xr, yl, yr, c, C, N, T = 1;

RectCut rc;

int main() {
    while(cin >> N >> C && N) {
        rc.clear();
        for(int i = 0; i < N; ++i) {
            cin >> c >> xl >> yl >> xr >> yr;
            if(xl > xr) swap(xl, xr);
            if(yl > yr) swap(yl, yr);
            rc.insert(xl, yl, xr, yr, c);
        }
        printf("The area of color %d in dataset %d is: %d\n", C, T++, rc.M[C]);
    }
}
