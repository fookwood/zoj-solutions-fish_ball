PROGRAM p2476;

VAR
        n , i , code            : Longint;
        a , b                   : Extended;
        s                       : String;

BEGIN
readln ( n ) ;
while n <> 0 do
        begin
        a := 0;

        for i := 1 to n do
                begin
                readln ( s );
                delete ( s , 1 , 1 );
                while ( pos (',' , s ) > 0 ) do delete ( s , pos (',' , s ) , 1 );
                val ( s , b , code );
                a := a + b;
                end;

        str ( a : 0 : 2 , s );
        write ( '$' );
        i := pos ( '.' , s ) - 3 ;

        while ( i > 1 ) do
                begin
                insert ( ',' , s , i );
                dec ( i , 3 );
                end;

        writeln ( s );
        readln ( n );
        end;
END.