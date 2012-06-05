program p1068;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
        card    : array['A' .. 'Z'] of String =
        ( '.-' , '-...' , '-.-.' , '-..' , '.' ,
          '..-.' , '--.' , '....' , '..' , '.---' ,
          '-.-' , '.-..' , '--' , '-.' , '---' ,
          '.--.' , '--.-' , '.-.' , '...' , '-' ,
          '..-' , '...-' , '.--' , '-..-' , '-.--' ,
          '--..' );

var
        p       : Longint;
        part    : Longint;
        name    : String;

function change ( s : Char ) : String;
begin
        if s = '_' then change := '..--' else
        if s = '.' then change := '---.' else
        if s = ',' then change := '.-.-' else
        if s = '?' then change := '----' else
        change := card [s];
end;

function back ( var s : String ) : Char;
var     ch      : Char;
begin
        if s = '..--' then back := '_' else
        if s = '---.' then back := '.' else
        if s = '.-.-' then back := ',' else
        if s = '----' then back := '?' else
                for ch := 'A' to 'Z' do
                        if card [ch] = s then back := ch;
end;

procedure Work;
var     i , j   : Longint;
        Temp    : String;
        ch      : Char;
        All_    : AnsiString;
        Tot     : Longint;
begin
        write ( p , ': ' );
        All_ := '';
        for i := 1 to length ( name ) do
                All_ := All_ + change ( name [i]);
        Tot := 0;
        for i := length ( name ) downto 1 do
                begin
                Temp := '';
                for j := 1 to length ( change ( name [i] )) do
                        Temp := Temp + All_ [Tot + j];
                inc ( Tot , length ( change ( name [i] )));
                write ( back ( Temp ));
                end;
        writeln;
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        readln ( part );
        for p := 1 to part do
                begin
                readln ( name );
                Work;
                end;
end.
