// 2932978 2008-05-26 00:13:55 Accepted 1825 C++ 00:00.25 1408K 呆滞的慢板 

// 二分，注意所有可能重复的情况 

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    
    vector<string>  V;
    set<string>     Exist;
    
    string  str;
    
    while( cin >> str )
        V.push_back( str );
        
    for( int i = 0; i < V.size(); ++i ) {
        for( int j = i + 1; j < V.size(); ++j ) {
            if( V[j].find( V[i] ) != 0 )
                break;
            str = V[j].substr( V[i].size() );
            if( binary_search( V.begin(), V.end(), str ) )
                Exist.insert( V[j] );
        }
    }
    
    for( set<string>::iterator it = Exist.begin();
         it != Exist.end(); ++it )
        cout << *it << endl;
    
//    while(1);
}
