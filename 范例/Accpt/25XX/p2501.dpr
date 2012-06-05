program p2501;

{$APPTYPE CONSOLE}

const
        maxn    = 50000;

type
        Topt    = array[0..1 , 1..maxn] of Longint;
        Tpass   = array[0..maxn] of Longint;

var
        part , p , n , r                : Longint;
        opt                             : Topt;
        pass , Sum                      : Tpass;

procedure init;
var     i                               : Longint;
begin
readln ( n ); for i := 1 to n do read ( pass [i] ); readln; readln ( r );

Sum [0] := 0;
Sum [1] := pass [1];
for i := 2 to n do Sum [i] := Sum [i - 1] + pass [i];

for i := 1 to n - r do pass [i] := Sum [i + r - 1] - Sum [i - 1];
for i := n - r + 1 to n do pass [i] := Sum [n] - Sum [i - 1];
end;

procedure work;
var     i , j , a , b , Max , T                 : Longint;
begin
a := 0; b := 1;
for i := 1 to n do opt [a] [i] := 0;

for i := 0 to 2 do
        begin
        Max := 0;
        for j := r * i + 1 to n - ( 3 - i ) * r + 1 do
                begin
                if ( j - r > 0 ) then T := opt [a] [j - r] + pass [j] else T := pass [j];
                if ( T > Max ) then Max := T;
                opt [b] [j] := Max;
                end;
        a := 1 - a;
        b := 1 - b;
        end;
        
writeln ( Max ); 
end;

begin
readln ( part );
for p := 1 to part do
        begin
        init;
        work;
        end;
end.
