program p1161;

{$APPTYPE CONSOLE}

const
        maxn    = 25;
        maxTime = 16 * 12;

type
        Tnum    = array[0..maxn] of Longint;

var
        part , p , n , Time  : Longint;
        first , down , Cost  : Tnum;
        heap  , leave        : Tnum;
        keep , ans           : Tnum;

procedure init;
var     i               : Longint;
begin
readln ( Time ); Time := Time * 12;
for i := 1 to n do read ( first [i] ); readln;
for i := 1 to n do read ( down [i] ); readln;
Cost [1] := 0;
for i := 2 to n do read ( Cost [i] ); readln;
for i := 3 to n do inc ( Cost [i] , Cost [i - 1] );
end;

procedure sort ( right : Longint );
var     i , j , t       : Longint;
begin
for i := 1 to right - 1 do
        for j := i + 1 to right do
                if ( leave [heap [i]] < leave [heap [j]] ) or
                        ( ( leave [heap [i]] = leave [heap [j]] ) and ( heap [i] > heap [j] )) then
                        begin
                        t := heap [i]; heap [i] := heap [j]; heap [j] := t;
                        end;
end;

procedure work ( Stop : Longint; var Keep : Tnum );
var     i , LeftTime       : Longint;
begin
fillchar ( Keep , sizeof ( keep ) , 0 );

LeftTime := Time - Cost [Stop];
for i := 1 to Stop do leave [i] := first [i];
for i := 1 to Stop do heap [i] := i;

sort ( Stop );
while ( leave [heap [1]] > 0 ) and ( LeftTime > 0 ) do
        begin
        dec ( LeftTime );
        inc ( Keep [heap [1]] );
        inc ( Keep [0] , leave [heap [1]] );
        dec ( leave [heap [1]] , down [heap [1]] );
        sort ( Stop );
        end;
inc ( Keep [1] , LeftTime );
end;

procedure main;
var     Stop  : Longint;
begin
fillchar ( Ans , sizeof ( Ans ) , 0 ); Ans [1] := Time;
for Stop := 1 to n do
        begin
        work ( Stop , keep );
        if keep [0] > Ans [0] then Ans := keep;
        end;
end;

procedure print;
var     i       : Longint;
begin
for i := 1 to n do
        begin
        if ( i > 1 ) then write ( ', ' );
        write ( Ans [i] * 5 );
        end;
writeln;
writeln ( 'Number of fish expected: ' , Ans [0] );
end;

begin
assign ( input , 'p.in' ); reset ( input );
assign ( output , 'p.out' ); rewrite ( output );

readln ( part );
for p := 1 to part do
        begin
        readln ( n );
        while ( n > 0 ) do
                begin
                init;
                main;
                print;
                readln ( n );
                if n > 0 then writeln;
                end;
        if p < part then writeln;
        end;
end.
