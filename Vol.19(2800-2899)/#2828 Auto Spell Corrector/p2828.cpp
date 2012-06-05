// 2844064 2008-04-14 20:21:26 Accepted 2828 C++ 00:00.03 860K ´ôÖÍµÄÂý°å  

// ¼òµ¥£¬ÉÆÓÃ STL

#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int main() {
    set<string> S;
    vector<string> V;
    int     T,  D,  Q;
    cin >> T;
    string  str,    temp;
    while( T-- ) {
        cin >> D;
        S.clear();
        for( int i = 0; i < D; i++ ) {
            cin >> str;
            S.insert( str );
        }
        cin >> Q;
        for( int i = 0; i < Q; i++ ) {
            V.resize( 0 );
            cin >> str;
            if( S.find( str ) != S.end() )
                cout << str << endl;
            else {
                for( int i = 1; i < str.size(); i++ ) {
                    temp = str;
                    char    c = temp[i];
                    temp[i] = temp[i - 1];
                    temp[i - 1] = c;
                    if( S.find( temp ) != S.end() )
                        V.push_back( temp );
                }
                sort( V.begin(), V.end() );
                for( int j = 1; j < V.size(); j++ )
                    cout << V[j - 1] << ',';
                if( V.empty() )
                    cout << str << endl;
                else
                    cout << V.back() << endl;
            }
        }
        if( T ) cout << endl;
    }
}
