program p1003;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var     a , b           : Longint;
        challenge       : Boolean;
        divideall       : Boolean;

procedure swap ( var a , b : Longint );
var     t       : Longint;
begin
        t := a;
        a := b;
        b := t;
end;

procedure check ( a , b , p : Longint );
begin
        if p > 100 then exit;
        if ( a = 1 ) then challenge := true;
        if ( a = 1 ) and ( b = 1 ) then divideall := true;
        if divideall then exit;
        check ( a , b , p + 1 );
        if a mod p = 0 then check ( a div p , b , p + 1 );
        if b mod p = 0 then check ( a , b div p , p + 1 );
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        While not seekeof do
                begin
                readln ( a , b );
                if a > b then swap ( a , b );
                challenge := false;
                divideall := false;
                check ( a , b , 2 );
                if challenge and not divideall then writeln ( a )
                        else writeln ( b );
                end;
end.
