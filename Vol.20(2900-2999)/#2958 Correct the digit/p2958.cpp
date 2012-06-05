// 1869895 2009-05-15 02:53:10 Accepted  2958 C++ 0 184 呆滞的慢板 

// 纯蘑菇题，求可能的数码组表示，反正用巧妙点的方法就可以避免复杂的代码。
// 其中一个技巧就是用 9 个二进制位表示一个数码。
// 于是就可以通过位与求知一个数码是否能由另一个数码识别错误而来的。 

#include <iostream>
#include <string>
using namespace std;

/*
用二进制掩码表示 0~9 的 9 段显示码。 
0xAF    010101111 
0x09    000001001
0x9E    010011110
0x9B    010011011
0x39    000111001
0xB3    010110011
0xB7    010110111
0x89    010001001
0xBF    010111111
0xBB    010111011
*/

const int CODE[] = {
    0xAF, 0x09, 0x9E, 0x9B, 0x39,
    0xB3, 0xB7, 0x89, 0xBF, 0xBB
};

int getval(int C) {
    for(int i = 0; i < 10; ++i)
        if(C == CODE[i])
            return i;
    return -1;
}

bool valid(int VV[]) {
    int ans = 0;
    for(int i = 0; i < 9; ++i) {
        if(VV[i] == -1) return false;
        ans += (9 - i) * VV[i];
        ans %= 11;
    }
    return ans == 0;
}

int main() {
    string a[3];
    while(cin >> a[0] >> a[1] >> a[2]) {
        int CC[9] = {};
        int VV[9] = {};
        for(int i = 0; i < 9; ++i) {
            for(int x = 0; x < 3; ++x) {
                for(int y = 0; y < 3; ++y) {
                    CC[i] <<= 1;
                    if(a[x][i*3+y] != '.')
                        CC[i] += 1;
                }
            }
        }
        for(int i = 0; i < 9; ++i)
            VV[i] = getval(CC[i]);
        if(valid(VV)) {
            for(int i = 0; i < 9; ++i)
                cout << VV[i];
            puts("");
        }
        else {
            int cnt = 0;
            int AA[9];
            for(int i = 0; i < 9; ++i) {
                for(int j = 0; j < 10; ++j) {
                    if((CODE[j] & CC[i]) == CC[i] && CODE[j] != CC[i]) {
                        VV[i] = j;
                        if(valid(VV)) {
                            ++cnt;
                            for(int k = 0; k < 9; ++k) 
                                AA[k] = VV[k];
                        }
                    }
                }
                VV[i] = getval(CC[i]);
            }
            if(cnt == 0) puts("failure");
            else if(cnt > 1) puts("ambiguous");
            else {
                for(int i = 0; i < 9; ++i)
                    cout << AA[i];
                puts("");
            }
        }
    }
}
