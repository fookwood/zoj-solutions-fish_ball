// 2867871 2008-04-25 08:37:53 Accepted 1123 C++ 00:00.00 856K 呆滞的慢板 

// 虽然有点 BT，但作为算法本身并不难
// 因为坐标只有 -9~9，因此所有的网格点应该只有至多 17^2 = 289 个
// 于是即使遍历所有点效率也不会低。
// 先求出 (minX, maxX)，(minY, maxY)，枚举所有这两个开区间内的整数点
// 然后对于每个点，检查是否在三角形内(在所有边的同侧)
// 如果在内，则标记概念字符串信息，否则，字符串为空白占位符(对齐)
// 最后，按行将各点的串连接成字符串，裁掉尾部空格
// 若字符串不为空，输出这个字符串，最后输出一个空行 
// 注意开头结尾那句话是要原样输出的，因此 WA 了几次，题目没说清楚 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Point {
    int X,  Y;
    string  S;
    Point( int x = 0, int y = 0 ) :
        X( x ), Y( y ) {}
};

int x[3], y[3];

bool Inside( const Point& p ) {
    int val1 = ( p.X  - x[0] ) * ( y[1] - y[0] ) - 
               ( x[1] - x[0] ) * ( p.Y  - y[0] );
    int val2 = ( p.X  - x[1] ) * ( y[2] - y[1] ) - 
               ( x[2] - x[1] ) * ( p.Y  - y[1] );
    int val3 = ( p.X  - x[2] ) * ( y[0] - y[2] ) - 
               ( x[0] - x[2] ) * ( p.Y  - y[2] );
    if( !val1 || !val2 || !val3 )
        return  false;
    return  ( val1 > 0 ) == ( val2 > 0 ) == ( val3 > 0 ); 
}

string  toString( const Point& p ) {
    string  ans( "(" );
    if( p.X < 0 ) {
        ans += "-";
        ans += ( '0' - p.X );
    }
    else {
        ans += " ";
        ans += ( '0' + p.X );
    }
    
    ans += ", ";
    
    if( p.Y < 0 ) {
        ans += "-";
        ans += ( '0' - p.Y );
    }
    else {
        ans += " ";
        ans += ( '0' + p.Y );
    }
    
    ans += ") ";
    
    return ans;
    
}

int main() {
    
    vector<Point>   V;

    puts( "Program 4 by team X" );

    while( cin >> x[0] >> y[0]
               >> x[1] >> y[1]
               >> x[2] >> y[2] ) {

        int minX = min( min( x[0], x[1] ), x[2] );
        int maxX = max( max( x[0], x[1] ), x[2] );
        int minY = min( min( y[0], y[1] ), y[2] );
        int maxY = max( max( y[0], y[1] ), y[2] );
        
        V.clear();
        for( int i = maxY - 1; i > minY; i-- )
            for( int j = minX + 1; j < maxX; j++ )
                V.push_back( Point( j, i ) );

        for( int i = 0; i < V.size(); i++ ) {
            if( Inside( V[i] ) )
                V[i].S = toString( V[i] );
            else
                V[i].S = "         ";
        }

        int pos = 0;
        for( int i = maxY - 1; i > minY; i-- ) {
            string str( "" );
            for( int j = minX + 1; j < maxX; j++ )
                str += V[pos++].S;
            int pos = 0;
            for( int j = 0; j < str.length(); j++ )
                if( str[j] != ' ' )
                    pos = j;
            if( pos != 0 ) {
                str.erase( pos + 1 );
                cout << str << "\n";
            }
        }
        putchar( '\n' );

    }
    
    puts( "End of program 4 by team X" );

}
