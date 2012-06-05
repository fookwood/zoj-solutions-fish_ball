#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T, N;
    for(cin >> T; T--;) {
        int mnRnd = INT_MAX, mnTrc = INT_MAX, mxRnd = 0, mxTrc = 0;
        for(cin >> N; N--;) {
            int num, percent;
            cin >> num >> percent;
            getchar();
            int r1, r2;
            // rounding phase
            if(percent == 0)
                mxRnd = max(mxRnd, num * 200 + 1);
            else if(percent == 100) {
                mxRnd = max(mxRnd, num);
                mnRnd = min(mnRnd, num * 200 / 95);
            }
            else {
                r1 = 2 * percent - 1;
                r2 = 2 * percent + 1;
                mnRnd = min(mnRnd, num * 200 / r1);
                mxRnd = max(mxRnd, (num * 200 - 1) / r2 + 1);
            }
/*
cout << "Round" << ' ';
cout << r1 << ' ' << r2 << endl;
cout << (num * 200 - 1) / r2 + 1 << " " << (num * 200 - 1) / r1 + 1 << endl;
//*/
            // truncating phase
            if(percent == 100) {
                mxTrc = max(mxTrc, num);
                mnTrc = min(mnTrc, num);
            }
            else {
                r1 = percent;
                r2 = percent + 1;
                if(r1) mnTrc = min(mnTrc, num * 100 / r1);
                mxTrc = max(mxTrc, (num * 100 - 1) / r2 + 1);
            }
/*
cout << "Trunc" << ' ';
cout << r1 << ' ' << r2 << endl;
cout << (num * 100 - 1) / r2 + 1 << " " << (num * 100 - 1) / r1 + 1 << endl;
//*/
        }
//        cout << "Rnd: " << mnRnd << " : " << mxRnd << endl;
//        cout << "Trc: " << mnTrc << " : " << mxTrc << endl;
        int idx = 0;
        idx |= mnRnd >= mxRnd ? 1 : 0;
        idx |= mnTrc >= mxTrc ? 2 : 0;
        char* result[] = {"Neither", "Rounding", "Truncation", "Either"};
        puts(result[idx]);
    }
}
