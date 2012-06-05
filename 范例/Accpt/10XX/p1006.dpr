program p1006;

{$APPTYPE CONSOLE}

{%File 'p.in'}

uses
  SysUtils;

type
        Tdata   = array [0..70] of Longint;

var     k       : Longint;
        len     : Longint;
        data    : Tdata;
        ansa    : Tdata;

procedure work;
var     ch      : Char;
        i       : Longint;
begin
        read ( k );
        if k = 0 then halt;
        read ( ch );
        len := -1;
        while not seekeoln do
                begin
                read ( ch ); inc ( len );
                case ch of
                        '_'     : data [len] := 0;
                        '.'     : data [len] := 27;
                        else    data [len] := ord ( ch ) - ord ( 'a' ) + 1;
                end;
                end;
        inc ( len );
        for i := 0 to len - 1 do ansa [k * i mod len] := ( data [i] + i ) mod 28;
        for i := 0 to len - 1 do
                case ansa [i] of
                0       : write ( '_' );
                27      : write ( '.' );
                else    write ( chr ( ansa [i] + ord ( 'a' ) - 1 ) );
                end;
        writeln;
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        while true do work;
end.
