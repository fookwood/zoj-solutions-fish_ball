{$R-,I-,Q-}
PROGRAM p2456;

type

        Tans                    = array[1..10,0..2000] of Integer;
        Ta                      = array[0..2000] of Integer;
        TFirst                  = array[0..35, 0..35, 0..37] of Integer;

VAR
        f3                      : Text;
        N , B , Total           : Integer;
        ans                     : Tans;
        A                       : Ta;
        First                   : TFirst;


procedure makeFirst;
var
        i , j , k , d , x , y , e       : Integer;

function extended_gcd ( a , b : Integer ; var x , y : Integer ) : Integer;
var
        t                               : Integer;
begin
if a = 0 then
        begin
        extended_gcd    := b;
        x               := 1;
        y               := 0;
        end else
        begin
        extended_gcd    := extended_gcd ( b mod a , a , x , y );
        t               := x;
        x               := y;
        y               := t - ( b div a ) * y;
        end;
end;

begin
for i := 0 to B - 1 do
        begin
        d := extended_gcd ( i , B , y , x );
        for j := 0 to B - 1 do
                begin
                First [i] [j] [0] := 0;
                if j mod d = 0 then
                        begin
                        First [i] [j] [0] := d;
                        e := ( ( x + B ) * ( j div d ) ) mod B;
                        for k := 0 to d - 1 do
                                First [i] [j] [k + 1] := ( e + k * B div d ) mod B;
                        end;
                end;
        end;
end;

procedure init;
begin
Total := 0;
makeFirst;
end;

procedure search ( dep , r : Longint );
var
        i , sum , left , right                : Longint;
begin
if dep = n then
        begin
        if A [n - 1] <> 0 then
                begin
                inc ( total );
                for i := 0 to n - 1 do
                        ans [total] [i] := A [i];
                end;
        exit;
        end;

sum := r;
for i := 1 to dep - 1 do
        sum := sum + A [i] * A [dep - i];

left  := ( 2 * A [0] - 1 + B ) mod B;
right := ( B - ( sum mod B ) ) mod B;

for I := 1 to First [left] [right] [0] do
        begin
        A [dep] := First [left] [right] [i];
        search ( dep + 1 , ( ( 2 * A [0] - 1 ) * A [dep] + sum ) div B );
        end;
end;

procedure main;
var
        i , t                   : Integer;
begin
for i := 0 to B - 1 do
        begin
        A [0] := i;
        if sqr ( i ) mod B <> i mod B then continue;

        t := sqr ( i ) div B;
        search ( 1 , t );
        end;
end;

procedure print;
var
        i , j                    : Integer;
begin
if ( n = 1 ) then
        begin
        inc ( Total );
        ans [total] [0] := 0;
        end;

writeln ( Total );
for i := 1 to Total do
        begin
        for j := N - 1 downto 0 do
                if ans [i] [j] >= 10 then
                        write ( Char ( ans [i] [j] - 10 + ord ( 'A' ) ) )
                        else
                        write ( ans [i] [j] );
        writeln;
        end;
end;


BEGIN
//assign ( input ,'p.in' );
//reset ( input );
while not eof do
        begin
        readln ( B , N );
        init;
        main;
        print;
        end;
END.