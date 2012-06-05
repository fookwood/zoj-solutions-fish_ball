#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    bool end = true;
    while(getline(cin, s)) {
        if(s == "") { end = true; puts(""); continue; }
        if(s[0] == ' ')
            s.erase(0, s.find_first_not_of(' '));
        if(s[s.size()-1] == ' ')
            s.erase(s.find_first_of(' '));
        if(end && s.size() > 62) {
            end = false;
             while(1)
            puts("fuck");
        }
    }
}


