#include <iostream>
using namespace std;

char C[26][7][17];

int main() {
    freopen("B.txt", "r", stdin);
    freopen("BW.txt", "w", stdout);
    for(int i = 0; i < 7; ++i) {
        for(int j = 0; j < 26; ++j) {
            cin >> C[j][i];
        }
    }
    for(int k = 0; k < 26; ++k) {
        int cnt = 0, va = 0, vb = 0;
        int x1 = INT_MAX, y1 = INT_MAX, x2 = INT_MIN, y2 = INT_MIN;
        for(int i = 0; i < 7; ++i) {
            for(int j = 0; j < 16; ++j) {
                if(C[k][i][j] == 'M') {
                    x1 <?= i;
                    x2 >?= i;
                    y1 <?= j;
                    y2 >?= j;
                }
            }
        }
        for(int i = 0; i < 7; ++i) {
            for(int j = 0; j < 16; ++j) {
                if(C[k][i][j] == 'M') {
                    va += (i - x1) * 16 + (j - y1);
                    vb += (x2 - i) * 16 + (y2 - j);
                    ++cnt;
                }
            }
        }
        cout << "{" << cnt << ", " << va << ", " << vb << "}," << endl;
    }
}
