program p1134;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
        Ans     : array[1..4] of String =
        (' is self-inventorying' ,
        ' is self-inventorying after ',
        ' enters an inventory loop of length ',
        ' can not be classified after 15 iterations' );

var
        part    : Longint;
        num     : array['0'..'9'] of Longint;

function Change ( var s : String ) : String;
var     t       : String;
        tt      : String;
        i       : Longint;
        ch      : Char;
begin
        fillchar ( num , sizeof ( num ) , 0 );
        for i := 1 to length ( s ) do inc ( num [s [i]] );
        for ch := '0' to '9' do
                begin
                if num [ch] = 0 then continue;
                str ( num [ch] , tt );
                t := t + tt + ch;
                end;
        Change := t;
end;

function checkSelf_Inventorying ( var s : String ) : Boolean;
var     t       : String;
begin
        t := Change ( s );
        checkSelf_Inventorying := ( s = t );
end;

function checkSelf_InventoryingAfter ( s : String ) : Longint;
var     i       : Longint;
begin
        for i := 1 to 15 do
                begin
                s := Change ( s );
                if not checkSelf_Inventorying ( s ) then continue;
                checkSelf_InventoryingAfter := i;
                exit;
                end;
        checkSelf_InventoryingAfter := -1;
end;

function checkLoop ( s : String ) : Longint;
var     save    : array [0..15] of String;
        i       : Longint;
        j       : Longint;
begin
        save [0] := s;
        for i := 1 to 15 do
                begin
                save [i] := Change ( save [i - 1] );
                for j := 0 to i - 1 do
                        if save [i] = save [j] then
                                begin
                                checkLoop := i - j;
                                exit;
                                end;
                end;
        checkLoop := -1;
end;

procedure check ( s : String );
var     t       : Longint;
begin
        if checkSelf_Inventorying ( s ) then
                begin
                writeln ( Ans [1] );
                exit;
                end;
        t := checkSelf_InventoryingAfter ( s );
        if t > 0 then begin
                writeln ( Ans [2] , t , ' steps' );
                exit;
                end;
        t := checkLoop ( s );
        if t > 0 then begin
                writeln ( Ans [3] , t );
                exit;
                end;
        writeln ( Ans [4] );
end;

procedure Work;
var     s       : String;
begin
        while true do
                begin
                readln ( s );
                if s = '-1' then break;
                write ( s );
                check ( s );
                end;
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }

        assign ( input , 'p.in' );
        reset ( input );
        assign ( output , 'p.out' );
        rewrite ( output );

        readln ( part );
        while ( part > 0 ) do
                begin
                readln;
                Work;
                dec ( part );
                if part > 0 then writeln;
                end;
end.
