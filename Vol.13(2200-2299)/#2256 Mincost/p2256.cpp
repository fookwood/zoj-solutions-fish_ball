// 2822093 2008-04-04 00:49:29 Accepted 2256 C++ 00:00.03 392K 呆滞的慢板 

// 贪心，当有整 8 公里以上，换成 18 块钱 
// 有剩下的，如果剩下 5 块以下，按 2.4 块每公里算
// 当然，这里必须是在输入为 8 公里以上才能这样算 
// 否则的话，按照先跑 10 公里，再跑 2 元每公里算
// 至于输出，对精度问题要有绝对的敏感！！ 

#include <cstdio>
#include <cmath>

int main() {
    int     D;
    double  P;
    while( scanf( "%d", &D ) && D ) {
        P = 0.0;
        while( D >= 8 ) {
            D -= 8;
            P += 18.0;
        }
        if( fabs( P ) < 1e-5 ) {
            P = 10.0;
            while( D-- > 4 )
                P += 2.0;
        }
        else if( D <= 5 )
            P += double( D ) * 2.4;
        else {
            P += 10.0;
            P += double( D - 4 ) * 2.0;
        }
        if( fabs( P * 10.0 - round(P) * 10.0 ) < 1e-5 )
            printf( "%.0lf\n", P );
        else
            printf( "%.1lf\n", P + 1e-5 );
    }
}
