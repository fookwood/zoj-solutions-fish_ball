#include <iostream>
#include <string>
using namespace std;

int main() {
    freopen("out.txt", "w", stdout);
    char * key = "u8kvc0z";
    int len = strlen(key);
    string s;
    getline(cin, s);
    for(int i = 0; i < s.length(); ++i) {
        printf("%u\n", s[i] ^ key[i %len]);
    }
}
