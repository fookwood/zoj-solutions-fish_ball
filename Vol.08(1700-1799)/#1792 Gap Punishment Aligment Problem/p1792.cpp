// 1682332 2008-10-29 22:18:21 Accepted  1792 C++ 250 1164 ¥Ù÷Õµƒ¬˝∞Â 

// O(n^3) DP£¨¿‡À∆ LCS

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int T, DP[501][501];
string s1, s2;

const int NEG = -10000000;

inline int score(char x, char y) {
    return x == y ? 2 : -1;
}

int main() {
    
    for(cin >> T; T--;) {
        
        // input
        cin >> s1 >> s2;
        
        // initialization
        for(size_t i = 0; i <= s1.size(); ++i)
            for(size_t j = 0; j <= s2.size(); ++j)
                DP[i][j] = NEG;
        DP[0][0] = 0;
        
        // recursion
        for(size_t i = 0; i <= s1.size(); ++i) {
            for(size_t j = 0; j <= s2.size(); ++j) {
                if(i && j) {
                    DP[i][j] = max(
                        DP[i][j],
                        DP[i-1][j-1] + score(s1[i-1], s2[j-1])
                    );
                }
                int sc = -5;
                for(size_t k = i+1; k <= s1.size(); ++k, sc -= 1) {
                    DP[k][j] = max(
                        DP[k][j],
                        DP[i][j] + sc
                    );
                }
                sc = -5;
                for(size_t k = j+1; k <= s2.size(); ++k, sc -= 1) {
                    DP[i][k] = max(
                        DP[i][k],
                        DP[i][j] + sc
                    );
                }
            }
        }        
        
        // output
        cout << DP[s1.size()][s2.size()] << endl;
        
    }
    
}
