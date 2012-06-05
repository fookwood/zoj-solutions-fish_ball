// 1746534 2009-01-21 22:45:40 Accepted  3103 C++ 1350 1000 呆滞的慢板 

// 最短路，用了 SPFA，状态由一个格的坐标加上左脚或者右脚构成，直接转移即可。 

#include <deque>
#include <map>
#include <iostream>
using namespace std;

inline int index(int x1, int y1, int x2, int y2) {
    return ((x1 * 100 + y1) * 100 + x2) * 100 + y2;
}

inline int cost(char c) {
    if(c == 'T' || c == 'S') return 0;
    else return c - '0';
}

int dx2[] = {-2, -1, 0, 1, 2, -1, 0, 1, 0};
int dy2[] = {1, 1, 1, 1, 1, 2, 2, 2, 3};
int dx1[] = {-2, -1, 0, 1, 2, -1, 0, 1, 0};
int dy1[] = {-1, -1, -1, -1, -1, -2, -2, -2, -3};

int main() {
    map<int, int> MP;
    deque<int> DQ;
    deque<pair<int, int> > ST;
    int M, N;
    char A[60][30];
    while(cin >> N >> M && N) {
        ST.clear();
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                cin >> A[i][j];
                if(A[i][j] == 'S')
                    ST.push_back(make_pair(i, j));
            }
        }
        DQ.clear();
        MP.clear();
        for(int i = 0; i < ST.size(); ++i) {
            int idx = index(ST[i].first, ST[i].second, ST[i].first, ST[i].second);
            DQ.push_back(idx);
            MP[idx] = 0;
            DQ.push_back(-idx);
            MP[-idx] = 0;
            /*
            for(int j = i + 1; j < ST.size(); ++j) {
                if(ST[i].second < ST[j].second) {
                    int idx = index(ST[i].first, ST[i].second, ST[j].first, ST[j].second);
                    DQ.push_back(idx);
                    MP[idx] = 0;
                    DQ.push_back(-idx);
                    MP[-idx] = 0;
                }
                else {
                    int idx = index(ST[j].first, ST[j].second, ST[i].first, ST[i].second);
                    DQ.push_back(idx);
                    MP[idx] = 0;
                    DQ.push_back(-idx);
                    MP[-idx] = 0;
                }
            }
            */
        }
        int BEST = -1;
        while(!DQ.empty()) {
            int d = MP[DQ.front()];
            if(BEST != -1 && d >= BEST) {DQ.pop_front(); continue;}
            int sign = DQ.front() < 0 ? -1 : 1;
            DQ.front() *= sign;
            int y2 = DQ.front() % 100; DQ.front() /= 100;
            int x2 = DQ.front() % 100; DQ.front() /= 100;
            int y1 = DQ.front() % 100; DQ.front() /= 100;
            int x1 = DQ.front() % 100; DQ.front() /= 100;
//printf("(%d, %d), (%d, %d), %d; %c\n", x1, y1, x2, y2, d, sign > 0 ? 'L' : 'R');
            DQ.pop_front();
            if(sign > 0) {
                for(int i = 0; i < 9; ++i) {
                    x2 = x1 + dx2[i];
                    y2 = y1 + dy2[i];
                    if(x2 >= 0 && x2 < M && y2 >= 0 && y2 < N && A[x2][y2] != 'X') {
                        int idx = -index(x1, y1, x2, y2) * sign;
                        map<int, int>::iterator iter = MP.find(idx);
                        if(iter == MP.end() || iter -> second > d + cost(A[x2][y2])) {
                            MP[idx] = d + cost(A[x2][y2]);
                            DQ.push_back(idx);
                            if(A[x2][y2] == 'T') BEST = d;
                        }
                    }
                }
            }
            else {
                for(int i = 0; i < 9; ++i) {
                    x1 = x2 + dx1[i];
                    y1 = y2 + dy1[i];
                    if(x1 >= 0 && x1 < M && y1 >= 0 && y1 < N && A[x1][y1] != 'X') {
                        int idx = -index(x1, y1, x2, y2) * sign;
                        map<int, int>::iterator iter = MP.find(idx);
                        if(iter == MP.end() || iter -> second > d + cost(A[x1][y1])) {
                            MP[idx] = d + cost(A[x1][y1]);
                            DQ.push_back(idx);
                            if(A[x1][y1] == 'T') BEST = d;
                        }
                    }
                }
            }
        }
        cout << BEST << endl;
    }
}
