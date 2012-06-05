program p1883;

{$APPTYPE CONSOLE}

const
        maxn    = 100;

type
        Topt    = array[1..maxn , 0..maxn] of Double;

var
        n , m           : Longint;
        opt             : Topt;

procedure makeopt;
var     i , j           : Longint;
        Total           : Double;
begin
for i := 0 to m do opt [1] [i] := 1 / ( m + 1 );
for i := 2 to n do
        for j := 0 to m do
                begin
                opt [i] [j] := opt [i - 1] [j];
                if ( j > 0 ) then opt [i] [j] := opt [i] [j] + opt [i - 1] [j - 1];
                if ( j < m ) then opt [i] [j] := opt [i] [j] + opt [i - 1] [j + 1];
                opt [i] [j] := opt [i] [j] / ( m + 1 );
                end;
Total := 0; for i := 0 to m do Total := Total + opt [n] [i];
writeln ( Total * 100 : 0 : 5 );
end;

begin
while not eof do
        begin
        readln ( m , n );
        makeopt;
        end;
end.
