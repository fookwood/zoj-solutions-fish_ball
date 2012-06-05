// 3045669 2008-08-22 11:32:12 Accepted 1075 C++ 00:00.00 848K ´ôÖÍµÄÂý°å 

// ±©Á¦Ã¶¾Ù 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string  C[12];

vector<vector<string> > V;

int main() {

    int T = 0;
    
    while( cin >> C[0] ) {
        
        for( int i = 1; i < 12; ++i )
            cin >> C[i];
            
        if( T++ )   puts( "" );
        
        cout << "CARDS: ";
        
        for( int i = 0; i < 12; ++i )
            cout << ' ' << C[i];
        
        cout << endl;
        
        V.clear();
        
        for( int i = 0; i < 12; ++i ) {
            for( int j = i+1; j < 12; ++j ) {
                for( int k = j+1; k < 12; ++k ) {
                    if( ( C[i][0] != C[j][0] && C[i][0] != C[k][0] && C[j][0] != C[k][0] ||
                          C[i][0] == C[j][0] && C[i][0] == C[k][0] ) &&
                        ( C[i][1] != C[j][1] && C[i][1] != C[k][1] && C[j][1] != C[k][1] ||
                          C[i][1] == C[j][1] && C[i][1] == C[k][1] ) &&
                        ( C[i][2] != C[j][2] && C[i][2] != C[k][2] && C[j][2] != C[k][2] ||
                          C[i][2] == C[j][2] && C[i][2] == C[k][2] ) &&
                        ( C[i][3] != C[j][3] && C[i][3] != C[k][3] && C[j][3] != C[k][3] ||
                          C[i][3] == C[j][3] && C[i][3] == C[k][3] ) ) {
                        vector<string>  now( 0 );
                        now.push_back( C[i] );
                        now.push_back( C[j] );
                        now.push_back( C[k] );
                        V.push_back( now );
                    }
                    
                }
            }
        }
        
        if( V.empty() ) puts( "SETS:   *** None Found ***" );
        else {
            cout << "SETS:   1. ";
            for( int i = 0; i < 3; ++i )
                cout << ' ' << V[0][i];
            puts( "" );
            for( int i = 1; i < V.size(); ++i ) {
                cout << "        " << i + 1 << ". ";
                for( int j = 0; j < 3; ++j )
                    cout << ' ' << V[i][j];
                puts( "" );
            }
        }
        
    }
    
}
