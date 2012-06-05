// 优先队列，用 STL 是异常的爽
// 不过注意用 iostream 会超时 

#include <queue> // for priority_queue<T>
#include <string>
#include <cstdio>
using namespace std;

class Message {
    string  msg;
    int     parameter;
    int     priority;
public:
    Message( string msg = "", int parameter = 0, int priority = 0 ) :
        msg(msg), parameter(parameter), priority(priority) {}
    friend bool operator < ( const Message& msg1, const Message& msg2 );
    void disp() const { printf( "%s %d\n", msg.c_str(), parameter ); }
};

inline bool operator < ( const Message& msg1, const Message& msg2 ) {
    return  msg1.priority > msg2.priority;
}

int main() {
    priority_queue<Message> Q;
    char    command[100];
    int     para,   prior;
    while( scanf( "%s", command ) != EOF ) {
        if( "GET" == string( command ) ) {
            if( Q.empty() )
                puts( "EMPTY QUEUE!" );
            else {
                Q.top().disp();
                Q.pop();
            }
        }
        else {
            scanf( "%s%d%d", command, &para, &prior );
            Q.push( Message( command, para, prior ) );
        }
    }
}
