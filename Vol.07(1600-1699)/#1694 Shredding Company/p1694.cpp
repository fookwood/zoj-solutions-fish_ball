// 3043348 2008-08-20 17:15:42 Accepted 1694 C++ 00:00.00 844K ¥Ù÷Õµƒ¬˝∞Â 

// ∞‘Õı”≤…œ£¨too 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int     X;
string  S;

vector<int> V,  A;

int     mx, cnt;

void DFS( int pos, int tot ) {
    if( pos == S.size() ) {
        if( tot > mx ) {
            mx = tot;
            cnt = 1;
            A = V;
        }
        else if( tot == mx ) ++cnt;
        return;
    }
    for( int len = 1; len + pos <= S.size(); ++len ) {
        int app = atoi( S.substr( pos, len ).c_str() );
        if( tot + app <= X ) {
            V.push_back( app );
            DFS( pos + len, tot + app );
            V.pop_back();
        }
    }
}

int main() {
    
    while( cin >> X >> S && ( X || S != "0" ) ) {
        
        mx = cnt = 0;
        
        V.clear();
        
        DFS( 0, 0 );
        
        if( cnt == 0 )      puts( "error" );
        else if( cnt > 1 )  puts( "rejected" );
        else {
            cout << mx;
            for( int i = 0; i < A.size(); ++i )
                cout << ' ' << A[i];
            puts( "" );
        }
        
    }
    
}
