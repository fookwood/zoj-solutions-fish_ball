#include <iostream>
#include <string>
using namespace std;

int main() {
    int C = 0;
    freopen( "std.in", "r", stdin );
    freopen( "statics.txt", "w", stdout );
    string  s;
    while(getline(cin, s)){
        if( s.find(  ' ') == string::npos )
        cout << ++C << endl;
    }
}
