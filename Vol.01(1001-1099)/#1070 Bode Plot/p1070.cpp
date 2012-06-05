#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    double  VS, R,  C,  VR, w;
    
    int n,  i;
    
    cin >> VS >> R >> C >> n;
    
    for( i = 0; i < n; i++ ) {
        cin >> w;
        VR = R / hypot( R, 1.0 / C / w );
        cout.precision( 3 );
        cout.setf( ios::fixed );
        cout << VR << endl;
    }

}
