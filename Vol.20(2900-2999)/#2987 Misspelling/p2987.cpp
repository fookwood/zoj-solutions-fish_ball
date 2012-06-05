// 2954543 2008-06-22 12:05:46 Accepted 2987 C++ 00:00.00 848K ´ôÖÍµÄÂı°å 

// Ò»¸ö×Ö£ºÈâ 

#include <string>
#include <iostream>
using namespace std;

int main() {
    
    int     N,  X;
    string  str;
    
    cin >> N;
    
    for( int i = 1; i <= N; ++i ) {
        cin >> X >> str;
        str.erase( X - 1, 1 );
        cout << i << ' ' << str << endl;
    }
    
}
