program p1146;

{$APPTYPE CONSOLE}

{%File 'p.in'}

uses
  SysUtils;

const
        change  : array[0..9 , 1..7] of Boolean =
                ((true, true, true, false, true, true, true),
                (false, false , true, false, false, true , false ),
                (true, false, true, true, true, false, true),
                (true, false, true, true, false, true, true),
                (false, true, true, true, false, true, false),
                (true, true, false, true, false, true, true),
                (true, true, false, true, true, true, true),
                (true, false, true, false, false, true, false),
                (true, true, true, true, true, true, true),
                (true, true, true, true, false, true, true));

var
        long , num      : Longint;
        map             : array[1..40 , 1..140] of Char;

procedure PutsIn ( dx , p : Longint );
var     i       : Longint;
begin
        if change [p] [1] then for i := 1 to long do map [1] [dx + i + 1] := '-';
        if change [p] [2] then for i := 1 to long do map [i + 1] [dx + 1] := '|';
        if change [p] [3] then for i := 1 to long do map [i + 1] [dx + long + 2] := '|';
        if change [p] [4] then for i := 1 to long do map [long + 2] [dx + i + 1] := '-';
        if change [p] [5] then for i := 1 to long do map [long + 2 + i] [dx + 1] := '|';
        if change [p] [6] then for i := 1 to long do map [long + 2 + i] [dx + long + 2] := '|';
        if change [p] [7] then for i := 1 to long do map [long + long + 3] [dx + i + 1] := '-';
end;

procedure Work;
var     Snum    : String;
        i       : Longint;
        j       : Longint;
        last    : Longint;
begin
        Str ( num , Snum );
        fillchar ( map , sizeof ( map ) , ' ' );
        for i := 1 to length ( Snum ) do
                PutsIn ( (i - 1) * ( long + 3 ) , ord ( Snum [i] ) - 48 );
        for i := 1 to 2 * long + 3 do
                begin
                last := ( long + 3 ) * length ( Snum ) - 1;
                //while ( map [i] [last] = ' ' ) do dec ( last );
                for j := 1 to last do
                        write ( map [i] [j] );
                writeln;
                end;
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        assign ( input , 'p.in' );
        reset ( input );
        assign ( output , 'p.out' );
        rewrite ( output );
       
        while true do
                begin
                readln ( long , num );
                if long = 0 then break;
                Work;
                writeln;
                end;
end.
