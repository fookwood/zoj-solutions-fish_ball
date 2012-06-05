program p2098;

{$APPTYPE CONSOLE}

{%File 'p.in'}

const
        maxn    = 50;

type
        Topt    = array[1..50] of Longint;

var
        n               : Longint;
        TotalC          : Longint;
        TotalP          : Longint;
        C , P           : Topt;
        Up              : Topt;

procedure init;
var     i       : Longint;
begin
TotalC := 0;
for i := 1 to n do begin read ( C [i] ); inc ( TotalC , C [i] ); end;
for i := 1 to n do read ( P [i] );
end;

procedure main;
var     i , j           : Longint;
        Ans1 , Ans2     : Extended;
begin
fillchar ( Up , sizeof ( Up ) , 0 );
for i := 1 to n do
        begin
        if P [i] > C [i] then begin writeln ( 0.0 : 0 : 5 ); exit; end;

        if P [i] > C [i] - P [i] then P [i] := C [i] - P [i];
        for j := 1 to P [i] do
                begin
                inc ( Up [C [i] - P [i] + j] );
                dec ( Up [j] );
                end;
        end;

if TotalP > TotalC - TotalP then TotalP := TotalC - TotalP;
for j := 1 to TotalP do
        begin
        dec ( Up [TotalC - TotalP + j] );
        inc ( Up [j] );
        end;

Ans1 := 1; Ans2 := 1;
for i := 1 to 50 do
        begin
        if Up [i] > 0 then
                for j := 1 to Up [i] do Ans1 := Ans1 * i;

        if Up [i] < 0 then
                for j := 1 to abs ( Up [i] ) do Ans2 := Ans2 * i;
        end;
        
writeln ( Ans1 / Ans2 : 0 : 5 );
end;

begin
while ( true ) do
        begin
        readln ( n , TotalP ); if n = -1 then break;
        init;
        main;
        end;
end.
