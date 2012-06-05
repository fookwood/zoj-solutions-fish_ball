// 3029762 2008-08-10 20:37:26 Accepted 2992 C++ 00:00.00 860K ´ôÖÍµÄÂı°å 

#include <string>
#include <iostream>
using namespace std;

string  input;
int     cnt,    mx,     T;

int main() {
    
    cin >> T;
    getline( cin, input );
    
    for( int t = 1; t <= T; ++t ) {
        
        getline( cin, input );
        
        cnt = mx = 0;
        
        for( int i = 0; i < input.size(); ++i ) {
            switch( input[i] ) {
                case '[': mx >?= ++cnt; break;
                case ']': --cnt;
            }
        }
        
        cout << t << ' ' << ( 1 << mx ) << endl;
        
    }
    
}
