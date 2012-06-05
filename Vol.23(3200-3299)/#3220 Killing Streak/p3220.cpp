// 1914809 2009-07-11 12:05:08 Accepted  3220 C++ 0 184 呆滞的慢板 

// DotA 称号提示，纯蘑菇题，用对象包起来好些的话优美一点。 

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Player {
    
    static const char*Streak[];
    
    // 是否掉了第一滴血 
    static bool firstblood;
    
    // 玩家名称 
    string name;
    
    // 称号累计数 
    int streak;
    
    // 连杀次数累计 
    int continuum;
    
    // 上次杀人事件
    int lasttime; 
    
    static map<string, Player> players;
    
public:
    
    Player(string name) :
        name(name),
        streak(0),
        continuum(0),
        lasttime(-1) {} 
   
    // 玩家自己杀了一个人 
    void Kill(int time) {
        // 首先判别是否 FB。 
        if(!firstblood) {
            cout << name << " just drew First Blood!" << endl;
            firstblood = true;
        }
        // 更新称号累计数
        streak = min(streak + 1, 10);
        // 报称号 
        if(streak >= 3)
            cout << name << Streak[streak] << endl;
        // 更新连杀数 
        if(time - lasttime <= 14) continuum += 1;
        else continuum = 1;
        // 更新时间 
        lasttime = time;
        // 报连杀
        if(continuum == 2)
            cout << name << " just got a Double Kill!" << endl;
        else if(continuum >= 3)
            cout << name << " just got a Triple Kill!" << endl;
    }
    
    // 玩家自己被杀了
    void Killed(int time) {
        // 称号数被置零
        streak = 0;
    } 
    
    // 开始新游戏，清空 FB 和玩家列表。 
    static void NewGame() {
        firstblood = false;
        players.clear();
    }
    
    // 杀人事件
    static void KillEvent(string a, string b, int t) {
        if(players.find(a) == players.end()) players.insert(make_pair(a, Player(a)));
        if(players.find(b) == players.end()) players.insert(make_pair(b, Player(b)));
        players.find(a)->second.Kill(t);
        players.find(b)->second.Killed(t);
    }
    
};

const char* Player::Streak[] = {
    "",
    "",
    "",
    " has a Killing Spree!",
    " is Dominating!",
    " has a Mega Kill!",
    " is Unstoppable!",
    " is Wicked Sick!",
    " has a Monster Kill!!!",
    " is Godlike!",
    " is Beyond Godlike! Somebody kill him!!" 
};

bool Player::firstblood = false;

map<string, Player> Player::players;

struct Rec {
    string A, B;
    Rec() {}
    Rec(string A, string B) : A(A), B(B) {}
};

bool operator<(Rec a, Rec b) { return a.A < b.A; }

int main() {
    int T;
    for(cin >> T; T--;) {
        int N = 0;
        pair<int, Rec> R[100];
        string buf;
        while(cin >> buf && buf != "#") {
            int p = buf.find(':');
            int t = atoi(buf.substr(0, p).c_str()) * 60 +
                    atoi(buf.substr(p + 1).c_str());
            string a, b;
            cin >> a >> buf >> b;
            R[N++] = make_pair(t, Rec(a, b));
        }
        Player::NewGame();
        sort(R, R+N);
        for(int i = 0; i < N; ++i)
            Player::KillEvent(R[i].second.A, R[i].second.B, R[i].first);
        puts("");
    }
}
