program p1675;

{$APPTYPE CONSOLE}

const
        maxn    = 7;
        dx      : array[1..4] of Longint = ( 1 , 0 , 0 , -1 );
        dy      : array[1..4] of Longint = ( 0 , 1 , -1 , 0 );

type
        Tmap    = array [1..maxn , 1..maxn] of Longint;
        Thash   = array [1..maxn , 1..maxn , 1..maxn , 1..maxn] of Longword;

var
        px , py : Longint;
        bx , by : Longint;
        gx , gy : Longint;
        n , m   : Longint;
        map     : Tmap;
        hash    : Thash;

procedure init;
var     i , j   : Longint;
begin
for i := 1 to n do begin
        for j := 1 to m do
                begin
                read ( map [i] [j] );
                if map [i] [j] = 4 then begin px := i; py := j; end;
                if map [i] [j] = 2 then begin bx := i; by := j; end;
                if map [i] [j] = 3 then begin gx := i; gy := j; end;
                end;
        readln;
        end;
end;

function inrange ( x , y : Longint ) : boolean;
begin
inrange := ( x <= n ) and ( x >= 1 ) and ( y <= m ) and ( y >= 1 );
end;

procedure search ( px , py , bx , by , cost : Longint );
var     x , y   : Longint;
        i       : Longint;
begin
if not inrange ( px , py ) then exit;
if not inrange ( bx , by ) then exit;
if map [bx] [by] = 1 then exit;
if ( cost >= hash [px] [py] [bx] [by] ) then exit;
hash [px] [py] [bx] [by] := cost;

for i := 1 to 4 do
        begin
        x := px + dx [i];
        y := py + dy [i];
        if not inrange ( x , y ) then continue;
        if map [x] [y] = 1 then continue;
        if ( x = bx ) and ( y = by ) then search ( x , y , x + dx [i] , y + dy [i] , cost + 1 )
                else search ( x , y , bx , by , cost );
        end;
end;

procedure main;
var     i , j   : Longint;
        min     : Longword;
begin
fillchar ( hash , sizeof ( hash ) , $ff );
search ( px , py , bx , by , 0 );
min := $ffffffff;
for i := 1 to n do for j := 1 to m do
        if hash [i] [j] [gx] [gy] < min then min := hash [i] [j] [gx] [gy];
if min = $ffffffff then writeln ( -1 )
        else writeln ( min );
end;

begin
assign ( input , 'p.in' ); reset ( input );
assign ( output , 'p.out' ); rewrite ( output );

readln ( m , n );
while ( n <> 0) do
        begin
        init;
        main;
        readln ( m , n );
        end;
end.
