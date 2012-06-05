#include <cstdio>
#include <cstring>

void put(int* x) {
    printf("%d", x[x[0]]);
    for(int i = x[0] - 1; i; i--)
        printf("%04d", x[i]);
    puts("");
}

void add(int* a, int* b) {
    if(b[0] > a[0]) a[0] = b[0];
    for(int i = 1; i <= a[0]; i++) {
        if((a[i] += b[i]) >= 10000) {
            a[i] -= 10000;
            a[i+1]++;
        }
    }
    if(a[a[0]+1]) a[0]++;
}

bool M[6][6] = {
    {1, 1, 0, 0, 1, 0},
    {1, 1, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 0},
};

int ans[1001][80], n;
int vec[6][80] =   {{1}, {1,1}, {1}, {1}, {1}, {1}};
int buf[6][80] =   {{1}, {1}, {1}, {1}, {1}, {1}};
int empty[6][80] = {{1}, {1}, {1}, {1}, {1}, {1}};

int main() {
    for(int i = 1; i <= 1000; ++i) {
        for(int j = 0; j < 6; ++j) {
            for(int k = 0; k < 6; ++k)
                if(M[k][j])
                    add(buf[j], vec[k]);
        }
        memcpy(vec, buf, sizeof(buf));
        memcpy(buf, empty, sizeof(buf));
        memcpy(ans[i], vec[2], sizeof(vec[2]));
    }
    while(scanf("%d", &n) != EOF) put(ans[n]);
}
