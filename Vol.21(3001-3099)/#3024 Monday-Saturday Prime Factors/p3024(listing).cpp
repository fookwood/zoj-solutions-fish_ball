// 打表过的，先生成所有素数然后枚举所有素数，很拙劣。

#include <iostream>
#include <vector>
using namespace std;

bool isPrime[300001] = {};
vector<int> Prime;

int main() {
    
    Prime.clear();
    for( int i=6, d=2; i<300001; i+=d, d=7-d ) {
        isPrime[i] = true;
        for( int j = 0; j < Prime.size(); ++j ) {
            if( i % Prime[j] == 0 ) {
                isPrime[i] = false;
                break;
            }
        }
        if( isPrime[i] ) Prime.push_back( i );
    }

    freopen( "list.txt", "w", stdout );
    
    for( int i = 0; i < Prime.size(); ++i )
        cout<<Prime[i]<<','<<endl;
    puts( "INT_MAX" );
    
}
