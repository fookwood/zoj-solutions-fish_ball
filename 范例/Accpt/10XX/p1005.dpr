program p1005;

{$APPTYPE CONSOLE}

{%File 'p.in'}

uses
  SysUtils;

var
        X , Y , Z       : Longint;

procedure ret ( X , Y , Z : Longint ; var A , B : Longint );
var     i       : Longint;
begin
        i := ( Z - 1 ) div X + 1;
        while true do
                begin
                if ( X * i - Z ) mod Y = 0 then
                        begin
                        A := i; B := ( A * X - Z ) div Y;
                        exit;
                        end;                 
                inc ( i );
                end;        
end;

procedure WorkWith ( X , Y , Z : Longint );
var     A , B   : Longint;
        FA , FB : Longint;

        procedure fillA;
        begin
                FA := X; dec ( A );
                writeln ( 'fill A' );
        end;

        procedure emptyB;
        begin
                FB := 0; dec ( B );
                writeln ( 'empty B' );
        end;

        procedure pourAB;
        begin
                if FA > Y - FB
                        then begin
                        dec ( FA , Y - FB ); FB := Y;
                        end
                        else begin
                        inc ( FB , FA ); FA := 0;
                        end;
                writeln ( 'pour A B' );
        end;

begin
        ret ( X , Y , Z , A , B );
        FA := 0; FB := 0;
        while ( A <> 0 ) or ( B <> 0 ) do
                begin
                if ( FA = 0 ) and ( A > 0 ) then fillA;
                if ( FB = Y ) and ( B > 0 ) then emptyB;
                if ( FA > 0 ) then pourAB;
                end;
        if ( X > Y ) and ( FB > 0 ) then writeln ( 'pour B A' );
        if ( X <= Y ) and ( FA > 0 ) then pourAB;
        writeln ( 'success' );
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        while not seekeof do
                begin
                readln ( X , Y , Z );
                WorkWith ( X , Y , Z );
                end;  
end.
