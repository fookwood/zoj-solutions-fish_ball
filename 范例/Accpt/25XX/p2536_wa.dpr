program p2536;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
        MaxC    = 100000;

var
        part    : Longint;
        p       : Longint;
        n       : Longint;
        m       : Longint;
        Limit   : Longint;
        num     : array [1..30] of Longint;
        whether : array [0..maxC * 20] of Boolean;

procedure init;
var     i       : Longint;
        j       : Longint;
        t       : Longint;
begin
        read ( n , m );
        for i := 1 to n do read ( num [i] );
        for i := 1 to n - 1 do
                for j := i + 1 to n do
                        if num [i] > num [j] then
                                begin
                                t := num [i];
                                num [i] := num [j];
                                num [j] := t;
                                end;
        readln;
        Limit := 0;
end;

procedure Puts ( x : Longint );
var     i       : Longint;
begin
        inc ( Limit , x );
        for i := Limit downto 0 do
                whether [i] := whether [i] or whether [i - x];
end;

procedure main;
var     i       : Longint;
        j       : Longint;
begin
        fillchar ( whether , sizeof ( whether ) , 0 );
        whether [0] := true;
        j := 0;
        for i := 1 to n do
                begin
                Puts ( num [i] );
                while whether [j] do inc ( j );
                end;
                
        for i := 1 to m do
                begin
                Puts ( j );
                while whether [j] do inc ( j );
                end;
        writeln ( j );
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        assign ( input , 'p.in' );
        reset ( input );
        assign ( output , 'p.out' );
        rewrite ( output );
        
        readln ( part );
        for p := 1 to part do
                begin
                writeln ( 'Case ' , p , ':' );
                init;
                main;
                if p < part then writeln;
                end;
end.
