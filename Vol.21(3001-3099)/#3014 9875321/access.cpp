#include <cstdio>

int x;

char* a[] = {
    "not special",
    "not special",
    "not special",
    "21",
    "31",
    "43",
    "5421",
    "5431",
    "76531",
    "765421",
    "9875321",
    "9876421",
    "BA98765421",
    "BA8765431",
    "DCBA9654321",
    "EDCBA8765432",
    "FEDCBA8765431" 
};

int main() {
    while(scanf("%d", &x) != EOF)
        puts(a[x]);
}
