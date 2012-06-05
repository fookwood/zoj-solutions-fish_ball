program p1007;

{$APPTYPE CONSOLE}

uses
  SysUtils;

procedure work;
var     x       : Extended;
        Tot     : Extended;
        i       : Longint;
begin
        x := 0;
        while ( x - 1e-10 < 2.0 ) do
                begin
                Tot := 0;
                for i := 1 to 16000 do Tot := Tot + 1 / (i * ( i + 1 ) * ( i + x ));
                Tot := ( 1 - x ) * ( Tot + 1 / 2 / 16000 / 16000 ) + 1;
                writeln ( x : 0 : 3 , ' ' , Tot : 0 : 12 );
                x := x + 0.001;
                end;
        
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        work;
end.
