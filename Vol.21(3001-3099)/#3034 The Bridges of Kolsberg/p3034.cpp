// 3058745 2008-09-03 20:50:05 Accepted 3034 C++ 00:00.79 8744K ´ôÖÍµÄÂý°å 

// n^2 DP£¬ÀàËÆÓÚ LCS 

#include <iostream>
#include <string>
#include <map>
using namespace std;

int T,  N,  M,  K;

map<string, int> idx;
map<string, int>::iterator it;

int addName( string s ) {
    it = idx.find( s );
    if( it != idx.end() )   return  it->second;
    return  idx[s] = K++;
}

int X1[1001],   V1[1001];
int X2[1001],   V2[1001];

string  s;
int VL[1001][1001], CNT[1001][1001];

int main() {
    
    for( cin >> T; T--; ) {
        idx.clear();
        K = 0;
        cin >> N;
        for( int i = 1; i <= N; ++i ) {
            cin >> s >> s >> V1[i];
            X1[i] = addName( s );
        }
        cin >> M;
        for( int i = 1; i <= M; ++i ) {
            cin >> s >> s >> V2[i];
            X2[i] = addName( s );
        }
        for( int i = 0; i <= N; ++i ) VL[i][M] = CNT[i][M] = 0;
        for( int i = 0; i <= M; ++i ) VL[N][i] = CNT[N][i] = 0;
        for( int i = 1; i <= N; ++i ) {
            for( int j = 1; j <= M; ++j ) {
                if( VL[i][j-1] > VL[i-1][j] ||
                    VL[i][j-1] == VL[i-1][j] &&
                    CNT[i][j-1] < CNT[i-1][j] ) {
                    VL[i][j] = VL[i][j-1];
                    CNT[i][j] = CNT[i][j-1];
                }
                else {
                    VL[i][j] = VL[i-1][j];
                    CNT[i][j] = CNT[i-1][j];
                }
                if( X1[i] == X2[j] && (
                    VL[i-1][j-1] + V1[i] + V2[j] > VL[i][j] ||
                    VL[i-1][j-1] + V1[i] + V2[j] == VL[i][j] && 
                    CNT[i-1][j-1] + 1 < CNT[i][j] ) ) {
                    VL[i][j] = VL[i-1][j-1] + V1[i] + V2[j];
                    CNT[i][j] = CNT[i-1][j-1] + 1;
                }
            }
        }
        cout << VL[N][M] << ' ' << CNT[N][M] << endl;
    }
    
}
