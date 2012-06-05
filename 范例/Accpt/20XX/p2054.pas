PROGRAM p2050;

TYPE
        TReach  = array[0..10001] of Boolean;

VAR
        part , p                : Longint;
        goal , L                : Longint;
        Reach                   : TReach;

PROCEDURE main;
var
        i , total               : Longint;
        p , q , c , mid         : Longint;
begin

Reach [0] := false;
total := 0;

for i := 1 to 10000 do
        begin
        p := 0;
        q := i - 1;
        c := 0;
        Reach [i] := false;
        while ( p <= q ) and ( c <= L ) do
                begin
                mid := ( p + q ) div 2;
                inc ( c );
                if mid = goal then
                        begin
                        Reach [i] := ( c = L );
                        p := q + 1;
                        end;
                if ( goal < mid ) then q := mid - 1
                        else p := mid + 1;
                end;
        if not Reach [i - 1] and Reach [i] then inc ( total );
        end;

writeln ( total );
Reach [10001] := false;
if total = 0 then exit;
for i := 1 to 10001 do
        if not Reach [i - 1] and Reach [i] then
                begin
                write ( i , ' ');
                end else
        if Reach [i - 1] and not Reach [i] then
                writeln ( i - 1 );
end;

BEGIN
readln ( part );
for p := 1 to part do
        begin
        readln ( goal , L );
        main;
        if p < part then writeln;
        end;
END.
