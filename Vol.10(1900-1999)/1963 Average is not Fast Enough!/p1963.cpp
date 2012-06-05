// 2950685 2008-06-16 09:53:10 Accepted 1963 C++ 00:00.04 840K 呆滞的慢板 
// 无聊题的无聊做法，加起来一除... 

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Time {
    
    int h,  mm, ss;
    
public:
    
    Time() {}
    Time( int h, int mm, int ss ) :
        h(h), mm(mm), ss(ss) {}
    Time( const Time& t ) :
        h(t.h), mm(t.mm), ss(t.ss) {}
    bool getTime();
    Time operator + ( const Time& t );
    Time operator / ( const double& n );
    void disp();
    virtual ~Time() {}
    
};

bool Time::getTime() {
    string  input;
    cin >> input;
    if( input == "-:--:--" )
        return  false;
    h = input[0] - '0';
    mm = ( input[2] - '0' ) * 10 + input[3] - '0';
    ss = ( input[5] - '0' ) * 10 + input[6] - '0';
    return  true;
}

Time Time::operator + ( const Time& t ) {
    int sec = h * 3600 + mm * 60 + ss +
              t.h * 3600 + t.mm * 60 + t.ss;
    return  Time( sec / 3600, sec / 60 % 60, sec % 60 );
}

Time Time::operator / ( const double& n ) {
    double  sec = h * 3600 + mm * 60 + ss;
    sec = round( sec / n );
    int     intSec = int( sec );
    return  Time( intSec / 3600, intSec / 60 % 60, intSec % 60 );
}

void Time::disp() {
    printf( ": %d:%02d min/km\n", h * 60 + mm, ss );
}

int main() {
    
    int     N;
    double  T;
    string  s;
    
    cin >> N >> T;
    
    while( cin >> s ) {
        
        while( s.size() < 3 )
            s = " " + s;
        cout << s;
        
        Time    tot( 0, 0, 0 ),    now;
        bool    success = true;
        
        for( int i = 0; i < N; ++i ) {
            if( !now.getTime() )
                success = false;
            if( success )
                tot = tot + now;
        }
        
        if( !success ) {
            cout << ": -\n";
            continue;
        }
        
        ( tot / T ).disp();
        
    }
    
}
