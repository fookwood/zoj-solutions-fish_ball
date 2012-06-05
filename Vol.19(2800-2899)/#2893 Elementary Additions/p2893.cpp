// 2825901 2008-04-05 23:50:46 Accepted 2893 C++ 00:00.06 2152K 呆滞的慢板  

// 很简单的，算法是 DP，反正千万不要用 iostream 就是了

#include <cstdio>
#include <cstring>

int main() {
    char    S[16][100000];
    int     L[16] = { 2 };
    strcpy( S[0], "{}" );
    for( int i = 1; i < 16; i++ ) {
        strcpy( S[i], "{" );
        strcat( S[i], S[0] );
        for( int j = 1; j < i; j++ ) {
            strcat( S[i], "," );
            strcat( S[i], S[j] );
        }
        strcat( S[i], "}" );
        L[i] = strlen( S[i] );
    }
    int     T;
    scanf( "%d", &T );
    while( T-- ) {
        char    s1[100000],  s2[100000];
        scanf( "%s%s", s1, s2 );
        int l1 = 0, l2 = 0;
        int L1 = strlen( s1 ), L2 = strlen( s2 );
        while( L1 > L[l1] ) l1++;
        while( L2 > L[l2] ) l2++;
        puts( S[l1 + l2] );
    }
}
