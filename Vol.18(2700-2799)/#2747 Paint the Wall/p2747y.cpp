// 3036757 2008-08-15 16:32:04 Accepted 2747 C++ 00:00.14 872K 呆滞的慢板 

//////////////////////////////////////////////////////
//                    矩形切割 v1.0                 //
///////////////////Documentation//////////////////////
//                                                  //
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
using namespace std;

int     X,  Y,  N,  T = 0;

vector<pair<int, int> > ans;

Rect    R;

RectCut rcut; 

int main() {
    
    while( cin >> X >> Y && X ) {
        
        cin >> N;
        
        rcut.clear();
        
        for( int i = 0; i < N; ++i ) {
            cin >> R.x1 >> R.y1 
                >> R.x2 >> R.y2 >> R.clr;
            rcut.insert( R );
        }
        
        if( T++ )   puts( "" );
        cout << "Case " << T << ":" << endl;
        
        ans = rcut.get_color();
        
        for( int i = 0; i < ans.size(); ++i )
            cout << ans[i].first << ' '
                 << ans[i].second << endl;
        
        if( ans.size() == 1 )
                puts( "There is 1 color left on the wall." );
        else    printf( "There are %d colors left on the wall.\n", ans.size() );
        
    }
    
}
