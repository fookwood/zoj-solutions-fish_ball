// 简单解方程 
// 2813227 2008-03-31 12:49:38 Accepted 2191 C++ 00:00.00 832K 呆滞的慢板 

#include <iostream>
using namespace std;

int main() {
    int     f0, f1, f2;
    while( cin >> f0 >> f1 >> f2 ) {
        cout << 3 * f2 - 3 * f1 + f0 << ' '
             << 6 * f2 - 8 * f1 + 3 * f0 << ' '
             << 10 * f2 - 15 * f1 + 6 * f0 << endl;
    }
} 
