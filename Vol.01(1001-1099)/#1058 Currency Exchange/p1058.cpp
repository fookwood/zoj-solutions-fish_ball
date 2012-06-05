// New Edition
// Elf
// 2008-1-6
#include <iostream>
#include <vector> 
#include <cmath> 
using namespace std; 

int main() {
    int     T,  N;
    float   rate[5][5]; 
    cin >> T;
    while( T-- ) {
        for( int i = 0; i < 5; i++ )
            for( int j = 0; j < 5; j++ )
                cin >> rate[i][j]; 
        while( ( cin >> N ) && N ) {
            vector<int> path( 1, 0 );
            while(N--) {
                int x;
                cin >> x; 
                path.push_back( x - 1 ); 
            }
            path.push_back( 0 );
            float   money;
            cin >> money;
            for(int i = 1; i < path.size(); i++) {
                money = money * rate[path[i - 1]][path[i]]; 
                money = round( money * 100 ) / 100; 
            }
            cout.setf( ios::fixed );
            cout.precision( 2 );
            cout << money << endl; 
        }
        if( T ) cout << endl; 
    } 
} 
