// 2942064 2008-06-04 19:21:08 Accepted 1928 C++ 00:00.04 832K ´ôÖÍµÄÂý°å 

// ¼òµ¥Ä£Äâ 

#include <iostream>
using namespace std;

int dist( int x, int y ) {
    return  x > y ? x - y : x - y + 40;
}

int main() {
    
    int a,  b,  c,  d,  x;
    
    while( cin >> a >> b >> c >> d &&
                ( a || b || c || d ) ) {
        
        x = 80;
        x += dist( a, b );
        x += 40;
        x += dist( c, b );
        x += dist( c, d );
        cout << 9 * x << endl;
    
    }
    
}
