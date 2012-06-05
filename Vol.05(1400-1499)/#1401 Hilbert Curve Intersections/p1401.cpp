// 1830466 2009-04-12 02:41:36 Accepted  1401 C++ 0 184 呆滞的慢板 

// 一个很经典的分治法解决的题目，对于每次切割，
// 都可以分治为四个子切割中某部分的和，
// 然后还需要加上重叠子状态记忆，这样才能满足效率要求。 

#include <iostream>
#include <map>
using namespace std;

typedef long long i64;

struct Key {
    int n, x1, y1, x2, y2;
    Key(int n, int x1, int y1, int x2, int y2) :
        n(n), x1(x1), y1(y1), x2(x2), y2(y2) {}
};

bool operator <(const Key& lhs, const Key& rhs) {
    if(lhs.n < rhs.n) return true;
    if(lhs.n > rhs.n) return false;
    if(lhs.x1 < rhs.x1) return true;
    if(lhs.x1 > rhs.x1) return false;
    if(lhs.y1 < rhs.y1) return true;
    if(lhs.y1 > rhs.y1) return false;
    if(lhs.x2 < rhs.x2) return true;
    if(lhs.x2 > rhs.x2) return false;
    return lhs.y2 < rhs.y2;
}

map<Key, i64> MP;

i64 eval(int n, int x1, int y1, int x2, int y2) {
    if(MP.find(Key(n, x1, y1, x2, y2)) != MP.end()) return MP[Key(n, x1, y1, x2, y2)];
    //cout << "evaluating: ("<<n<<", "<<x1<<", "<<y1<<", "<<x2<<", "<<y2<<")"<<endl;
    int hlf = 1 << n-1;
    if(x1 == x2) {
        if(x1 == hlf) return MP[Key(n, x1, y1, x2, y2)] = int(y1 < hlf && y2 >= hlf);
        else if(x1 == 0 || x1 == (1<<n)) return MP[Key(n, x1, y1, x2, y2)] = 0;
        else if(x1 < hlf) {
            i64 ans = 0;
            if(y1 < hlf) ans += eval(n - 1, x1, y1, x1, min(y2, hlf));
            if(y2 > hlf) ans += eval(n - 1, max(hlf, y1) - hlf, hlf - x1, y2 - hlf, hlf - x1);
            return MP[Key(n, x1, y1, x2, y2)] = ans;
        }
        else if(x1 > hlf) {
            i64 ans = 0;
            if(y1 < hlf) ans += eval(n - 1, x1 - hlf, y1, x1 - hlf, min(y2, hlf));
            if(y2 > hlf) ans += eval(n - 1, (1<<n) - y2, x1 - hlf, (1<<n) - max(y1, hlf), x1 - hlf);
            return MP[Key(n, x1, y1, x2, y2)] = ans;
        }
        // Exception
        else while(1) puts("OLE!!");
    }
    else if(y1 == y2) {
        if(y1 == hlf) return MP[Key(n, x1, y1, x2, y2)] = int(x1 == 0 && x2 > 0) + int(x1 < (1<<n) && x2 == (1<<n));
        else if(y1 == 0 || y1 == (1<<n)) return MP[Key(n, x1, y1, x2, y2)] = 0;
        else if(y1 < hlf) {
            i64 ans = 0;
            if(x1 < hlf) ans += eval(n - 1, x1, y1, min(x2, hlf), y1);
            if(x2 > hlf) ans += eval(n - 1, max(x1, hlf) - hlf, y1, x2 - hlf, y1);
            return MP[Key(n, x1, y1, x2, y2)] = ans;
        }
        else if(y1 > hlf) {
            i64 ans = 0;
            if(x1 < hlf) ans += eval(n - 1, y1 - hlf, hlf - min(x2, hlf), y1 - hlf, hlf - x1);
            if(x2 > hlf) ans += eval(n - 1, (1<<n) - y1, max(x1, hlf) - hlf, (1<<n) - y1, x2 - hlf);
            return MP[Key(n, x1, y1, x2, y2)] = ans;
        }
        // Exception
        else while(1) puts("OLE!!");
    }
}

int main() {
    int n, x1, x2, y;
    while(cin >> n >> x1 >> x2 >> y)
        cout << eval(n, x1, y, x2, y) << endl;
}
