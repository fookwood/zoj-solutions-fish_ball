// 2002823 2009-09-26 10:59:08 Accepted  1631 C++ 0 184 呆滞的慢板 

// 星际争霸，水题，但题目极度有病，注意输入顺序是 name HP Armor Cool Amount Power ws 

#include <iostream>
#include <string>
using namespace std;

struct Unit {    
    string name;
    long long Armor, HP, Power, Amount, Cool;
    bool get() {
        if( cin >> name
                >> HP
                >> Armor
                >> Cool
                >> Amount
                >> Power
                >> ws
        ) return true;
        else return false;
    }
};

long long QTime(Unit a, Unit b) {
    long long DPS = a.Power - b.Armor;
    if(DPS < 1) DPS = 1;
    DPS *= a.Amount;
    int ans = b.HP / DPS;
    if(b.HP % DPS) ++ans;
    return a.Cool * ans;
}

int main() {
    Unit A, B;
    while(A.get() && B.get()) {
        long long t1 = QTime(A, B);
        long long t2 = QTime(B, A);
        if(t1 > t2) cout << B.name << " Survive!\n";
        else if(t1 < t2) cout << A.name << " Survive!\n";
        else cout << "All Die!" << endl;
    }
}
