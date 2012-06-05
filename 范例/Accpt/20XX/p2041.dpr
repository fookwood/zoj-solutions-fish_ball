program p2041;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
        node    = record
                time    : Longint;
                pro     : Longint;
                stout   : Longint;
                end;

var
        part            : Longint;
        n , K , T       : Longint;
        data            : array [0..100] of node;
        Opt             : array [0..100 , 0..100] of Longint;


procedure init;
var     i       : Longint;
begin
        readln ( n , K , T );
        for i := 1 to n do
                read ( data [i].time );
        for i := 1 to n do
                read ( data [i].pro );
        for i := 1 to n do
                read ( data [i].stout );
        data [0].time := 0;
end;

procedure sort;
var     i , j   : Longint;
        temp    : node;
begin
        for i := 1 to n - 1 do
                for j := i + 1 to n do
                        if data [i].time > data [j].time then
                                begin
                                temp := data [i];
                                data [i] := data [j];
                                data [j] := temp;
                                end;
end;

procedure main;
var     i , j   : Longint;
        d       : Longint;
        cost    : Longint;
begin
        for i := 1 to K do Opt [0] [i] := -300000;
        Opt [0] [0] := 0;
        for i := 1 to n do
                begin
                for j := 0 to K do Opt [i] [j] := -300000;
                for j := 0 to K do
                        begin
                        if Opt [i - 1] [j] < 0 then continue;
                        for d := 0 to K do
                                begin
                                if ( data [i].time - data [i - 1].time < abs ( j - d )) then continue;
                                cost := Opt [i - 1] [j];
                                if d = data [i].stout then inc ( cost , data [i].pro );
                                if cost > Opt [i] [d] then Opt [i] [d] := cost;
                                end;
                        end;
                end;
        cost := 0;
        for i := 0 to K do
                if ( Opt [n] [i] > cost ) then
                        cost := Opt [n] [i];
        writeln ( cost );
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
                init;
                sort;
                main;
                dec ( part );
                if part > 0 then writeln;
                end;
end.
