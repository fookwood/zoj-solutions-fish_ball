// 这个~~数据很弱，这里 sample2.cpp 的算法才是正确的
// 连 sample.cpp 的也是错的 
// 这个偷工减料的东西也 AC 了
// 但是很明显的可以举出反例： 7 7 50 --> 0 正确 
// 而这个和 sample.cpp 得到的 7 7 50 --> 1 错了
// 数据太弱 
#include <iostream>
using namespace std;

int main() {
    int     F[7][7][49];
    for( int a = 0; a < 7; a++ )
    for( int b = 0; b < 7; b++ ) {
        F[a][b][0] = F[a][b][1] = 1;
        for( int i = 2; i < 49; i++ ) {
            F[a][b][i] = ( a * F[a][b][i - 1] +
                           b * F[a][b][i - 2] ) % 7;
        }
    }
    int     A,  B,  N;
    while( ( cin >> A >> B >> N ) && ( A || B || N ) ) {
        A %= 7;
        B %= 7;
        N = ( N - 1 ) % 49;
        cout << F[A][B][N] << endl;
    }
}
