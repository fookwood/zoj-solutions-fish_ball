program p1066;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
        map     : array[1..50 , 1..50] of Char;
        matrix  : array[1..11 , 1..11] of Longint;
        fill    : array[1..50 , 1..50] of Longint;
        n       : Longint;
        step    : Longint;

procedure init;
var     i , j   : Longint;
begin
        for i := 1 to n do
                begin
                for j := 1 to n do read ( matrix [i] [j] );
                readln;
                end;
end;

procedure Work;
var     i , j   : Longint;
begin
        fillchar ( fill , sizeof ( fill ) , 0 );
        fillchar ( map , sizeof ( map ) , ' ' );

        for i := 1 to 4 * n - 1 do
                begin
                map [i] [1] := '*';
                map [i] [4 * n + 3] := '*'
                end;
        for i := 1 to 4 * n + 3 do
                begin
                map [1] [i] := '*';
                map [4 * n - 1] [i] := '*';
                end;

        for i := 1 to n do
                for j := 1 to n do
                        map [4 * i - 2] [4 * j] := 'O';

        for i := 1 to n do
                for j := 1 to n + 1 do
                        map [4 * i - 2] [4 * j - 2] := 'H';
        for i := 1 to n - 1 do
                for j := 1 to n do
                        map [4 * i] [4 * j] := 'H';


        for i := 1 to n do
                for j := 1 to n do
                        begin
                        if matrix [i] [j] = 1 then
                                begin
                                map [4 * i - 2] [4 * j - 1] := '-';
                                map [4 * i - 2] [4 * j + 1] := '-';
                                inc ( fill [4 * i - 2] [4 * j] , 2 );
                                inc ( fill [4 * i - 2] [4 * j - 2] );
                                inc ( fill [4 * i - 2] [4 * j + 2] );
                                end;
                        if matrix [i] [j] = -1 then
                                begin
                                map [4 * i - 3] [4 * j] := '|';
                                map [4 * i - 1] [4 * j] := '|';
                                inc ( fill [4 * i - 2] [4 * j] , 2 );
                                inc ( fill [4 * i - 4] [4 * j] );
                                inc ( fill [4 * i] [4 * j] );
                                end;
                        end;

        for i := 1 to n do
                for j := 1 to n do
                        if matrix [i] [j] = 0 then
                                begin
                                if ( i > 1 ) and ( fill [4 * i - 4] [4 * j] = 0 )
                                        then begin
                                        map [4 * i - 3] [4 * j] := '|';
                                        inc ( fill [4 * i - 4] [4 * j] );
                                        end
                                        else begin
                                        map [4 * i - 1] [4 * j] := '|';
                                        inc ( fill [4 * i] [4 * j] );
                                        end;
                                if fill [4 * i - 2] [4 * j - 2] = 0
                                        then begin
                                        map [4 * i - 2] [4 * j - 1] := '-';
                                        inc ( fill [4 * i - 2] [4 * j - 2] );
                                        end
                                        else begin
                                        map [4 * i - 2] [4 * j + 1] := '-';
                                        inc ( fill [4 * i - 2] [4 * j + 2] );
                                        end;
                                end;
end;

procedure print;
var     i , j   : Longint;
begin
        writeln ( 'Case ' , Step , ':' );
        writeln;
        for i := 1 to 4 * n - 1 do
                begin
                for j := 1 to 4 * n + 3 do
                        write ( map [i] [j] );
                writeln;
                end;
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        Step := 0;
        while true do
                begin
                readln ( n ); if n = 0 then break;
                inc ( Step );
                if Step > 1 then writeln;
                init;
                Work;
                print;
                end;
end.
