// 字符串处理，很难看的处理 
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string>  fig,    gap,    temp1,  temp2;
    fig.resize( 1, "X" );
    gap.resize( 1, " " );
    for( int i = 1; i <= 7; i++ ) {
        temp1.resize( 0 );
        temp2.resize( 0 );
        for( int j = 0; j < fig.size(); j++ ) {
            temp1.push_back( fig[j] + gap[j] + fig[j] );
            temp2.push_back( gap[j] + fig[j] + gap[j] );
        }
        fig.resize( 0 );
        for( int j = 0; j < temp1.size(); j++ )
            fig.push_back( temp1[j] );
        for( int j = 0; j < temp2.size(); j++ )
            fig.push_back( temp2[j] );
        for( int j = 0; j < temp1.size(); j++ )
            fig.push_back( temp1[j] );
        string  blank = gap[0] + gap[0] + gap[0];
        gap.resize( 0 );
        gap.resize( blank.size(), blank );
    }
    int     N;
    while( ( cin >> N ) && N != -1 ) {
        int     L = 1;
        for( int i = 1; i < N; i++ )    L *= 3;
        temp1.resize( 0 );
        for( int i = 0; i < L; i++ ) {
            temp1.push_back( fig[i].substr( 0, L ) );
            int     pos = temp1.back().size() - 1;
            while( temp1.back()[pos] == ' ' )   pos--;
            temp1.back().erase( pos + 1 );
            cout << temp1.back() << endl;
        }
        cout << '-' << endl;
    }
}
