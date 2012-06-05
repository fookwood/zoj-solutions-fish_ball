#include <cstdio>

int main() {
    
    int     A,  B,  C,  D,  E,  F;
    
    while( scanf( "%d%d%d%d%d%d", &A, &B, &C, &D, &E, &F ) ) {

        if( !( A || B || C || D || E || F ) )   break;

        while( E-- ) {
            ++F;
            if( A > 91 )    A -= 91;
            else            A = 0;
        }
        
        while( D-- ) {
            ++F;
            int remain = 152;
            if( B > 19 ) {
                B -= 19;
                continue;
            }
            else    remain -= B * 8;
            B = 0;
            if( A > remain )
                A -= remain;
            else    A = 0;
        }
        
        while( C ) {
            ++F;
            int remain;
            if( C >= 8 ) {
                C -= 8;
                continue;
            }
            else {
                remain = 8 - C;
                C = 0;
                if( remain == 1 ) {
                    remain = 27;
                    if( B ) {
                        --B;
                        remain -= 8;
                    }
                    if( A > remain )
                        A -= remain;
                    else    A = 0;
                }
                else if( remain == 2 ) {
                    remain = 54;
                    if( B >= 3 ) {
                        B -= 3;
                        remain -= 24;
                    }
                    else {
                        remain -= B * 8;
                        B = 0;
                    }
                    if( A > remain )
                        A -= remain;
                    else    A = 0;
                }
                else if( remain == 3 ) {
                    remain = 81;
                    if( B >= 5 ) {
                        B -= 5;
                        remain -= 40;
                    }
                    else {
                        remain -= B * 8;
                        B = 0;
                    }
                    if( A > remain )
                        A -= remain;
                    else    A = 0;
                }
                else if( remain == 4 ) {
                    remain = 108;
                    if( B >= 9 ) {
                        B -= 9;
                        remain -= 72;
                    }
                    else {
                        remain -= B * 8;
                        B = 0;
                    }
                    if( A > remain )
                        A -= remain;
                    else    A = 0;
                }
                else if( remain == 5 ) {
                    remain = 135;
                    if( B >= 11 ) {
                        B -= 11;
                        remain -= 88;
                    }
                    else {
                        remain -= B * 8;
                        B = 0;
                    }
                    if( A > remain )
                        A -= remain;
                    else    A = 0;
                }
                else if( remain == 6 ) {
                    remain = 162;
                    if( B >= 15 ) {
                        B -= 15;
                        remain -= 120;
                    }
                    else {
                        remain -= B * 8;
                        B = 0;
                    }
                    if( A > remain )
                        A -= remain;
                    else    A = 0;
                }
                else if( remain == 7 ) {
                    remain = 189;
                    if( B >= 19 ) {
                        B -= 19;
                        remain -= 152;
                    }
                    else {
                        remain -= B * 8;
                        B = 0;
                    }
                    if( A > remain )
                        A -= remain;
                    else    A = 0;
                }
                break;
            }
            
        }
        
        while( B ) {
            ++F;
            if( B >= 27 ) {
                B -= 27;
                continue;
            }
            int remain = ( 27 - B ) * 8;
            B = 0;
            if( A > remain )
            A -= remain;
            else    A = 0;
        }
        
        if( A % 216 )   F += ( A / 216 + 1 );
        else            F += A / 216;
        
        printf( "%d\n", F );
        
    }
    
}
