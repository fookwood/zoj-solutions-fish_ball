// 1760164 2009-02-07 15:46:31 Accepted  1023 C++ 0 184 呆滞的慢板 

// 高校录取，按照志愿和分数匹配，思路类似于最优婚配的延迟认可算法。 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Examination {

    // student info
    int N;
    vector<int> RA, SA;
    vector<vector<int> > PA;
    
    // university info
    int M;
    vector<int> RB, CB;
    
    // status
    vector<int> pos;
    vector<vector<int> > accepted;

    bool login(int v) {
        if(pos[v] >= PA[v].size()) return true;
        
        int university = PA[v][pos[v]];
        int score = SA[v] * (RB[university] == RA[v] ? 10 : 7);

        if(accepted[university].size() < CB[university]) {
            accepted[university].push_back(v);
            int index = accepted[university].size() - 1;
            while(index > 0) {
                int student = accepted[university][index - 1];
                int score2 = SA[student] * (RB[university] == RA[student] ? 10 : 7);
                if(score > score2) {
                    swap(accepted[university][index], accepted[university][index - 1]);
                    index -= 1;
                }
                else break;
            }
            return true;
        }
        else {
            int student = accepted[university].back();
            int score2 = SA[student] * (RB[university] == RA[student] ? 10 : 7);
            if(score2 >= score) {
                pos[v] += 1;
                return false;
            }
            else {
                int rechoose = accepted[university].back();
                accepted[university].back() = v;
                int index = accepted[university].size() - 1;
                while(index > 0) {
                    student = accepted[university][index - 1];
                    score2 = SA[student] * (RB[university] == RA[student] ? 10 : 7);
                    if(score > score2) {
                        swap(accepted[university][index], accepted[university][index - 1]);
                        index -= 1;
                    }
                    else break;
                }
                
                pos[rechoose] += 1;
                while(!login(rechoose));
                
                return true;
            }
        }
    }

public:
    
    void read() {
        cin >> N >> M;
        
        RA.resize(N);
        SA.resize(N);
        PA.assign(N, vector<int>());
        
        RB.resize(M);
        CB.resize(M);
        
        for(int i = 0, k, tmp; i < N; ++i) {
            cin >> RA[i] >> SA[i];
            for(cin >> k; k--;) {
                cin >> tmp;
                PA[i].push_back(tmp - 1);
            }
        }
        
        for(int j = 0; j < M; ++j)
            cin >> RB[j] >> CB[j];
    }
    
    void solve() {
        pos.assign(N, 0);
        accepted.assign(M, vector<int>());
        
        for(int i = 0; i < N; ++i) while(!login(i));
    }
    
    void write() const {
        for(int i = 0; i < N; ++i) {
            if(pos[i] >= PA[i].size()) puts("not accepted");
            else cout << PA[i][pos[i]] + 1 << endl;
        }
    }
    
};

int main() {
    
    int T;
    
    for(cin >> T; T--;) {
        Examination obj;
        obj.read();
        obj.solve();
        obj.write();
        if(T) puts("");
    }

}
