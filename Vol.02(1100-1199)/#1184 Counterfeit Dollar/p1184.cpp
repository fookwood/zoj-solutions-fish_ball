// 3057604 2008-09-02 18:54:10 Accepted 1184 C++ 00:00.00 392K ´ôÖÍµÄÂý°å 

// Ó²±Ò³ÆÖØ£¬¾­µä 

#include <cstdio>
#include <cstring>

char s1[20], s2[20], s3[20];
int  ys[12], up[12], dn[12];

int main() {
    int T,  imba;
    for( scanf("%d", &T); T--; ) {
        imba = 0;
        memset( ys, 0, sizeof( ys ) );
        memset( up, 0, sizeof( up ) );
        memset( dn, 0, sizeof( dn ) );
        for( int i = 0; i < 3; ++i ) {
            scanf( "%s%s%s", s1, s2, s3 );
            switch( *s3 ) {
                case 'u':
                    ++imba;
                    for( int i = 0; s1[i]; ++i )
                        ++up[s1[i]-'A'];
                    for( int i = 0; s2[i]; ++i )
                        ++dn[s2[i]-'A'];
                break;
                case 'd':
                    ++imba;
                    for( int i = 0; s1[i]; ++i )
                        ++up[s2[i]-'A'];
                    for( int i = 0; s2[i]; ++i )
                        ++dn[s1[i]-'A'];
                break;
                case 'e':
                    for( int i = 0; s1[i]; ++i )
                        ys[s2[i]-'A'] = 1;
                    for( int i = 0; s2[i]; ++i )
                        ++ys[s1[i]-'A'] = 1;
                break;
            }
        }
        for( int i = 0; i < 12; ++i ) {
            if( !ys[i] ) {
                if( dn[i] == imba ) {
                    printf( "%c is the counterfeit"
                        " coin and it is light.\n", 'A'+i );
                    break;
                }
                else if( up[i] == imba ) {
                    printf( "%c is the counterfeit"
                        " coin and it is heavy.\n", 'A'+i );
                    break;
                }
            }
        }
    }
}
