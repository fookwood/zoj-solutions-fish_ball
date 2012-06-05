PROGRAM p1946;

const
        maxn    = 20;

type
        node            = record
                        name            : String;
                        money           : Longint;
                        end;

        Tdata           = array[1..maxn] of node;

VAR
        step                            : Integer;
        n , t , i , a , b , p , code    : Longint;
        data                            : Tdata;
        s , c                           : String;

FUNCTION Find ( var s : String ) : Longint;
var
        i                               : Longint;
begin
for i := 1 to n do
        if data [i] . name = s then exit ( i );
exit ( 0 );
end;

PROCEDURE Print ;
var
        i , j , temp                    : Longint;
begin
i := 1;
j := 1;
while ( i <= n ) do
        if data [i] . money < 0 then
                begin
                while ( data [j] . money <= 0 ) do inc ( j );

                if abs ( data [i] . money ) > abs ( data [j] . money ) then
                        temp := abs ( data [j] . money )
                        else temp := abs ( data [i] . money );

                writeln ( data [j] . name , ' ' , data [i] . name ,' ', temp );
                dec ( data [j] . money , temp );
                inc ( data [i] . money , temp );
                end else inc ( i );
end;

BEGIN


step := 0;
readln ( n , t );
while ( n > 0 ) do
        begin
        inc ( step );
        writeln ( 'Case #' , step );
        for i := 1 to n do
                begin
                readln ( data [i] .name );
                data [i] . money := 0;
                end;

        for i := 1 to t do
                begin
                readln ( s );
                c := copy ( s , 1 , pos ( ' ' , s ) - 1 );
                a := find ( c );
                delete ( s , 1 , pos ( ' ' , s ) );
                c := copy ( s , 1 , pos ( ' ' , s ) - 1);

                b := find ( c );

                delete ( s , 1 , pos ( ' ' , s ) );
                val ( s , p , code );

                dec ( data [a] . money , p );
                inc ( data [b] .money , p );
                end;

        print;
        writeln;
        readln ( n , t );
        end;
END.
