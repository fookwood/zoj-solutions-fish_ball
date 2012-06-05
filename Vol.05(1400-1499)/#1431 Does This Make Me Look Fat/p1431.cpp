// 3027345 2008-08-08 01:06:18 Accepted 1431 C++ 00:00.00 844K 呆滞的慢板 

// 弱智题，排序输出，没有 tie 的情况 

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Man {
    string  name;
    int     x,  y;
};

bool icmp( Man m1, Man m2 ) {
    return  m1.y - m1.x > m2.y - m2.x;
}

vector<Man> V;
Man         now;
string      input;

int main() {
    
    int T = 0;
    
    while( cin >> input ) {
        
        if( T++ )   puts( "" );
        
        V.clear();
        
        while( cin >> input && input != "END" ) {
            now.name = input;
            cin >> now.x >> now.y;
            V.push_back( now );
        }
        
        sort( V.begin(), V.end(), icmp );
        
        for( int i = 0; i < V.size(); ++i )
            cout << V[i].name << endl;
    
    }
    
}
