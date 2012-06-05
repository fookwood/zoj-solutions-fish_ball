program p1123;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
        map     : array[-9..9 , -9..9] of Boolean;
        x       : array[0..2] of Longint;
        y       : array[0..2] of Longint;

procedure init;
var     i       : Longint;
begin
        for i := 0 to 2 do read ( x [i] , y [i] );
end;

function RangeIn ( x_ , y_ : Longint ) : Boolean;
var     t       : Longint;
        j       : Longint;
        i       : Longint;
begin
        for i := 0 to 2 do
                begin
                j := ( i + 1 ) mod 3;
                t := ( x [i] - x_ ) * ( y [j] - y_ ) - ( y [i] - y_ ) * ( x [j] - x_ );
                if t < 0 then continue;
                RangeIn := false;
                exit;
                end;
        RangeIn := true;
end;

procedure Work;
var     i , j   : Longint;
        minx    : Longint;
        miny    : Longint;
        maxx    : Longint;
        maxy    : Longint;
        last    : Longint;
begin
        minx := 10; miny := 10;
        maxx := -10; maxy := -10;

        for i := -9 to 9 do
                for j := -9 to 9 do
                        begin
                        map [i] [j] := RangeIn ( j , i );
                        if not map [i] [j] then continue;
                        if i > maxy then maxy := i;
                        if i < miny then miny := i;
                        if j > maxx then maxx := j;
                        if j < minx then minx := j;
                        end;

                        
        for i := maxy downto miny do
                begin
                last := maxx;
                while ( last > minx ) and not map [i] [last] do dec ( last );
                for j := minx to last do
                        begin
                        if j > minx then write ( ' ' );
                        if map [i] [j] then write ( '(' , j : 2 , ',' , i : 3 , ')' )
                                else write ( '        ' );
                        end;
                writeln;
                end;
        writeln;
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        writeln ( 'Program 4 by team X' );
        while not seekeof do
                begin
                init;
                Work;
                end;
        writeln ( 'End of program 4 by team X' );
end.
