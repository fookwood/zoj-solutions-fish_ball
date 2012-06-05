program p1096;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
        d , m , a , j   : Extended;

function MinTime : Extended;
var     S , t1 , t11    : Extended;       
begin
        if a * a > m * j
                then begin
                t1 := sqrt ( m / j );
                S := j * t1 * t1 * t1;
                end
                else begin
                t1 := a / j;
                t11 := m / j / t1 - t1;
                S := j * t1 * t1 * t1
                        + 1.5 * j * t1 * t1 * t11
                        + 0.5 * j * t1 * t11 * t11;
                end;
                
        if 2 * S > d
                then begin
                t1 := exp ( ln ( d / j / 2 ) / 3 );
                if j * t1 <= a
                        then MinTime := 4 * t1
                        else begin
                        t1 := a / j;
                        t11 := ( - 3 * t1 + sqrt ( sqr ( t1 ) + 4 * d / a )) / 2;
                        MinTime := 4 * t1 + 2 * t11;
                        end;
                end else
                begin
                if a * a > m * j then MinTime := 4 * t1 + ( d - 2 * S ) / m
                        else MinTime := 4 * t1 + 2 * t11 + ( d - 2 * S ) / m;
                end;
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        while not seekeof do
                begin
                readln ( d , m , a , j );
                writeln ( MinTime : 0 : 1 );
                end;
end.
