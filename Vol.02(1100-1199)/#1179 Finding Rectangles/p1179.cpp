// 3037538 2008-08-16 11:11:41 Accepted 1179 C++ 00:00.00 872K ´ôÖÍµÄÂı°å 

// °ÔÍõÓ²ÉÏ¹­... 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Point {
    char    name;
    int     x,  y;
    void    get() { cin >> name >> x >> y; }
};

bool cmpP1( Point lhs, Point rhs ) {
    return  make_pair( lhs.x, lhs.y ) <
            make_pair( rhs.x, rhs.y );
}

struct Rect {
    string  name;
    Point   p[4];
    void getname() {
        name = "     ";
        name[1] = p[1].name;
        name[2] = p[3].name;
        name[3] = p[2].name;
        name[4] = p[0].name;
    }
};

bool cmpR( Rect lhs, Rect rhs ) {
    return  lhs.name < rhs.name;
}


int             N,  T = 0;
int             idx[4];
Point           A[26];
Rect            now;
vector<Rect>    V;

int main() {
    
    while( cin >> N && N ) {
        
        for( int i = 0; i < N; ++i )
            A[i].get();
            
        sort( A, A + N, cmpP1 );
        
        V.clear();
        
        for( idx[0] = 0; idx[0] < N; ++idx[0] )
        for( idx[1] = idx[0] + 1; idx[1] < N; ++idx[1] )
        for( idx[2] = idx[1] + 1; idx[2] < N; ++idx[2] )
        for( idx[3] = idx[2] + 1; idx[3] < N; ++idx[3] ) {
            if( A[idx[0]].x == A[idx[1]].x &&
                A[idx[2]].x == A[idx[3]].x &&
                A[idx[0]].y == A[idx[2]].y &&
                A[idx[1]].y == A[idx[3]].y ) {
                for( int i = 0; i < 4; ++i )
                    now.p[i] = A[idx[i]];
                now.getname();
                V.push_back( now );
            }
        }
        
        cout << "Point set " << ++T << ":";
        
        if( V.empty() ) {
            puts( " No rectangles" );
            continue;
        }
        
        sort( V.begin(), V.end(), cmpR );
        
        for( int i = 0; i < V.size(); ++i ) {
            if( i % 10 == 0 )   puts( "" );
            cout << V[i].name;
        }
        
        puts( "" );
        
    }
    
}
