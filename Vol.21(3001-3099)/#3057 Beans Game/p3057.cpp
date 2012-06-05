// 1694300 2008-11-09 17:27:49 Accepted  3057 C++ 890 26816 呆滞的慢板 

// 博弈 DP，直接前推，DP[i][j][k]，保证 i<=j<=k，然后枚举 i,j,k 前推。 
// 开始全部默认必输，然后枚举，从必输点发展出来的重新标记为必赢。否则略过。 

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool M[301][301][301] = {};

inline bool& at(int x, int y, int z) {
    if(y > z) swap(y, z);
    if(x > y) swap(x, y);
    if(y > z) swap(y, z);
    return M[x][y][z];
}

int main() {

    int a[3];

    for(a[0] = 0; a[0] <= 300; ++a[0]) {
        for(a[1] = a[0]; a[1] <= 300; ++a[1]) {
            for(a[2] = a[1]; a[2] <= 300; ++a[2]) {

                if(M[a[0]][a[1]][a[2]]) continue;

                for(int v = 1; a[0] + v <= 300; ++v)
                    at(a[0] + v, a[1], a[2]) = true;
                for(int v = 1; a[1] + v <= 300; ++v)
                    at(a[0], a[1] + v, a[2]) = true;
                for(int v = 1; a[2] + v <= 300; ++v)
                    at(a[0], a[1], a[2] + v) = true;

                for(int v = 1; a[1] + v <= 300; ++v)
                    at(a[0] + v, a[1] + v, a[2]) = true;
                for(int v = 1; a[2] + v <= 300; ++v)
                    at(a[0], a[1] + v, a[2] + v) = true;
                for(int v = 1; a[2] + v <= 300; ++v)
                    at(a[0] + v, a[1], a[2] + v) = true;
            }
        }
    }

    while(cin >> a[0] >> a[1] >> a[2])
        cout << at(a[0], a[1], a[2]) << endl;

}
