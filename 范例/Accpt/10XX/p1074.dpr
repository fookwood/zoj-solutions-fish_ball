program p1074;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
        maxn    = 100;

type
        Tnum    = array[0..maxn , 0..maxn] of Longint;

var
        n               : Longint;
        num , sum       : Tnum;

procedure init;
var     i , j   : Longint;
begin
        read ( n );
        fillchar ( sum , sizeof ( sum ) , 0 );
        for i := 1 to n do
                for j := 1 to n do
                        begin
                        read ( num [i] [j] );
                        sum [i] [j] := sum [i - 1] [j] + num [i] [j];
                        end;
end;

function max : Longint;
var     i , j   : Longint;
        k       : Longint;
        t       : Longint;
        hmax    : Longint;
begin
        hmax := 0;
        for i := 1 to n do
                for j := i to n do
                        begin
                        t := 0;
                        for k := 1 to n do
                                begin
                                if t < 0 then t := 0;
                                inc ( t , sum [j] [k] - sum [i - 1] [k] );
                                if t > hmax then hmax := t;
                                end;
                        end;
        max := hmax;
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        {assign ( input , 'p.in' );
        reset ( input );
        assign ( output , 'p.out' );
        rewrite ( output );}
        
        init;
        writeln ( max );
end.
