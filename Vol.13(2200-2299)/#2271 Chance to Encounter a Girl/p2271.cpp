// 1814783 2009-04-02 15:37:24 Accepted  2271 C++ 330 184 呆滞的慢板 

// 入门级概率 DP，每过一天更新一下 girl 在各个格子的概率，
// 然后将遇上的格子的概率累加并清空，最后累加结果就是最终结果。 

#include <iostream>
#include <algorithm>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    
    double X[100][100], Y[100][100];
    
    double (*A)[100] = X, (*B)[100] = Y;
    
    int N;
    
    while(cin >> N) {
        
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                A[i][j] = B[i][j] = 0;
        
        A[N / 2][N / 2] = 1;
        
        double ans = 0;
        
        for(int d = 0; d < N; ++d) {
            
            for(int i = 0; i < N; ++i) {
                for(int j = 0; j < N; ++j) {
                    if(i != 0 && i != N - 1 && j != 0 && j != N - 1) {
                        for(int k = 0; k < 4; ++k)
                            B[i + dx[k]][j + dy[k]] += 0.25 * A[i][j];
                    }
                    else if((i == 0 || i == N - 1) && (j == 0 || j == N - 1)) {
                        for(int k = 0; k < 4; ++k)
                            if(i + dx[k] >= 0 && i + dx[k] < N && j + dy[k] >= 0 && j + dy[k] < N)
                                B[i + dx[k]][j + dy[k]] += 0.5 * A[i][j];
                    }
                    else if(i == 0 || i == N - 1 || j == 0 || j == N - 1) {
                        for(int k = 0; k < 4; ++k)
                            if(i + dx[k] >= 0 && i + dx[k] < N && j + dy[k] >= 0 && j + dy[k] < N)
                                B[i + dx[k]][j + dy[k]] += A[i][j] / 3;
                    }
                }
            }
            
            swap(A, B);
/*
            for(int i = 0; i < N; ++i) {
                for(int j = 0; j < N; ++j)
                    cout << A[i][j] << '\t';
                cout << endl;
            }
            system("pause");
  */              
                
            ans += A[N / 2][d];
            A[N / 2][d] = 0;
            
            for(int i = 0; i < N; ++i)
                for(int j = 0; j < N; ++j)
                    B[i][j] = 0;
        }
        
        printf("%.4lf\n", ans);
        
    }
    
}
