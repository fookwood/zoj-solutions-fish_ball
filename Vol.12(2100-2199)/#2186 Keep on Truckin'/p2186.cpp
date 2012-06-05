// 超弱智，啥都别说了，充其量算英语阅读
// 只输入三个数，找出第一个 <= 168 的数
// 或者找不到... 

#include <iostream>
using namespace std;

int main() {
    int     A[3];
    cin >> A[0] >> A[1] >> A[2];
    for( int i = 0; i < 3; i++ ) if( A[i] <= 168 ) {
        cout << "CRASH " << A[i] << endl;
        return  EXIT_SUCCESS;
    }
    cout << "NO CRASH" << endl;
}
