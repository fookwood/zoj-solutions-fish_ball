#include <iostream>
using namespace std;

int main() {
    
    char line[100];
    
    freopen("g2.txt", "r", stdin);
    freopen("p1695x.cpp", "w", stdout);

    puts("#include <cstdio>\n");
    puts("int main() {");
    
    while(cin >> line)
        cout << "    puts(\"" << line << "\");\n";
    
    puts("}");
    
}
