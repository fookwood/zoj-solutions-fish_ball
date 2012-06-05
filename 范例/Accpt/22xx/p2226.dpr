program p2226;

{$APPTYPE CONSOLE}

const
        maxn    = 70;

type
        TA      = array[1..maxn , 0..maxn ] of Longint;

var
        part , d , p , n    : Longint;
        A               : TA;

procedure base_gcd ( a , b : Longint; var x , y : Longint );
var
        t                       : Longint;
begin
if a > b then
        begin
        t := a;
        a := b;
        b := t;
        end;
if a = 0 then
        begin
        x := 0;
        y := 1;
        end else
        begin
        base_gcd ( b mod a , a , x , y );
        t := y;
        y := x;
        x := t - ( b div a ) * x;
        end;
end;

function base_solve ( a , b : Longint ) : Longint;
var
        x , y                   : Longint;
begin
base_gcd ( a , p , x , y );
base_solve := ( ( x + p ) * b ) mod p; 
end;

procedure init;
var
        i , j           : Longint;
        ch              : Char;
begin
read ( p );
read ( ch );
while ( ch = ' ' ) do read ( ch );
n := 0;
inc ( n );
if ch = '*' then A [n] [0] := 0
        else A [n] [0] := ord ( ch ) - 96; 

while not eoln and not eof do
        begin
        inc ( n );
        read ( ch );
        if ch = '*' then A [n] [0] := 0
                else A [n] [0] := ord ( ch ) - 96;
        end;
readln;

for i := 1 to n do
        begin
        A [i] [1] := 1;
        for j := 2 to n do A [i] [j] := ( A [i] [j - 1] * i ) mod p;
        end;
{for i := 1 to n do
        begin
        for j := 1 to n do write ( A [i] [j] ,' ' );
        writeln;
        end;}
end;

procedure main;
var
        i , j , k , t            : Longint;
begin
for i := 1 to n do
        begin
        t := base_solve ( A [i] [i] , 1 );
        if t <> 1 then
                begin
                for j := i to n do
                        A [i] [j] := A [i] [j] * t mod p;
                A [i] [0] := A [i] [0] * t mod p;
                end;

        for j := i + 1 to n do
                begin
                t := A [j] [i];
                for k := i to n do
                        A [j] [k] := ( ( A [j] [k] - A [i] [k] * t ) mod p + p ) mod p;
                A [j] [0] := ( ( A [j] [0] - A [i] [0] * t ) mod p + p ) mod p;
                end;
        {for j := 1 to n do
                begin
                for k := 0 to n do write ( A [j] [k] , ' ' );
                writeln;
                end;
        writeln;}
        end;
        
for i := n downto 1 do
        for j := i - 1 downto 1 do
                A [j] [0] := ( ( A [j] [0] - A [i] [0] * A [j] [i] ) mod p + p ) mod p;
end;

procedure print;
var
        i                       : Longint;
begin
for i := 1 to n - 1 do write ( A [i] [0] , ' ' );
writeln ( A [n] [0] );
end;

begin
{assign ( input ,'p.in' );
reset ( input );
assign ( output ,'p.out' );
rewrite ( output );}
readln ( part );
for d := 1 to part do
        begin
        init;
        main;
        print;
        end;
end.
