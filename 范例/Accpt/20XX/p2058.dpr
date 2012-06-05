program p2058;

{$APPTYPE CONSOLE}

const
        maxn    = 100;

type
        Tb      = array[0..1] of Boolean;

var
        n        : Longint;

procedure main;
var
        ch              : Char;
        i , j           : Longint;
        min , max       : Longint;
        b               : Tb;
begin
min := 0; max := 0;
for i := 1 to n do
        begin
        fillchar ( b , sizeof ( b ) , 0 );
        for j := 1 to i do
                begin
                read ( ch );
                if ch = '@' then b [j and 1] := true;
                if ch = '*' then b [( j + 1 ) and 1] := true;
                end;
        readln;
        if b [0] then begin inc ( min , i shr 1 ); inc ( max , i shr 1 ) end else
        if b [1] then begin inc ( min , ( i + 1 ) shr 1 ); inc ( max , ( i + 1 ) shr 1 ) end else
                      begin inc ( min , i shr 1 ); inc ( max , ( i + 1 ) shr 1 ) end;
        end;
writeln ( max , ' ' , min );
end;

begin
assign ( input , 'p.in' ); reset ( input );
assign ( output , 'p.out' ); rewrite ( output );

readln ( n );
while ( n > 0 ) do
        begin
        main;
        readln ( n );
        end;
end.
