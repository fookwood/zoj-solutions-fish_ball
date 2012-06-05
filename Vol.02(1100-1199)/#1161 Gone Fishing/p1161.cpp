// 3045332 2008-08-21 23:37:55 Accepted 1161 C++ 00:00.25 848K ´ôÖÍµÄÂý°å 

// ¾­µäÌ°ÐÄ 

#include <iostream>
#include <vector>
using namespace std;

int L,  T,  C,  CS;

int X[25],  Y[25],  P[25],  R[25];

int main() {
    
    for( cin >> CS; CS--; ) {
    
        C = 0;
        
        while( cin >> L && L ) {
        
            cin >> T;
        
            if( C++ )   puts( "" );
        
            for( int i = 0; i < L; ++i )
                cin >> X[i];
        
            for( int i = 0; i < L; ++i )
                cin >> Y[i];
            
            P[0] = 0;
            for( int i = 1; i < L; ++i )
                cin >> P[i];
            
            int mx = 0, temp, rem;
            vector<int> ans( L, 0 ),    now;
            ans[0] = T * 60;
        
            for( int l = 1; l <= L; ++l ) {
                rem = T * 60;
                for( int i = 0; i < l; ++i )
                    rem -= 5 * P[i];
                if( rem <= 0 ) break;
                now.assign( L, 0 );
                for( int i = 0; i < l; ++i ) R[i] = X[i];
                temp = 0;
                while( rem > 0 ) {
                    int mmx = 0, mpos = 0;
                    for( int i = 0; i < l; ++i ) {
                        if( R[i] > mmx ) {
                            mmx = R[i];
                            mpos = i;
                        }
                    }
                    now[mpos] += 5;
                    rem -= 5;
                    temp += R[mpos];
                    R[mpos] -= Y[mpos];
                    R[mpos] >?= 0;
                }
                if( temp > mx ) {
                    mx = temp;
                    ans = now;
                }
            }
        
            cout << ans[0];
            for( int i = 1; i < ans.size(); ++i )
                cout << ", " << ans[i];
            cout << "\nNumber of fish expected: " << mx << endl;
            
        }
        
        if( CS )    puts( "" );
        
    }
    
}
