#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    while(cin >> N) {
        vector<string> V(N);
        for(int i = 0; i < N; ++i)
            cin >> V[i];
        string output("");
        for(int i = V[0].size() - 1; i >= 0; --i) {
            for(int j = V.size() - 1; j >= 0; --j) {
                if(V[j][i] == '\\')
                    output += '\n';
                else if(V[j][i] == '_')
                    output += ' ';
                else
                    output += V[j][i];
            }
        }
        output.erase(output.find_last_not_of(' ') + 1);
        cout << output << endl << endl;
    }
}
