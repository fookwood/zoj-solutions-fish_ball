program p1104;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
        n       : Longint;
        i       : Longint;
        x , y   : array [1..100] of Double;

procedure main;
var     t       : Double;
        slop    : Double;
        a       : Double;
        i       : Longint;
begin
        a := 1e20;
        for i := 2 to n do
                begin
                t := y [i] / x [i - 1] / ( x [i - 1] - x [n] );
                if t < a then a := t;
                if i = n then continue;
                t := y [i] / x [i] / ( x [i] - x [n] );
                if t < a then a := t;
                end;
                
        slop := - a * x [n];
        t := sqrt ( - ( 1 + sqr ( slop )) * 9.8 / a / 2 );
        writeln ( arctan ( slop ) * 180 / pi : 0 : 2 , ' ' , t : 0 : 2 );
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        assign ( input , 'p.in' );
        reset ( input );
        assign ( output , 'p.out' );
        rewrite ( output );
        
        while not seekeof do
                begin
                readln ( n );
                for i := 1 to n do
                        begin
                        readln ( y [i] , x [i] );
                        if i > 1 then x [i] := x [i] + x [i - 1];
                        end;
                main;
                end;
end.
