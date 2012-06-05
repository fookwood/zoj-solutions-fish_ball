// 这时间卡得太紧了！！
// 费了9牛2虎之力才 1.50s 险过...
// map 用得很爽 
// 2883653 2008-05-02 10:25:13 Accepted 2524 C++ 00:01.50 2988K 呆滞的慢板 

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct TeamInfo {
    
    int point;
    int win, draw, lost;
    int goal;
    
    TeamInfo() : point( 0 ),
        win( 0 ),  draw( 0 ), lost( 0 ),
        goal( 0 ) {}
        
    void Increase( int p, int w, int d, int l, int g ) {
        point += p;
        win += w;
        draw += d;
        lost += l;
        goal += g;
    }
    
};

typedef pair<string, TeamInfo> Team;

void disp( pair<string, TeamInfo> pr ) {
    
    printf( "%s %d %d %d %d %d\n",
        pr.first.c_str(),
        pr.second.win, pr.second.draw, pr.second.lost,
        pr.second.point, pr.second.goal );
         
}

bool icmp( const map<string, TeamInfo>::iterator pr1,
           const map<string, TeamInfo>::iterator pr2 ) {
    return  pr1 -> second.point >  pr2 -> second.point ||
            pr1 -> second.point == pr2 -> second.point &&
            pr1 -> second.goal  >  pr2 -> second.goal  ||
            pr1 -> second.point == pr2 -> second.point &&
            pr1 -> second.goal  == pr2 -> second.goal  &&
            pr1 -> first        <  pr2 -> first;
}

int main() {

    int     sc1,    sc2,    N,  C = 0;
    string  name1,  name2;
    map<string, TeamInfo>   T;
    map<string, TeamInfo>::iterator iter;
    vector<map<string, TeamInfo>::iterator >    V;
    
    while( cin >> N ) {
        
        if( C++ )   cout << endl;

        T.clear();

        while( N-- ) {

            cin >> name1;
            scanf( "%d:%d", &sc1, &sc2 );
            cin >> name2;

            T[name1].Increase(
                sc1 > sc2 ? 3 : sc1 == sc2 ? 1 : 0,
                sc1 > sc2, sc1 == sc2, sc1 < sc2,
                sc1 - sc2
            );

            T[name2].Increase(
                sc2 > sc1 ? 3 : sc2 == sc1 ? 1 : 0,
                sc2 > sc1, sc2 == sc1, sc2 < sc1,
                sc2 - sc1
            );
            
        }

        V.clear();
        for( iter = T.begin(); iter != T.end(); ++iter )
            V.push_back( iter );
        
        sort( V.begin(), V.end(), icmp );
        
        for( int i = 0; i < V.size(); ++i ) {
            printf( "%d ", i + 1 );
            disp( *V[i] );
        }

    }

}
