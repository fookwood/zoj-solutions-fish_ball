// 1867963 2009-05-14 01:45:30 Accepted  3131 C++ 20 568 呆滞的慢板 

// 数字钟，数字钟的时间 hhmmss 串接而成的整数叫时钟数。
// 给一个闭时间区间，问当中时钟数能被 3 整除的有几个。
// 蛮力的话单次复杂度不高，但查询个数很多。
// 因此蛮力做一次判定，按序将合法的能被 3 整除的所有时钟数存到顺序表中。
// 然后每给一个区间，用二分查找找到位置，然后一减即可得到结果。
// 这样可以在单次处理的效率上打一个对数。 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Clk {
    int hh, mm, ss;
    int value() { return ((hh * 100) + mm) * 100 + ss; }
    int get() { scanf("%2d:%2d:%2d", &hh, &mm, &ss); }
    void inc() { ss += 1; if(ss == 60) { mm += 1; ss = 0; if(mm == 60) { hh += 1; mm = 0; } } }
};

int main() {
    int N;
    Clk a, b;
    vector<int> v;
    a.hh = a.mm = a.ss = 0;
    while(true) {
        if(a.value() % 3 == 0) v.push_back(a.value());
        a.inc();
        if(a.value() == 475959) break;
    }
    for(scanf("%d", &N); N--;) {
        a.get();
        b.get();
        if(b.value() < a.value()) b.hh += 24;
        int dis =
            upper_bound(v.begin(), v.end(), b.value()) -
            lower_bound(v.begin(), v.end(), a.value());
        printf("%d\n", dis);
    }
}
