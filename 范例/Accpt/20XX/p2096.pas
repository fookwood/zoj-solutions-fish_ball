  {$I-,Q-,R-,S-}

PROGRAM p2096;

const
        maxn    = 100;

TYPE
        TData   = array[0..maxn] of Integer;
        Topt    = array[0..maxn ,0..maxn ]of Integer;

VAR
        n , i                   : Integer;
        Data                    : TData;
        opt                     : Topt;

PROCEDURE Danymic;
var
        i , j                   : Integer;
        temp , t2               : Integer;
begin
opt [1] [0] := 0;
opt [2] [1] := abs (Data [2] - Data [1] );
opt [2] [0] := opt [2] [1];

for i := 2 to n - 1 do
        begin
        temp := abs ( Data [i + 1] - Data [i] );
        opt [i + 1] [0] := opt [i] [0] + temp;

        opt [i + 1] [i] := maxint;

        for j := 1 to i - 1 do
                begin
                opt [i + 1] [j] := opt [i] [j] + temp;
                t2 := abs ( Data [i + 1] - Data [j] ) + opt [i] [j];
                if ( t2 < opt [i + 1] [i] ) then
                        opt [i + 1] [i] := t2 ;
                end;
        end;

temp := maxint;
for i := 0 to n - 1 do if opt [n] [i] < temp then temp := opt [n] [i];

if temp < maxint then writeln ( temp )
        else writeln ( 0 );
end;

BEGIN
Data [0] := 0;
readln ( n );
while ( n <> 0 ) do
        begin
        for i := n downto 1 do read ( Data [i] );
        readln ;
        Danymic;
        readln ( n ) ;
        end;
END.