#include <stdio.h>
#include <string.h>

char    Str [255];     

bool    IsVowel ( char ch )
{
        return  ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

bool    check ()
{
        int     len = strlen ( Str ) , i , Have = 0;
        if ( len == 0 ) return false;
        for ( i = 0; i < len; i ++ ) {
                if ( IsVowel ( Str [i] )) Have = true;
                if ( i && Str [i] == Str [i - 1] && Str [i] != 'e' && Str [i] != 'o') return false;
                if ( i > 1 && !IsVowel ( Str [i - 2] ) && !IsVowel ( Str [i - 1] ) && !IsVowel ( Str [i] )) return false;
                if ( i > 1 && IsVowel ( Str [i - 2] ) && IsVowel ( Str [i - 1] ) && IsVowel ( Str [i] )) return false;
        }
        return  Have;
}

main ()
{
        while ( gets ( Str ) , strcmp ( "end" , Str ) )
                if ( check () ) printf ( "<%s> is acceptable.\n" , Str );
                        else printf ( "<%s> is not acceptable.\n" , Str );
}
 