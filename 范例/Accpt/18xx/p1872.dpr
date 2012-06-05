// Accept
// Time 2005/06/08
program p1872;

{$APPTYPE CONSOLE}

const
        maxn    = 100;

type
        TLine   = array[1..maxn , 1..maxn ] of Real;
        Tmin    = array[1..maxn ] of Real;
        Tcover  = array[1..maxn ] of Boolean;
        TPos    = array[1..maxn ] of Real;
        Tprev   = array[1..maxn ] of Integer;

var
        n                       : Integer;
        x , y                   : TPos;
        dis                     : TLine;
        min                     : Tmin;
        cover                   : Tcover;
        prev                    : Tprev;      

procedure init;
var
        i , j                   : Integer;
begin
readln ( n );
for i := 1 to n do
        begin
        readln ( x [i] , y [i] );
        for j := 1 to i do
                begin
                dis [i] [j] := sqrt ( sqr ( x [i] - x[j] ) + sqr ( y [i] - y [j] ) );
                dis [j] [i] := dis [i] [j];
                end;
        end;
end;

procedure main;
var
        i , j , k                       : Integer;
        sum , T                         : Real;
begin
sum := 0;
for j := 2 to n do
        begin
        min [j] := dis [1] [j];
        prev [j] := 1;
        end;
        
fillchar ( cover , sizeof ( cover ) , 0 );

for i := 2 to n do
        begin
        T := 1e10;
        for j := 2 to n do
                if not cover [j] and ( min [j] < T ) then
                        begin
                        T := min [j];
                        k := j;
                        end;
        cover [k] := true;
        sum := sum + dis [prev [k]] [k];
        for j := 2 to n do
                if not cover [j] and ( dis [k] [j] < min [j] ) then
                        begin
                        prev [j] := k;
                        min [j] := dis [k] [j];
                        end;
        end;
writeln ( sum :0 :2 );
end;

begin
assign ( input ,'p.in' );
reset ( input );
assign ( output , 'p.out' );
rewrite ( output );

while not eof do
        begin
        init;
        main;
        end;
end.
