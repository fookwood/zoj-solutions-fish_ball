PROGRAM p1499;

CONST
        maxn    = 80;

TYPE
        TData   = array[1..maxn] of Char;

        Tanstype = record
                minlast , nextone               : Longint;
                end;
        Tans    = array[1..maxn,1..maxn] of Tanstype;

VAR
        n               : Integer;
        Data            : TData;
        ans             : Tans;

PROCEDURE error ( s : string );
begin
writeln ( s );
halt;
end;

FUNCTION Compare ( L1 , T1 , L2 , T2 : Longint ) : Longint;
begin
if ( L1 < 0 ) or ( L1 > n ) or ( L2 < 0 ) or ( L2 > n ) then
        error ( 'Runtime error 201 at compare function' );

while ( L1 < T1 ) and ( Data [L1] = '0' ) do inc ( L1 );
while ( L2 < T2 ) and ( Data [L2] = '0' ) do inc ( L2 );

if T1 - L1 < T2 - L2 then exit ( - 1 );
if T1 - L1 > T2 - L2 then exit (   1 );

                // T1 - L1 = T2 - L2

while ( L1 < T1 ) and ( Data [L1] = Data [L2] ) do
        begin
        inc ( L1 );
        inc ( L2 );
        end;
if Data [L1] < Data [L2] then exit ( - 1 ) else
if Data [L1] = Data [L2] then exit (   0 ) else
                              exit (   1 );
end;

FUNCTION Init : Boolean;
var i :integer;
begin
n := 0;
while not eoln do
        begin
        inc ( n );
        read ( Data [n] );
        end;

if ( n = 1 ) and ( Data [1] = '0' ) then exit ( false );
Init := true;
readln;
end;

PROCEDURE Dp;
var
        i , j , k , temp
                                : Longint;
begin
for i := 1 to n do
        with ans [i] [n] do
                begin
                minlast := i;
                while ( minlast < n ) and ( Data [minlast] = '0' ) do inc ( minlast );
                nextone := n + 1 ;
                end;

for j := n - 1 downto 1 do
        for i := 1 to j do
                with ans [i] [j] do
                        begin
                        nextone := 0;
                        minlast := -1;

                        k := n;
                        while ( k > j ) do
                                begin
                                if compare ( i , j , j + 1 , k ) >= 0 then break;

                                if ans [j + 1] [k] . minlast > minlast then
                                        begin
                                        minlast := ans [j + 1] [k] . minlast;
                                        nextone := k;
                                        end;
                                dec ( k );
                                end;
                        end;

j := -1;
for i := n downto 1 do
        if ans [1] [i] . minlast > j then
                begin
                j := ans [1] [i] . minlast;
                k := i;
                end;

j := 1;
repeat
        if ( j > 1 ) then write (',');
        for i := j to k do write ( Data [i] );
        temp := k;
        k    := ans [j] [k] . nextone ;
        j    := temp + 1;
until ( k = n + 1 );
writeln;
end;

BEGIN
while Init do Dp;
END.