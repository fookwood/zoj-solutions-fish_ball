#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int T, N;
map<char, int> A, B;
string nA, nB;

class StableMarriage {
    typedef vector<int> V1D;
    typedef vector<V1D> V2D;
    int SZ;
    V1D mX, mY, k;
    V2D X, Y;
    
public:
    vector<pair<int, int> > getMatch(V2D vX, V2D vY) {
        X = vX;
        Y = vY;
        SZ = X.size();
        for(int i = 0; i < SZ; ++i)
            for(int j = 0; j < SZ; ++j)
                Y[i][vY[i][j]] = j;
        mX.assign(SZ, -1);
        mY.assign(SZ, -1);
        k.assign(SZ, 0);
        bool yes = true;
        while(true) {
            bool mark = true;
            int i;
            for(i = 0; i < SZ; ++i) {
                if(mX[i] == -1) {
                    while(k[i] < SZ) {
                        int j = X[i][k[i]];
                        if( mY[j] == -1 ) {
                            mX[i] = j;
                            mY[j] = i;
                            break;
                        }
                        if( Y[j][i] < Y[j][mY[j]] ) {
                            mX[mY[j]] = -1;
                            k[mY[j]]++;
                            mX[i] = j;
                            mY[j] = i;
                            break;
                        }
                        ++k[i];
                    }
                    if(mX[i] == -1)
                        mark = false;
                    break;
                }
            }
            if(i == N)
                break;
            if(!mark) {
                yes = false;
                break;
            }
        }
        vector<pair<int, int> > ans(0);
        if(!yes) return ans;
        for(int i = 0; i < SZ; ++i)
            ans.push_back(make_pair(i, mX[i]));
        return ans;
    }
};


int main() {
    for(cin >> T; T--;) {
        cin >> N >> ws;
        A.clear();
        B.clear();
        nA = nB = "";
        for(int i = 0; i < N; ++i) {
            char c;
            cin >> c;
            nA += c;
            A[c] = i;
        }
        for(int i = 0; i < N; ++i) {
            char c;
            cin >> c;
            nB += c;
            B[c] = i;
        }
        vector<vector<int> > X(N), Y(N);
        for(int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            for(int k = 2, j = A[s[0]]; k < s.size(); ++k)
                X[j].push_back(B[s[k]]);
        }
        for(int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            for(int k = 2, j = B[s[0]]; k < s.size(); ++k)
                Y[j].push_back(A[s[k]]);
        }
        StableMarriage obj;
        vector<pair<int, int> > ans = obj.getMatch(X, Y);
        vector<string> ss(0);
        for(int i = 0; i < ans.size(); ++i) {
            string tmp("");
            tmp += nA[ans[i].first];
            tmp += ' ';
            tmp += nB[ans[i].second];
            ss.push_back(tmp);
        }
        sort(ss.begin(), ss.end());
        for(int i = 0; i < ss.size(); ++i)
            cout << ss[i] << endl;
        if(T) cout << endl;
    }
}
