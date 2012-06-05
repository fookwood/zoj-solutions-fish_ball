program p2107;

{$APPTYPE CONSOLE}

const
        maxn    = 100000;

type
        node    = record
                x , y   : Real;
                dis     : Real;
                end;

        Tdata   = array[1..maxn] of node;

var
        n               : Longint;
        mid             : node;
        data            : Tdata;

function dis_ ( x1 , y1 , x2 , y2 : real ) : real;
begin
dis_ := sqrt ( sqr ( x1 - x2 ) + sqr ( y1 - y2 ) );
end;

procedure qsort ( left , right : Longint );
var     i , j   : Longint;
        t       : node;
        key     : Real;
begin
i := left - 1; j := right + 1; key := data [left+random ( right - left )] .dis;
repeat
        repeat dec ( j ); until data [j] .dis <= key;
        repeat inc ( i ); until data [i] .dis >= key;
        if ( i < j ) then begin t := data [i]; data [i] := data [j]; data [j] := t; end
                else break;
until false;
if ( j + 1 < right ) then qsort ( j + 1 , right );
if ( left < j ) then qsort ( left , j );
end;

procedure init;
var     i       : Longint;
begin
mid .x := 0; mid .y := 0;
for i := 1 to n do
        begin
        readln ( data [i] .x , data [i] .y );
        mid .x := mid .x + data [i] .x;
        mid .y := mid .y + data [i] .y;
        end;
mid .x := mid .x / n; mid .y := mid .y / n;
for i := 1 to n do
        data [i] .dis := dis_ ( mid .x , mid .y , data [i] .x , data [i] .y );
qsort ( 1 , n );
end;

procedure main;
var     i , j   : Longint;
        min     : Real;
        t       : Real;
begin
min := 1e20;
for i := 1 to n do
        for j := i - 1 downto 1 do
                begin
                t := dis_ ( data [i] .x , data [i] .y , data [j] .x , data [j] .y );
                if t < min then min := t;
		  if ( data [j].dis + min < data [i].dis ) then break;
                end;
writeln ( min / 2 : 0 : 2 );
end;

begin
randomize;
while true do
        begin
        read ( n ); if n = 0 then break;
        init;
        main;
        end
end.

