// 3014822 2008-07-30 23:27:50 Accepted 1982 C++ 00:00.02 852K 呆滞的慢板 

// 英语阅读，简单模拟题 

#include <iostream>
#include <string>
using namespace std;

int D[4][2] = {
    { 10, 0 },
    { 0, -10 },
    { -10, 0 },
    { 0, 10 }
};

int main() {

    string  s;
    
    int x,  y,  k;
    
    while( cin >> s ) {
        
        puts( "300 420 moveto\n310 420 lineto" );
        
        k = 0;
        x = 310;
        y = 420;
        
        for( int i = 0; i < s.size(); ++i ) {
            if( s[i] == 'V' )   k = ( k + 3 ) % 4;
            if( s[i] == 'A' )   k = ( k + 1 ) % 4;
            x += D[k][0];
            y += D[k][1];
            cout << x << ' ' << y << " lineto\n";
        }
        
        puts( "stroke\nshowpage" );
    
    }

} 
