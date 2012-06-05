// 字符串处理，很难看的处理 
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ofstream    out( "figure.txt" );
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
    for( int i = 0; i < fig.size(); i++ )
        out << fig[i] << endl;
}
