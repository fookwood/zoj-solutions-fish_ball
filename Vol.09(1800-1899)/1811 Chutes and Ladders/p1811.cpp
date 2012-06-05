#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    int status[101];
    int player[5],  player_n,   np;
    vector<int> dice;
    int x,  y;
    
    while( ( cin >> x ) && x )
        dice.push_back( x );
        
    int dice_n = 0;
    
    while( cin >> np ) {
        
        fill( status, status + 101, 0 );
        
        while( ( cin >> x >> y ) && ( x || y ) )
            status[x] = y;
        
        while( ( cin >> x ) && x ) {
            if( x > 0 ) status[x] = -1;
            else        status[-x] = -2;
        }
        
        fill( player, player + np, 0 );
        
        player_n = 0;
        
        do {
            // 标记为"停走"的忽略一轮 
            if( player[player_n] < 0 ) {
                player[player_n] = -player[player_n];
                continue;
            }
            
re_throw:   player[player_n] += dice[dice_n++];
            
            if( player[player_n] >= 100 ) {
                if( player[player_n] == 100 ) {
                    --dice_n;
                    break;
                }
                else {
                    player[player_n] -= dice[--dice_n];
                    continue;
                }
            }
            
            if( !status[player[player_n]] )
                continue;
            
            if( status[player[player_n]] == -2 ) {
                player[player_n] = -player[player_n];
                continue;
            }
            
            if( status[player[player_n]] == -1 )
                goto    re_throw;
            
            player[player_n] = status[player[player_n]];
            
        } while( player_n = ( player_n + 1 ) % np, 1 );
        
        cout << player_n + 1 << endl;
        
    }
    
}
