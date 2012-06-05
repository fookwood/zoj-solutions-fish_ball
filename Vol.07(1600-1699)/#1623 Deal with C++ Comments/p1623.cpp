// 2910713 2008-05-13 10:17:18 Accepted 1623 C++ 00:00.01 860K 呆滞的慢板 

// hdu 里面比赛碰到的，要冷静沉着！
// 将所有行连成一串，行间加一个 '\n'
// 然后，/* 找 */ 匹配 // 找 '\n' 匹配
// 假如是 /* 先查找匹配，如果不存在匹配，忽略此注释头
// 如果存在匹配，将匹配部分转成大写，并且跳过整个匹配
// 如果是 // 则必定存在匹配，直接转大写并跳过 

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main() {
    
    int     T,  N;
    string  input,  temp;
    
    for( cin >> T; T--; ) {
    
        for( cin >> N, getline( cin, temp ), input = ""; N--; ) {
            getline( cin, temp );
            input += temp;
            input += '\n';
        }
        
        int status = 0;
        for( int pos = 0; pos + 1 < input.size(); ) {
            if( input[pos] == '/' && input[pos + 1] == '*' ) {
                pos += 2;
                int posx = pos;
                while( posx + 1 < input.size() )
                    if( input[posx] == '*' && input[posx + 1] == '/' )
                        break;
                    else    ++posx;

                if( posx + 1 == input.size() ) continue;

                ++status;

                while( !( input[pos] == '*' && input[pos+1] == '/' ) ) {
                    input[pos] = toupper( input[pos] );
                    ++pos;
                }
                pos += 2;
            }
                
            else if( input[pos] == '/' && input[pos + 1] == '/' ) {
                ++status;
                pos += 2;
                while( input[pos] != '\n' ) {
                    input[pos] = toupper( input[pos] );
                    ++pos;
                }
                ++pos;
            }
            
            else    ++pos;
            
        }
        
        cout << status << endl << input << endl;
    
    }
    
}
