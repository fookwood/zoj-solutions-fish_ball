program p1640;

{$APPTYPE CONSOLE}

const
        maxn    = 20;
        maxlen  = 500;

type
        TA      = array[0..maxn] of Longint;

var
        part , n        : Longint;
        A               : TA;
        Ans             : TA;

procedure init;
var     i               : Longint;
begin
readln ( n );
for i := n downto 0 do read ( A [i] );
readln;
end;

procedure del ( x : Longint );
var     t               : TA;
        i               : Longint;
begin
t := A;
inc ( Ans [0] ); Ans [Ans [0]] := - x;
for i := n downto 1 do
        begin
        A [i - 1] := t [i];
        dec ( t [i - 1] , t [i] * x );
        end;
dec ( n );
end;

function check ( x : Longint ) : Boolean;
var     i , j           : Longint;
        xi , p , s      : Longint;

begin
check := false;
for i := 1 to 4 do
        begin
        p := random ( 1000 ) + 34;
        s := 0; xi := 1;
        for j := 0 to n do
                begin
                inc ( s , xi * A [j] );
                if s < 0 then s := s + ( abs ( s ) div p + 1 ) * p;
                s := s mod p;

                xi := xi * x;
                if xi < 0 then xi := xi + ( abs ( xi ) div p + 1 ) * p;
                xi := xi mod p;
                end;
        if s <> 0 then exit;
        end;
check := true;
end;

procedure sort;
var     i , j , t       : Longint;
begin
for i := 1 to Ans [0] - 1 do
        for j := i + 1 to Ans [0] do
                if Ans [i] > Ans [j] then begin
                        t := Ans [i]; Ans [i] := Ans [j]; Ans [j] := t;
                        end;
end;

procedure main;
var     i               : Longint;
        Limit           : Longint;
        ChangeOnce      : Boolean;
begin
Ans [0] := 0;
while ( n > 0 ) and ( A [0] = 0 ) do del ( 0 );

while ( n > 0 ) do
        begin
        ChangeOnce := false;
        Limit := abs ( A [0] );

        for i := 1 to Limit do if Limit mod i = 0 then
                begin
                if check ( i ) then begin ChangeOnce := true; del ( - i ); end;
                if check ( - i ) then begin ChangeOnce := true; del ( i ); end;
                end;

        if not ChangeOnce then break;
        end;

//writeln ( ' The Answer are : ' );
sort;
for i := 1 to Ans [0] do
        begin
        if i > 1 then write ( ' ' );
        write ( Ans [i] );
        end;
if Ans [0] = 0 then write ( 'NIR' );
writeln;
end;

begin
assign ( input , 'p.in' ); reset ( input );
assign ( output , 'p.out' ); rewrite ( output );

randomize;
readln ( part );
while ( part > 0 ) do
        begin
        init;
        main;
        dec ( part );
        end;
end.
