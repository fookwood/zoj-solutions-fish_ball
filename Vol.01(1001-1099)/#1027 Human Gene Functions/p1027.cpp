// 2900339 2008-05-09 01:53:30 Accepted 1027 C++ 00:00.01 896K 呆滞的慢板 

// 经典 DP，最终 AC，类似于最长公共子串 

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int char2num( char c ) {
    switch( c ) {
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
        case '-': return 4;
    }
}

int score[5][5] = { {  5, -1, -2, -1, -3 },
                    { -1,  5, -3, -2, -4 },
                    { -2, -3,  5, -2, -2 },
                    { -1, -2, -2,  5, -1 },
                    { -3, -4, -2, -1,  0 } };

int     N1, N2,  T;
string  s1, s2;

int DP[101][101];

int main() {
    
    cin >> T;
    
    while( T-- ) {
        
        cin >> N1 >> s1 >> N2 >> s2;
        
        DP[0][0] = 0;
        for( int i = 1; i <= N1; ++i )
            DP[i][0] = DP[i-1][0] + score[4][char2num( s1[i-1] )];
        for( int j = 1; j <= N2; ++j )
            DP[0][j] = DP[0][j-1] + score[4][char2num( s2[j-1] )];
        
        for( int i = 1; i <= N1; ++i ) {
            for( int j = 1; j <= N2; ++j ) {
                DP[i][j] = max( score[4][char2num( s1[i-1] )] + DP[i-1][j],
                                score[4][char2num( s2[j-1] )] + DP[i][j-1] );
                DP[i][j] = max( DP[i][j],
                    DP[i-1][j-1] + score[char2num( s1[i-1] )][char2num( s2[j-1] )] );
            }
        }
        
        cout << DP[N1][N2] << endl;
        
    }
    
}

