PROGRAM p2051;

CONST
        maxn    =       100000;

TYPE
        TData           =  array[0..maxn] of Char;

VAR
        part , p                : Longint;
        n , k  , l , min , sum  : Longint;
        Data                    : TData;

PROCEDURE Main;
var
        i , ans                 : Longint;
begin
min := maxLongint;

Data [0] := '*';
for i:=0 to n do
        if Data [i] <> '*' then
                begin
                sum := sum + ord ( Data [i] ) - 48;
                if ( i - l + 1 = k ) then
                        begin
                        if sum < min then
                                begin
                                min := sum;
                                ans := l;
                                end;
                        sum := sum - ord ( Data [l] ) + 48;
                        inc ( l );
                        end;
                end else
                begin
                sum :=     0;
                l   := i + 1;
                end;

if min < maxLongint then writeln ( ans )
         else writeln ( 0 );
end;

BEGIN
//assign ( input, 'p.in');
//reset ( Input );

readln ( part );
for p:= 1 to part do
        begin
        readln ( n , k );
        l := 1;
        while ( l <= n ) do
                begin
                read ( Data [l] );
                if ord ( Data [l] ) <= 13 then continue;
                inc ( l );
                end;
        Main;
        if p < part then writeln;
        end;
END.