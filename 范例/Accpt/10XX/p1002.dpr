program p1002;

{$APPTYPE CONSOLE}

{%File 'p.in'}

uses
  SysUtils;

type
        Tmap    = Object
                len     : Longint;
                wall    : array [0..3 , 0..3] of Boolean;
                procedure init;
                function  max_blockhouse : Longint;
        end;

var     map     : Tmap;

procedure Tmap.init;
var     i , j   : Longint;
        ch      : Char;
begin
        readln ( len );
        dec ( len );
        for i := 0 to len do
                begin
                for j := 0 to len do
                        begin
                        read ( ch );
                        wall [i] [j] := ( ch = 'X' );
                        end;
                readln;
                end;
end;

function Tmap.max_blockhouse : Longint;

type    Tchoose = array[0..3 , 0..3] of Boolean;
var     choose  : Tchoose;
        max     : Longint;
        get     : Longint;
        
        function check ( x , y : Longint ) : Boolean;
        var     i       : Longint;
        begin
                check := false;
                i := x - 1;
                while ( i >= 0 ) do
                        begin
                        if wall [i] [y] then break;
                        if choose [i] [y] then exit;
                        dec ( i );
                        end;
                i := y - 1;
                while ( i >= 0 ) do
                        begin
                        if wall [x] [i] then break;
                        if choose [x] [i] then exit;
                        dec ( i );
                        end;
                check := true;
        end;

        procedure search ( x , y : Longint );
        var     nx , ny : Longint;
        begin
                if x > len then exit;
                nx := x + ord ( y = len );
                ny := ( y + 1 ) mod ( len + 1 );
                
                if wall [x] [y]
                        then search ( nx , ny )
                        else begin
                                if check ( x , y ) then
                                        begin
                                        choose [x] [y] := true;
                                        inc ( get );
                                        if get > max then max := get;
                                        search ( nx , ny );
                                        dec ( get );
                                        choose [x] [y] := false;
                                        end;
                                search ( nx , ny );
                        end;
        end;

begin
        fillchar ( choose , sizeof ( choose ) , 0 );
        max := 0;
        get := 0;
        search ( 0 , 0 );
        max_blockhouse := max;
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        while true do with map do
                begin
                init;
                if len < 0 then break;
                writeln ( max_blockhouse );                
                end;  
end.
