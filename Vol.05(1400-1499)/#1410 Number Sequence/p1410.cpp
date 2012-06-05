// 3027350 2008-08-08 01:30:43 Accepted 1410 C++ 00:00.05 1328K 呆滞的慢板 

// 半模拟的乱搞，比开根号略低的复杂度 

#include <iostream>
#include <string>
#include <vector> 
using namespace std;

string      s;
vector<size_t> l; 
char    num[100];
size_t  sum = 0;

int main() {
    
    s = "1";
    int i = 1;
    
    l.push_back( 1 );
    while( sum < 2147483647u ) {
        sprintf( num, "%d", ++i );
        s += num;
        l.push_back( s.size() );
        sum += l.back();
    }
    
    int T,  N;
    
    for( cin >> T; T--; ) {
        cin >> N;
        i = 0;
        while( N > l[i] )
            N -= l[i++];
        cout << s[N-1] << endl;
    }
    
}
