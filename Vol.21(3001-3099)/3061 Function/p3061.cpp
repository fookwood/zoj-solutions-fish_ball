#include <iostream>
using namespace std;

int n, k;
int t[100], m;

int main() {
    while(cin >> n >> k) {
        m = 0;
        int tmp = n;
        while(tmp != 0) {
            t[m++] = tmp % 3;
            tmp /= 3;
        }
        for(int p = m-1; p >= 0; --p)
            cout << t[p] <<' ';puts("");
    }
}
