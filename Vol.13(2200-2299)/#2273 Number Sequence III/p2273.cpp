// 1796957 2009-03-21 16:49:41 Accepted  2273 C++ 50 4580 呆滞的慢板 

// 暴力的艺术，暴力也要暴力得巧妙！本题查询超多！ 
// 先用一次暴力处理把表打出来，然后让每次查询的代价降到最低。
// 怎么用一次暴力把所有结果暴力出来呢？
// 用一个链表(这里用数组模拟)，存放从 1 串到 99999 的所有字符，
// 以及该个字符是属于哪一个数字的。
// 然后一次一次删，删之前检查链表第一个和第二个是否属于同一个数字。
// 如果不是，那么假设第一个节点属于数字 k，字符是 c，
// 那么查询 k 的结果就是 c，保存 ans[k] = c
// 这样预处理了之后，对于每次查询 k： 
// 如果 k 已经出来过结果，那么记过就是 ans[k]，
// 否则就一直往前找，直到找出第一个计算出来过的 ans[k']。 

#include <iostream>
using namespace std;

char ans[100000] = {'1'};

char content[488900] = {};
int next[488900] = {1}, idx[488900] = {};

int main() {
    char S[6];
    int top = 1;
    for(int i = 1; i <= 99999; ++i) {
        sprintf(S, "%d", i);
        for(int j = 0; S[j]; ++j) {
            content[top] = S[j];
            next[top] = top + 1;
            idx[top] = i;
            top++;
        }
    }
    int rem = top - 1;
    for(int k = 0; rem > 1; k = 1 - k) {
        int it = next[0], post = 0;
        if(idx[it] != idx[next[it]])
            ans[idx[it]] = content[it];
        if(k == 0) { it = next[it], post = next[post]; }
        while(it != top) {
            next[post] = it = next[it];
            --rem;
            if(it != top) { it = next[it], post = next[post]; }
        }
    }
    int N;
    for(int i = 1; i <= 99999; ++i) if(!ans[i]) ans[i] = ans[i-1];
    while(scanf("%d", &N) != EOF) { putchar(ans[N]); puts(""); }
}
