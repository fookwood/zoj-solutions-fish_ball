// 1706957 2008-11-22 20:21:25 Accepted  1128 C++ 0 184 呆滞的慢板 

// 常规矩形切割。 

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
template<class T>
struct Rect { 
    T x1, y1, x2, y2;
    int clr;
    Rect() {}
    Rect( T a, T b, T c, T d, int clr ) :
        x1(a), y1(b), x2(c), y2(d), clr(clr) {}
    double area() const { return (y2-y1)*(x2-x1); }
};

const Rect<double> SENTINEL( 0, 0, 0, 0, -1 );

template<class T>
class RectCut {
    
    deque<Rect<double> >     Q;
    map<int, T>   M;
    
public:
    
    // 在队列中放置一个 sentinel 
    void clear() { Q.assign( 1, SENTINEL ); M.clear(); }
    
    void insert( T a, T b, T c, T d, int clr ) {
        insert( Rect<double>( a, b, c, d, clr ) );
    }
    
    void insert( Rect<double> r ) {
        M[r.clr] += r.area();
        Q.push_back( r );
        while( Q.front().clr != -1 ) {
            Rect<double> z = Q.front();
            Q.pop_front();
            if( z.x1 >= r.x2 || z.x2 <= r.x1 ||
                z.y1 >= r.y2 || z.y2 <= r.y1 ) {
                Q.push_back( z );
                continue;
            }
            if( z.x1 < r.x1 ) {
                Q.push_back( Rect<double>( z.x1, z.y1, r.x1, z.y2, z.clr ) );
                z.x1 = r.x1;
            }
            if( z.x2 > r.x2 ) {
                Q.push_back( Rect<double>( r.x2, z.y1, z.x2, z.y2, z.clr ) );
                z.x2 = r.x2;
            }
            if( z.y1 < r.y1 ) {
                Q.push_back( Rect<double>( z.x1, z.y1, z.x2, r.y1, z.clr ) );
                z.y1 = r.y1;
            }
            if( z.y2 > r.y2 ) {
                Q.push_back( Rect<double>( z.x1, r.y2, z.x2, z.y2, z.clr ) );
                z.y2 = r.y2;
            }
            if( ( M[z.clr] -= z.area() ) == 0 ) M.erase( M.find( z.clr ) );
        }
        Q.push_back( Q.front() );
        Q.pop_front();
    } 
    
    vector<pair<int, T> > get_color() const {
        return  vector<pair<int, T> >( M.begin(), M.end() );
    }
    
};

//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////

#include <iostream>
using namespace std;

double a, b, c, d;

int T = 1, N;
RectCut<double> RC;

int main() {
    while(cin >> N && N) {
        RC.clear();
        while(N--) {
            cin >> a >> b >> c >> d;
            RC.insert(a, b, c, d, 1);
        }
        printf("Test case #%d\n", T++);
        printf("Total explored area: %.2lf\n", RC.get_color().front().second);
        puts("");
    }
}
