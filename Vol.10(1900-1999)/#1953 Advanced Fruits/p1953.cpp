// 3013289 2008-07-30 00:39:06 Accepted 1953 C++ 00:00.00 924K 呆滞的慢板 

// 先找出最长公共子序列，然后构造合并串

// 合并的方法：对于公共子串的每一个字母
// 从 s1 及 s2 开头扫描，不等于公共子串中遍历到的字母，直接输出
// 然后输出公共的字母，注意三个一起删掉
// 当公共字串为空之后，输出 s1 及 s2 剩余部分 

#include <iostream>
#include <string>
using namespace std;

int DP[101][101],   PR[101][101];

string  s1, s2, s3, sub;

int main() {
    
    while( cin >> s1 >> s2 ) {
        
        memset( PR, 0, sizeof( PR ) );
        memset( DP, 0, sizeof( DP ) );
            
        for( int i = 1; i <= s1.size(); ++i ) {
            DP[i][0] = 0;
            for( int j = 1; j <= s2.size(); ++j ) {
                DP[i][j] = DP[i][j-1];
                PR[i][j] = 1;
                if( DP[i-1][j] > DP[i][j] ) {
                    DP[i][j] = DP[i-1][j];
                    PR[i][j] = 2;
                }
                if( s1[i-1] == s2[j-1] && 
                    DP[i-1][j-1] + 1 > DP[i][j] ) {
                    DP[i][j] = DP[i-1][j-1] + 1;
                    PR[i][j] = 3;
                }
            }
        }
        
        sub.erase();
        
        int x = s1.size(), y = s2.size();
        while( x && y ) {
            if( PR[x][y] == 3 )
                sub = s2[y-1] + sub;
            int temp = PR[x][y];
            y -= temp % 2;
            x -= temp / 2;
        }
        
        while( sub.size() ) {
            while( s1[0] != sub[0] ) {
                cout << s1[0];
                s1.erase( 0, 1 );
            }
            while( s2[0] != sub[0] ) {
                cout << s2[0];
                s2.erase( 0, 1 );
            }
            cout << sub[0];
            s1.erase( 0, 1 );
            s2.erase( 0, 1 );
            sub.erase( 0, 1 );
        }
        cout << s1 << s2 << endl;
    
    }
    
}
