program p1099;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
        OWord   : String;
        P       : Longint;

procedure puts ( OWord : String );
var     i       : Longint;
begin
        if OWord = '<br>' then
                begin
                writeln;
                P := 0;
                end else
        if OWord = '<hr>' then
                begin
                if P <> 0 then writeln;
                for i := 1 to 80 do write ( '-' ); writeln;
                P := 0;
                end else
        if ( P = 0 ) then
                begin
                write ( OWord );
                P := length ( OWord );
                end else
                begin
                inc ( P , length ( OWord ) + 1 );
                if ( P <= 80 ) then write ( ' ' , OWord )
                        else begin
                        writeln;
                        write ( OWord );
                        P := length ( OWord );
                        end;
                end;
end;

procedure Work;
var     ch      : Char;
begin
        P := 0;
        while not seekeof do
                begin
                read ( ch );
                OWord := '';
                while ( ch <> ' ' ) and ( ord ( ch ) > 13 ) do
                        begin
                        OWord := OWord + ch;
                        read ( ch );
                        end; 
                if OWord <> '' then puts ( OWord );
                end;
        writeln;
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        Work;
end.
