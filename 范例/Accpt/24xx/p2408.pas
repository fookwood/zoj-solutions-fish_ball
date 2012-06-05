PROGRAM p2408;

type
        Ta      = array[0..14] of Extended;
        Tnum    = array[1..13] of Integer;

VAR
        n , step                : Integer;
        a , s                   : Ta;
        num                     : Tnum;
        goal                    : Extended;

procedure init;
var
        i                       : Integer;
begin
for i := 1 to n + 1 do read ( num [i] , s [i] );

fillchar ( a , sizeof ( a ) , 0 );
for i := 1 to n do
        begin
        a [( num [n + 1] - num [i] + 12 ) mod 12 + 1] := s [i];
        end;
goal := s [n + 1];
end;

function f ( x : Extended ) : Extended;
var
        i                       : Integer;
        s , t                   : Extended;
begin
t := 1;
s := 0;
for i := 0 to 12 do
        begin
        s := s + a [i] * t;
        t := t * x;
        end;
f := s;
end;

function search ( left , right : Extended ): Extended;
var
        mid , t                 : Extended;
begin
//writeln ( left : 8 : 3 , ' ' , right : 8 : 4 );
mid := ( left + right ) / 2;
t := f ( mid );
if abs ( right - left ) < 1e-10 then
        begin
        search := mid - 1;
        exit;
        end;

if ( t < goal ) then search := search ( mid , right )
        else search := search ( left , mid );
end;


BEGIN
read ( n );
step := 0;
while ( n > 0 ) do
        begin
        inc ( Step );
        init;
        writeln ( 'Case ' , step , ': ' , search ( 1 , 2 ) : 0 : 5);
        readln ( n );
        if n > 0 then writeln;
        end;
END.