program p2482;

var
        part , p , i , j        : Integer;
        s                       : String;
        a                       : array[1..4] of Integer;

begin
readln ( part );
for p := 1 to part do
        begin
        readln ( s ); fillchar ( a , sizeof ( a ) , 0 );
        for i := 1 to 4 do
                begin
                a [i] := 0; for j :=8 * ( i - 1 ) + 1 to 8 * i do a [i] := a [i] * 2 + ord ( s [j] ) - 48 ;
                end;
        for i := 1 to 4 do
                begin
                if i > 1 then write ( '.' );
                write ( a [i] );
                end;
        writeln;
        end;
end.
