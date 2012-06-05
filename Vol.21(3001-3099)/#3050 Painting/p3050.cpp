// 1656540 2008-10-04 18:34:06 Accepted  3050 C++ 0 184 ´ôÖÍµÄÂı°å 

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pp;

int main() {
    string s;
    set<pair<pp, pp> > m;
    vector<pair<pp, pp> > v;
    set<int> xx, yy;
    while(cin >> s) {
        xx.clear();
        yy.clear();
        int x = 0, y = 0, xn, yn;
        bool on = true;
        m.clear();
        for(int i = 0; i < s.size(); ++i) {
            xn = x; yn = y;
            switch(s[i]) {
                case 'u': on = false; break;
                case 'd': on = true;  break;
                case 'U': y += 1; break;
                case 'D': y -= 1; break;
                case 'L': x -= 1; break;
                case 'R': x += 1; break;
            }
            if(xn == x && yn == y) continue;
            if(on) {
                pair<pp, pp> PP;
                PP.first = make_pair(x, y);
                PP.second = make_pair(xn, yn);
                if(PP.first > PP.second)
                    swap(PP.first, PP.second);
                m.insert(PP);
                xx.insert(x);
                xx.insert(xn);
                yy.insert(y);
                yy.insert(yn);
            }
        }
        v.assign(m.begin(), m.end());
        for(int i = 0; i < v.size(); ++i) {
            v[i].first.first -= *xx.begin();
            v[i].second.first -= *xx.begin();
            v[i].first.second -= *yy.begin();
            v[i].second.second -= *yy.begin();
        }
        int len = *yy.rbegin() - *yy.begin() >> 1;
        m.clear();
        m.insert(v.begin(),v.end());
        switch(m.size() / len) {
            case 2: puts("1");break;
            case 3: puts("7");break;
            case 7: puts("8");break;
            case 4: puts("4");break;
            case 5: 
                if(m.find(make_pair(make_pair(0,len),make_pair(0,1+len)))!=m.end())
                    puts("5");
                else if(m.find(make_pair(make_pair(0,0),make_pair(0,1)))!=m.end())
                    puts("2");
                else puts("3");
            break;
            case 6:
                if(m.find(make_pair(make_pair(0,len),make_pair(1,len)))==m.end())
                    puts("0");
                else if(m.find(make_pair(make_pair(len,len),make_pair(len,1+len)))==m.end())
                    puts("6");
                else puts("9");
            break;
        }
    }
}
