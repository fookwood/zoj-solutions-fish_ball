#include <iostream>
using namespace std;

int main() {
    
    int r[16], g[16], b[16]; 
    
    for(int i = 0; i < 16; i++)
        cin >> r[i] >> g[i] >> b[i]; 
    
    long x, y, z, min, now;

    while( ( cin >> x >> y >> z ) && x >= 0 ) {

        cout << "(" << x << "," << y << "," << z << ") maps to ";

        min = 3 * 255 * 255;
        
        int rr, gg, bb;
        
        for(int i = 0; i < 16; i++) {
        
            now = ( r[i] - x ) * ( r[i] - x )
                + ( g[i] - y ) * ( g[i] - y )
                + ( b[i] - z ) * ( b[i] - z );
        
            if( now < min ) {
                min = now;
                rr = r[i];
                gg = g[i];
                bb = b[i]; 
            }
        }
        
        cout << "(" << rr << "," << gg << "," << bb << ")" << endl;
    } 
} 
