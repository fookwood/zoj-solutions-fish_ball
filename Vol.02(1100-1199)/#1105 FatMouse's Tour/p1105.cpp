// 2147595 2010-04-08 16:47:45 Accepted  1105 C++ 0 184 呆滞的慢板 

// 烟雾题，其实双行线的图直接按照DFS路线肯定是一个欧拉回路。
// 因此，只需要统计所有边长除以20km/s再除1000m/km就得到小时数。 

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    double x1, y1, x2, y2;
    while(cin >> x1 >> y1 >> ws) {
        double len = 0;
        while(cin.peek() != 'j') {
            cin >> x1 >> y1 >> x2 >> y2 >> ws;
            len += hypot(x1-x2, y1-y2);
        }
        string buf;
        cin >> buf;
        int ans = (int)(len / 1000 * 6 + 0.5);
        printf("%d:%02d\n", ans / 60, ans % 60);
    }
}
