// 3028160 2008-08-09 00:16:38 Accepted 1823 C++ 00:00.50 836K 呆滞的慢板 

// 数据远远没有题目叙述的那么恐怖，其实可能出来玩死这个算法的数据
// 但是没有，硬搞就行了 

#include <iostream>
using namespace std;

long long X,    Y;

int main() {
    
    while( cin >> X && X != -1 ) {
        
        for( Y = 2; Y * Y <= X; ++Y ) {
            while( X % Y == 0 ) {
                X /= Y;
                cout << Y << endl;
            }
        }
        
        if( X != 1 )    cout << X << endl;
        
        cout << endl;
        
    }
    
}
