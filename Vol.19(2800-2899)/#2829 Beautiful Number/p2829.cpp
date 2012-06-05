#include <cstdio>

int main() {
  int N;
  int list[7] = {3, 5, 6, 9, 10, 12, 15};
  while(scanf("%d", &N) != EOF)
    printf("%d\n", (N - 1) / 7 * 15 + list[(N - 1) % 7]);
} 
