program p1027;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
        Change  : array[1..5 , 1..5] of Longint =
                ( (5, -1, -2, -1, -3),
                (-1, 5, -3, -2, -4),
                (-2, -3, 5, -2, -2),
                (-1, -2, -2, 5, -1),
                (-3, -4, -2, -1, 0) );

var
        part            : Longint;
        nLeft , nRight  : Longint;
        pLeft , pRight  : array[1..100] of Longint;
        maxGet          : array[0..100,0..100] of Longint;

function num ( ch : Char ) : Longint;
begin
        case ch of
                'A'     : num := 1;
                'C'     : num := 2;
                'G'     : num := 3;
                'T'     : num := 4;
                '-'     : num := 5;
        end;
end;

procedure init;
var     i       : Longint;
        ch      : Char;
begin
        read ( nLeft );
        read ( ch );
        for i := 1 to nLeft do
                begin
                read ( ch );
                pLeft [i] := num ( ch );
                end;
        readln;
        read ( nRight );
        read ( ch );
        for i := 1 to nRight do
                begin
                read ( ch );
                pRight [i] := num ( ch );
                end;
        readln;
end;

procedure Work;
var     i , j   : Longint;
        t       : Longint;
begin
        maxGet [0] [0] := 0;
        for i := 1 to nLeft do
                maxGet [i] [0] := maxGet [i - 1] [0] + change [pLeft [i]] [5];
        for j := 1 to nRight do
                maxGet [0] [j] := maxGet [0] [j - 1] + change [5] [pRight [j]];

        for i := 1 to nLeft do
                for j := 1 to nRight do
                        begin
                        maxGet [i] [j] := maxGet [i - 1] [j] + change [pLeft [i]] [5];
                        t := maxGet [i] [j - 1] + change [5] [pRight [j]];
                        if t > maxGet [i] [j] then maxGet [i] [j] := t;
                        t := maxGet [i - 1] [j - 1] + change [pLeft [i]] [pRight [j]];
                        if t > maxGet [i] [j] then maxGet [i] [j] := t;
                        end;
        writeln ( maxGet [nLeft] [nRight] );
end;



begin
  { TODO -oUser -cConsole Main : Insert code here }
        readln ( part );
        while ( part > 0 ) do
                begin
                init;
                Work;
                dec ( part );
                end;
end.
