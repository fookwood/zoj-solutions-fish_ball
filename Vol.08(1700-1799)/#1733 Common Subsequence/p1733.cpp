// 2 串最长公共子序列，经典，DP
// 2830884 2008-04-08 14:22:14 Accepted 1733 C++ 00:00.00 1016K 呆滞的慢板 

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string  s1, s2;
    int     A[201][201];    
    while( cin >> s1 >> s2 ) {
        for( int i = 0; i <= s1.size(); i++ )
            A[i][0] = 0;
        for( int j = 0; j <= s2.size(); j++ )
            A[0][j] = 0;
        for( int i = 1; i <= s1.size(); i++ )
            for( int j = 1; j <= s2.size(); j++ )
                A[i][j] = max( A[i-1][j-1] + int(s1[i-1] == s2[j-1]),
                          max( A[i][j-1], A[i-1][j] ) );
        cout << A[s1.size()][s2.size()] << endl;
    }
}
