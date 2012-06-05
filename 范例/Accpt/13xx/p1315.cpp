#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define maxlen     1000

main()
{
      int K , E , i , j , f [20] , len;
      char Key[20] [maxlen] , Excuse[20] [maxlen] , *p , *q , Tmp [maxlen];
      
      int  max , step;

      step=0;
      while ( scanf ( "%d %d\n" , & K , & E ) != EOF ) {
            
            printf ( "Excuse Set #%d\n" , ++ step );
            
            for ( i = 0; i < K; i ++ ) gets ( Key [i] );
            
            for ( i = 0; i < E; i ++ ) gets ( Excuse [i] );
            
            memset ( f , 0 , sizeof ( f ));
            
            for ( i = 0; i < K; i ++ )
                for ( j = 0 , len = strlen ( Key [i] ); j < len; j ++ )
                    Key [i] [j] = tolower ( Key [i] [j] );
            
            for ( i = max = 0; i < E; i ++ ) {
                len = strlen ( Excuse [i] );
                
                for ( j = 0; j < K; j ++) {
                    
                    for ( int d = 0; d < len; d ++ ) Tmp [d] = tolower ( Excuse [i] [d] );
                    Tmp [len] = 0;
                    
                    for ( p = Tmp; ( q = strstr ( p , Key [j] ) ) != NULL; *q = '/' )
                        if ( q == Tmp || !isalpha ( * ( q - 1 ) ))
                           if ( !isalpha ( * (q + strlen ( Key [j] )) )) f [i] ++;
                }
                if ( f [i] > max ) max = f [i];
            }
//            printf ( "max = %d\n" , max );
            for ( i = 0; i < E; i ++ ) if ( f [i] == max ) printf ( "%s\n" , Excuse [i] );
            printf("\n");
     }
}
