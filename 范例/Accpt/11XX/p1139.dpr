program p1139;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
        maxn    = 5000;

type
        node    = record
                minx , miny , maxx , maxy       : Longint;
                end;

var
        n       : Longint;
        cover   : array[1..maxn] of Boolean;
        data    : array[1..maxn] of node;
        

procedure init;
var     i       : Longint;
begin
        readln ( n );
        fillchar ( cover , sizeof ( cover ) , 0 );
        for i := 1 to n do
                with data [i] do
                        readln ( minx , maxx , miny , maxy );
end;

procedure Work;
var     i , j   : Longint;
        sum     : Longint;
begin
        for i := 1 to n do
                begin
                for j := 1 to i - 1 do
                        begin
                        if ( data [i].minx >= data [j].minx ) and ( data [i].maxx <= data [j].maxx )
                                and ( data [i].miny >= data [j].miny ) and ( data [i].maxy <= data [j].maxy ) then
                                        cover [i] := true;
                        if ( data [j].minx >= data [i].minx ) and ( data [j].maxx <= data [i].maxx )
                                and ( data [j].miny >= data [i].miny ) and ( data [j].maxy <= data [i].maxy ) then
                                        cover [j] := true;
                        end;
                end;

        sum := 0;
        for i := 1 to n do
                if cover [i] then inc ( sum );
        writeln ( sum );
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        assign ( input , 'p.in' );
        reset ( input );
        assign ( output , 'p.out' );
        rewrite ( output );
        
        while not seekeof do
                begin
                init;
                Work;
                end;
end.
