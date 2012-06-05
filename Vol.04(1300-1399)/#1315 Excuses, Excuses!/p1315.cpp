// 2905334 2008-05-11 01:35:31 Accepted 1315 C++ 00:00.00 888K 呆滞的慢板 

// 比较臃肿的模拟题，还是用 STL 乱搞过了 

#include <set>
#include <sstream>
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main() {
    
    int     N,  M,  T = 1,  m_val;
    
    set<string>     D;
    vector<string>  L;
    vector<int>     V;
    string  input;
    
    
    while( cin >> N >> M ) {
        
        D.clear();
        for( int i = 0; i < N ; ++i ) {
            cin >> input;
            D.insert( input );
        }
        
        L.clear();
        V.clear();
        m_val = 0;
        cin >> ws;
        for( int i = 0; i < M; ++i ) {
            getline( cin, input );
            L.push_back( input );
            for( int i = 0; i < input.size(); ++i ) {
                if( !isalpha( input[i] ) )
                    input[i] = ' ';
                else
                    input[i] = tolower( input[i] );
            }
            istringstream   is( input );
            string  temp;
            V.push_back( 0 );
            while( is >> temp ) {
                if( D.find( temp ) != D.end() )
                ++V.back();
            }
            if( V.back() > m_val )
                m_val = V.back();
        }
        
        cout << "Excuse Set #" << T++ << endl;

        for( int i = 0; i < M; ++i )
            if( V[i] == m_val )
                cout << L[i] << endl;
        
        cout << endl;
        
    }
    
}
