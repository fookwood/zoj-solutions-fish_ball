// 2924678 2008-05-20 16:16:21 Accepted 2212 C++ 00:00.14 872K 呆滞的慢板 

// 用个优先队列搞啊搞啊... 

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Data {
    int id, t;
    
    Data(){}
    Data( int id, int t ) : id(id), t(t) {}
    
};

bool operator < ( const Data& d1, const Data& d2 ) {
    return  d1.t >  d2.t ||
            d1.t == d2.t &&
            d1.id > d2.id;
}

int     M[3001];

priority_queue<Data>    Q;

int main() {
    
    string  str;
    
    int     id, val;
    
    while( ( cin >> str ) && str != "#" ) {
        cin >> id >> val;
        M[id] = val;
        Q.push( Data( id, val ) );
    }
    
    for( cin >> val; val--; ) {
        cout << Q.top().id << endl;
        Q.push( Data( Q.top().id, Q.top().t + M[Q.top().id] ) );
        Q.pop();
    }
    
}
