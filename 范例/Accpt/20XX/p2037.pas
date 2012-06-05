  {$I+,Q+,R+,S-}

PROGRAM p2037;

VAR
        part , p , n , m , sum , j
                                : Longint;


BEGIN
readln ( part );
for p:= 1 to part do
        begin
        readln ( n );
        inc ( n );
        m := trunc ( ( sqrt ( 1 + 8 * n ) - 1 ) / 2 ) + 1;
        sum := m * ( m + 1 ) div 2;
        if sum - m >= n then
                begin
                dec ( sum , m );
                dec ( m );
                end;

        if sum - n = 1 then
                begin
                for j := 3 to m -1 do
                        write ( j , ' ' );
                writeln ( m + 1 );
                end else
                begin
                for j := 2 to sum - n - 1 do write ( j , ' ' );
                if sum = n then for j:= 2 to m -1 do write ( j , ' ' ) else
                for j := sum - n + 1 to m - 1 do write ( j , ' ' );
                writeln ( m );
                end;
        if p < part then writeln;
        end;
END.