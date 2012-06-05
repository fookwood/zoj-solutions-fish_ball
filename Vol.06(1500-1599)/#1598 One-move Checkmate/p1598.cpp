// 3044806 2008-08-21 16:12:27 Accepted 1598 C++ 00:00.01 852K 呆滞的慢板 

// 直接硬搞，求出控制点预备控制点集合取交集 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string  wKing,  wQueen, bKing;

vector<string>  toMove, attack, canMove, winpos;

string  remain[64];

int dx[8] = { 0,  0,  1,  1,  1, -1, -1, -1 };
int dy[8] = { 1, -1, -1,  1,  0,  1, -1,  0 };

int main() {
    
    while( cin >> wKing >> wQueen >> bKing ) {
        
        toMove.clear();
        
        for( int i = 0; i < 8; ++i ) {
            string  now = wQueen;
            now[0] += dx[i];
            now[1] += dy[i];
            while( now[0] >= 'a' && now[0] <= 'h' &&
                   now[1] >= '1' && now[1] <= '8' &&
                   now != wKing ) {
                toMove.push_back( now );
                now[0] += dx[i];
                now[1] += dy[i];
            }
        }
        
        canMove.assign( 1, bKing );
        for( int i = 0; i < 8; ++i ) {
            string  now = bKing;
            now[0] += dx[i];
            now[1] += dy[i];
            if( now[0] >= 'a' && now[0] <= 'h' &&
                now[1] >= '1' && now[1] <= '8' && now != wKing )
                canMove.push_back( now );
        }
        
        sort( canMove.begin(), canMove.end() );
        
        winpos.clear();
        
        for( int j = 0; j < toMove.size(); ++j ) {
            attack.clear();
            for( int i = 0; i < 8; ++i ) {
                string  now = toMove[j];
                now[0] += dx[i];
                now[1] += dy[i];
                while( now[0] >= 'a' && now[0] <= 'h' &&
                       now[1] >= '1' && now[1] <= '8' &&
                       now != wKing ) {
                    attack.push_back( now );
                    now[0] += dx[i];
                    now[1] += dy[i];
                }
            }
            for( int i = 0; i < 8; ++i ) {
                string  now = wKing;
                now[0] += dx[i];
                now[1] += dy[i];
                if( now[0] >= 'a' && now[0] <= 'h' &&
                    now[1] >= '1' && now[1] <= '8' ) {
                    attack.push_back( now );
                    now[0] += dx[i];
                    now[1] += dy[i];
                }
            }
            sort( attack.begin(), attack.end() );
            
            if( set_intersection( 
                    attack.begin(), attack.end(),
                    canMove.begin(), canMove.end(),
                    remain
                ) - remain == canMove.size() ) {
                winpos.push_back( toMove[j] );
            }
        }
        
        sort( winpos.begin(), winpos.end() );
        
        if( winpos.empty() )    puts( "no" );
        else                    cout << winpos[0] << endl;

    }
    
}
