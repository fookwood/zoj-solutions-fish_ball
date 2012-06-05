// 2886908 2008-05-03 16:09:43 Accepted 1175 C++ 00:00.05 916K 呆滞的慢板
 
// 简单模拟题，只是读题一定要读清楚！
// 输入字符串由 N 行串接而成，换行符忽略，空格不忽略
// 指令字符当取到 # 时结束，空格换行都忽略
// 输出字符串如果有长于 80 的折断成 80 字符一行显示
// 因为最后一条没看清 WA 了几次 

#include <string>
#include <iostream>
using namespace std;

int main() {
    
    int     T,  N;
    string  s1, s2;
    
    cin >> T;
    
    while( T-- ) {
        
        cin >> N;
        getchar();
        
        s1 = "";
        while( N-- ) {
            getline( cin, s2 );
            s1 += s2;
        }
        
        int     head = 0, rear = s1.size();
        char    c;
        bool    type = true;
        
        s2 = "";
        while( ( c = getchar() ) != '#' ) {
            if( head >= rear )
                continue;
            if( c == 'G' ) {
                if( type )
                    s2 += s1[head++];
                else
                    s2 += s1[--rear];
            }
            if( c == 'R' )
                type = !type;
        }
        
        while( s2.size() > 80 ) {
            
            cout << s2.substr( 0, 80 ) << endl;
            s2.erase( 0, 80 );
            
        }
        
        cout << s2 << endl;
        
        if( T ) cout << endl;
        
    }
    
}
