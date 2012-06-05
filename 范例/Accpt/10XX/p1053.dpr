program p1053;

{$APPTYPE CONSOLE}

{%File 'p.in'}

const
        maxn    = 20;
        tab     = chr ( 9 );


type
        Tmap    = array[1..maxn , 1..maxn] of Longint;

        Tnum    = array[1..maxn] of Longint;

var
        part , n        : Longint;
        fire , r        : Longint;
        card            : Tnum;
        min             : Tnum;
        pred            : Tnum;
        mk              : Tnum;
        map             : Tmap;




procedure init;
var     i ,j            : Longint;
begin
readln ( n );
for i := 1 to n do
        begin
        for j := 1 to n do read ( map [i] [j] );
        readln;
        end;
read ( fire );
r := 0;
while ( not seekeoln ) do
        begin
        inc ( r );
        read ( card [r] );
        end;
readln;
end;

procedure dijkstra;
var     i , k   : Longint;
begin
for i := 1 to n do if map [i] [fire] = -1 then min [i] := maxLongint
        else begin min [i] := map [i] [fire]; pred [i] := fire; end;

fillchar ( mk , sizeof ( mk ) , 0 ); mk [fire] := 1;
repeat
        k := 0;
        for i := 1 to n do if ( mk [i] = 0 ) then
                if ( k = 0 ) or ( min [i] < min [k] ) then k := i;
        if k = 0 then break; mk [k] := 1;
        for i := 1 to n do if ( mk [i] = 0 ) and ( map [i] [k] >= 0 )then
                if ( min [k] + map [i] [k] < min [i] ) then
                        begin
                        min [i] := min [k] + map [i] [k];
                        pred [i] := k;
                        end;
until false;
end;

procedure sort;
var     i , j , t  : Longint;
begin
for i := 1 to r - 1 do
        for j := i + 1 to r do
                if min [card [i]] > min [card [j]] then
                        begin
                        t := card [i];
                        card [i] := card [j];
                        card [j] := t;
                        end;
end;

procedure print;
var     i , j              : Longint;
begin
writeln ( 'Org' , tab , 'Dest' , tab , 'Time' , tab , 'Path' );
for i := 1 to r do
        begin
        write ( card [i] , tab , fire , tab , min [card [i]] );
        j := card [i];
        repeat
                write ( tab , j );
                if j = fire then break;
                j := pred [j];
        until false;
        writeln;
        end;
end;

begin
assign ( input , 'p.in' ); reset ( input );
assign ( output, 'p.out' ); rewrite ( output );

readln ( part );
while ( part > 0 ) do
        begin
        init;
        dijkstra;
        sort;
        print;
        dec ( part );
        if part > 0 then writeln;
        end;
end.
