// BFS，精彩，但不见得高效
// 可以基于这个打表过 
// 2806836 2008-03-28 15:16:59 Accepted 1937 C++ 00:00.64 4828K ELF 

#include <vector>
#include <deque>
#include <iostream>
using namespace std;

typedef vector<int> SEQ;

int main() {
    int     N;
    deque<SEQ>  Q;
    SEQ     temp,   store;
    while( ( cin >> N ) && N ) {
        if( N == 1 ) {
            cout << 1 << endl;
            continue;
        }
        Q.resize( 0 );
        temp.resize( 1, 1 );
        Q.push_back( temp );
        bool    exit = 0;
        while( 1 ) {
            store = Q.front();
            Q.pop_front();
            for( int i = 0; i < store.size(); i++ ) {
                temp = store;
                temp.push_back( store[i] + store.back() );
                if( temp.back() < N )
                    Q.push_back( temp );
                if( temp.back() == N ) {
                    exit = true;
                    break;
                }    
            }
            if( exit )  break;
        }
        for( int i = 0; i < temp.size(); i++ )
            cout << temp[i] << ' ';
        cout << endl;
    }
}
