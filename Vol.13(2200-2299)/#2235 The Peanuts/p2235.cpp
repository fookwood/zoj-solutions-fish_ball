// 2925302 2008-05-20 20:10:27 Accepted 2235 C++ 00:00.17 936K ´ôÖÍµÄÂý°å 

// ¼òµ¥Ä£Äâ 

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct PeaNut {
    
    int x,  y,  val;
    
    PeaNut() {}
    
    PeaNut( int x, int y, int val ) :
        x(x), y(y), val(val) {}
    
};

bool operator < ( const PeaNut& p1, const PeaNut& p2 ) {
    return  p1.val > p2.val;
}

int main() {
    
    int T,  X,  Y,  Time,   val;
    
    vector<PeaNut>  V;
    
    for( cin >> T; T--; ) {
        
        cin >> X >> Y >> Time;
        
        V.clear();
        
        for( int x = 0; x < X; ++x ) {
            for( int y = 0; y < Y; ++y ) {
                cin >> val;
                if( val )   V.push_back( PeaNut( x, y, val ) );
            }
        }
        
        sort( V.begin(), V.end() );
        
        int tm = V[0].x + 3, tot = V[0].val;
        
        if( tm + V[0].x > Time ) {
            puts( "0" );
            continue;
        }
        
        for( int i = 1; i < V.size(); ++i ) {
            tm += ( abs( V[i].x - V[i-1].x ) +
                    abs( V[i].y - V[i-1].y ) + 1 );
            if( tm + V[i].x > Time ) break;
            tot += V[i].val;
        }
        
        cout << tot << endl;
        
    }
    
}
