// not Accept

program p1575;

{$APPTYPE CONSOLE}

const
        maxn    = 7;
        maxp    = 16384;

type
        node    = record
                x , y           : Extended ;
        end;
        Tdata   = array[0..maxp ] of node;

var
        n , p , i               : Longint;
        data                    : Tdata;

procedure prepare ( left , right : Longint );
var
        m                       : Longint;
        dx , dy                 : Real;
begin
if ( right - left <= 1 ) then exit;

m := ( right - left ) div 4;

with data [ left + m ] do
        begin
        x := ( data [left] .x + data [right] .x / 2 ) / 1.5;
        y := ( data [left] .y + data [right] .y / 2 ) / 1.5;
        prepare ( left , left + m );
        end;

with data [ right - m ] do
        begin
        x := ( data [left] .x + data [right] .x * 2 ) / 3;
        y := ( data [left] .y + data [right] .y * 2 ) / 3;
        prepare ( right - m , right );
        end;

dx := data [right] .x - data [left] .x;
dy := data [right] .y - data [left] .y;
with data [ left + m + m ] do
        begin
        x := data [ left + m ] .x + ( dx - sqrt ( 3 ) * dy ) / 6;
        y := data [ left + m ] .y + ( dy + sqrt ( 3 ) * dx ) / 6;
        prepare ( left + m , left + m + m );
        prepare ( left + m + m , right - m );
        end;
end;

procedure print ( x : Extended );
begin
if abs ( x ) < 1e-7 then write ('0.00' )
        else write ( x :0 :2 );
end;

begin
{assign ( input , 'p.in' );
reset ( input );
assign ( output , 'p.out' );
rewrite ( output );}

while not eof do
        begin
        readln ( n );
        p := round ( exp ( n * ln ( 4 ) ) );
        readln ( data [0] .x , data [0] .y , data [p] .x , data [p] .y );

        prepare ( 0 , p );

        for i := 0 to p do
                begin
                print ( data [i] . x );
                write ( ' ' );
                print ( data [i] . y );
                writeln;
                end;
        writeln;
        end;
end.
