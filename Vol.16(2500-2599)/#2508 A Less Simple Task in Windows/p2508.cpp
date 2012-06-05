// 1671053 2008-10-19 11:05:28 Accepted  2508 C++ 0 184 呆滞的慢板 

// 小蘑菇一道，Windows 的窗口点击。枚举即可，需要注意的是连击的逻辑关系 

#include <iostream>
#include <vector>
using namespace std;

int MH, MW, H, N, C;

struct Win {
    int x1, y1, x2, y2, idx;
    bool maximized;
    void get() {
        cin >> x1 >> y2 >> x2 >> y1;
        maximized = false;
    }
    bool in(int x, int y) {
        return maximized ||
                x1 <= x && x <= x2 &&
                y1 <= y && y <= y2;
    }
    bool title(int x, int y) {
        if(maximized)
            return MH - H <= y <= MH;
        return x1 <= x && x <= x2 &&
                y2 - H <= y && y <= y2;
    }
} win[5], tmp;


int main() {
    
    while(cin >> N >> H >> MH >> MW) {
    
        for(int i = 0; i < N; ++i) {
            win[i].get();
            win[i].idx = i;
        }
        
        cin >> C;
        
        int xx = -1, yy = -1, px, py, k = -1;
        
        while(C--) {
            cin >> px >> py;
            int pos;
            for(pos = N-1; pos >= 0; --pos)
                if(win[pos].in(px, py))
                    break;
            if(pos == -1) {
                cout << pos;
                if(C) putchar(' ');
                xx = -1;
                yy = -1;
                k = -1;
                continue;
            }
            cout << win[pos].idx;
            if(C) putchar(' ');
            if(px == xx && py == yy &&
                k != -1 && win[pos].title(px, py))
                win[pos].maximized ^= 1;
            tmp = win[pos];
            k = win[pos].title(px, py) ? 1 : -1;
            for(int i = pos + 1; i < N; ++i)
                win[i-1] = win[i];
            win[N-1] = tmp;
            xx = px;
            yy = py;
        }
        puts("");
        
    }
    
}
