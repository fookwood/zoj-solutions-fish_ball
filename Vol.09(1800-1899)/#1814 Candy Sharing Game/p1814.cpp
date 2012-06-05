// 直接模拟，数据规模很小，收敛性应该其实也很快，但缺乏证明
// 2837125 2008-04-10 23:39:14 Accepted 1814 C++ 00:00.00 836K 呆滞的慢板  

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> V,  P;
    int     N;
    while( ( cin >> N ) && N ) {
        V.resize( N );
        for( int i = 0; i < N; i++ )
            cin >> V[i];
        int     count = 0;
        while( 1 ) {
            int     exit = true;
            for( int i = 1; i < N; i++ ) {
                if( V[i] != V[i-1] ) {
                    exit = false;
                    break;
                }
            }
            if( exit )  break;
            count++;
            P = V;
            V[0] = ( V[0] + P.back() ) >> 1;
            if( V[0] & 1 )  V[0]++;
            for( int i = 1; i < N; i++ ) {
                V[i] = ( V[i] + P[i-1] ) >> 1;
                if( V[i] & 1 )  V[i]++;
            }
        }
        cout << count << ' ' << V[0] << endl;
    }
}
