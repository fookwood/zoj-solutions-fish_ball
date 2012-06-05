#include <iostream>
#include <string>
using namespace std;

int main() {
    freopen( "std.out", "r", stdin );
    freopen( "stdout.txt", "w", stdout );
    string  s;
    while(getline(cin, s))puts(s.c_str());
}
