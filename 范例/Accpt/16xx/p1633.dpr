program p1633;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
        N       : Int64;
        F       : array [1..91] of Int64;
        
function Answer ( N : Int64 ) : Char;
var     i       : Integer;
begin
        Answer := ' ';
        i := 89;
        while ( N > 7 ) do
                begin
                while ( N <= F [i] ) do dec ( i );
                N := N - F [i];
                end;
        case N of
                1       : Answer := 'T';
                2       : Answer := '.';
                3       : Answer := 'T';
                4       : Answer := '^';
                5       : Answer := '_';
                6       : Answer := '_';
                7       : Answer := '^';
        end;
end;

var     i       : integer;
begin
  { TODO -oUser -cConsole Main : Insert code here }
        F [1] := 4; F [2] := 3;
        for i := 3 to 89 do F [i] := F [i - 1] + F [i - 2];

        while ( not EOF ) do
                begin
                readln ( N );
                writeln ( Answer ( N ));
                end;
end.
