program p1054;

{$APPTYPE CONSOLE}

{%File 'p.in'}

const
        maxn    = 20;

type
        node    = record
                total , give            : Longint;
                have , contain          : Longint;
                end;

        Tcost           = array[1..maxn ] of Longint;
        Tsati           = array[1..maxn ] of Longint;

var
        part , p , n , m                : Longint;
        up , down                       : Longint;
        cost , order , get              : Tcost;
        sati                            : Tsati;
        max                             : Node;

procedure init;
var
        i , j , t , a                  : Integer;
begin
readln ( up , down , n , m );
for i := 1 to n do readln ( cost [i] );
for i := 1 to m do
        begin
        read ( t );
        sati [i] := 0;
        for j := 1 to t do
                begin
                read ( a );
                sati [i] := sati [i] or order [a] ;
                end;
        readln ( get [i] );
        end;
max . give  := 0;
max . total := maxLongint;
max . contain := 0;
max . have := 0;
end;

function make ( p : Longint ) : node;
var
        a , b , i , c            : Longint;
begin
a := 0;
c := 0;
for i := 1 to m do
        if not p and sati [i] = 0 then
                begin
                c := c or order [i];
                inc ( a , get [i] );
                end;
b := 0;
for i := 1 to n do
        if order [i] and p = order [i] then inc ( b , cost [i] );
make .total := b;
make .give  := a;
make .contain := p;
make .have  := c;
end;

procedure main;
var
        i                       : Longint;
        temp                    : Node;
begin
for i := 1 to m do
        if sati [i] <> max . contain then
                begin
                temp := make ( sati [i] );
                if abs ( temp . give / temp . total - max . give / max . total ) < 1e-10 then
                        begin
                        if ( max . total + temp . total <= down ) then
                                begin
                        max . total := max . total + temp . total;
                        max . give  := max . give  + temp . give;
                        max . have  := max . have  or temp . have;
                        max . contain := max . contain or temp . contain;
                                end else
                                if ( max . total < temp . total ) and ( temp . total < down ) then
                                max := temp;
                        end;
                if ( temp . give / temp . total > max . give / max . total ) and ( temp . total < down )then
                        max := temp;
                end;
                
if max . total < up then
        begin
        for i := m downto 1 do
                if ( not max . contain and sati [i] > 0 ) then
                        begin
                        temp := make ( sati [i] or max .contain);
                        if ( temp . total <= down ) and ( temp . total >= up ) and
                        ( ( temp . give / temp . total > max . give / max . total ) or ( max . total < up ) ) then
                                max := temp;
                        end;
                        
        for i := 1 to n do
                if ( not max . contain and order [i] > 0 ) then
                        begin
                        temp := make ( order [i] or max . contain );
                        if ( temp . total <= down ) and ( temp . total >= up ) and
                        ( ( temp . give / temp . total > max . give / max . total ) or ( max . total < up ) ) then
                                max := temp;
                        end;
        end;
end;

procedure print;
var
        i                       : Longint;
        first                   : Boolean;
begin
with max do
        begin
        writeln ( round ( 1000 *  give / total ) / 1000: 0 : 3);
        writeln ( give );
        writeln ( total );
        first := true;
        for i := 1 to n do
                if order [i] and contain = order [i] then
                        begin
                        if not first then write ( ' ' )
                                else first := false;
                        write ( i );
                        end;
        writeln ;
        first := true;
        for i := 1 to m do
                if order [i] and have = order [i] then
                        begin
                        if not first then write ( ' ' )
                                else first := false;
                        write ( i );
                        end;
        writeln ;
        end;
end;

begin
order [1] := 1; for p := 2 to maxn do order [p] := order [p - 1] shl 1;
readln ( part );
for p := 1 to part do
        begin
        writeln ( 'Feature Set ' , p );
        init;
        main;
        print;
        end;
end.
