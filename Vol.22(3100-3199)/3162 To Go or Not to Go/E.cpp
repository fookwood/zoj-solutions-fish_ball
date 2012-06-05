// 错误版本，本程序计算从 1 到 n 的数字二进制表示含有多少个 1 和多少个字符 

#include <iostream>
#include <algorithm>
using namespace std;

int ones(int num) {
    int ans = 0;
    int k = 0;
    while((1 << k + 1) <= num) ++k;
    
    int nn = num - (1<<k) + 1;
    ans += nn;
//cout<<"base = " << nn <<endl;
    for(int i = 0; i < k; ++i) {
        ans += nn / (1<<i+1) * (1<<i);
        ans += max(0, nn % (1<<i+1) - (1<<i));
//        cout << "i = " << i << endl;
//        cout <<" +1 : " << nn / (1<<i+1) * (1<<i) << endl;
//        cout << " +2 : " << min(0, nn % (1<<i+1) - (1<<i)) <<endl;
    }

    ans += k * (1 << k) / 2;
//cout << "k = " << k <<" add = " << k * (1 << k) / 2 << endl;
    return ans;
}

int total(int num) {
    int ans = 0;
    int k = 0;
    while((1 << k + 1) <= num) ++k;
    ans += (k + 1) * (num - (1<<k) + 1);
    for(int len = 0; len < k; ++len)
        ans += (len + 1) * (1<<len);
    return ans;
}
/*
int tt(int num) {
    int k = 0;
    while((1 << k + 1) <= num) ++k;
    return k + 1;
}

int oo(int num) {
    int k = 0;
    while((1 << k + 1) <= num) ++k;
    int ans = 0;
    while(k >= 0) {
        if(num & (1<<k))
            ++ans;
        k--;
    }
    return ans;
}

int disp(int num){
    int t=0,o=0;
    for(int i = 1; i <= num; ++i) {
        t +=tt(i);
        o += oo(i);
    }
        cout << " ones_A_ = " << o << endl;
        cout << " total_A_= " << t << endl;
}
*/
int main() {
    int T, A, B;
/*
    while(cin >> A) {
        cout << " ones(A) = " << ones(A) << endl;
        cout << " total(A)= " << total(A) << endl;
        disp(A);
    }
*/
    for(cin >> T; T--;) {
        cin >> A >> B;
        double ans = double(ones(B) - ones(A - 1)) /
                     double(total(B) - total(A - 1));
        printf("%.6lf\n", ans);
    }
}
