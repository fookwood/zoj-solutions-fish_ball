// 2942250 2008-06-04 20:31:46 Accepted 1902 C++ 00:00.00 840K ´ôÖÍµÄÂý°å 

// ²é×Öµä£¬STL ÃëÉ±Ö® 

#include <map>
#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string  name;
    int     val;
    map<string, int>    M;
    map<string, int>::iterator iter;
    
    int     D,  Q;
    cin >> D >> Q; 
    
    while( D-- ) {
        cin >> name >> val;
        M[name] = val;
    }
    
    int tot = 0;
    
    while( Q && cin >> name ) {
        
        if( name == "." ) {
            cout << tot << endl;
            tot = 0;
            --Q;
            continue;
        }
        
        iter = M.find( name );
        
        if( iter != M.end() )
            tot += iter -> second;
        
    }
    
}
