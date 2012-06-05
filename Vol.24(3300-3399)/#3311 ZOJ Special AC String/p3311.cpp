// 2164853 2010-04-16 13:01:04 Accepted  3311 C++ 0 184 呆滞的慢板 

// ZOJ串检验，逻辑等价变换，命题等价于：
// 有且仅有一个 Z，有且仅有一个 J，J 在 Z 后面且不能紧跟在后面，
// 另外，中间夹杂的三段 O 分别有 a, b, c 的长度，必须满足 a + b = c。 

#include <string>
#include <iostream>
using namespace std;

int main() {
    string s;
    while(cin >> s) {
        int z1, z2, j1, j2;
        z1 = s.find_first_of('Z');
        z2 = s.find_last_of('Z');
        j1 = s.find_first_of('J');
        j2 = s.find_last_of('J');
        puts(z1==z2&&j1==j2&&z1!=-1&&j1!=-1&&j1-z1>1&&s.size()==j1+j1 ?
            "Accepted" : "Wrong Answer");
    }
}
