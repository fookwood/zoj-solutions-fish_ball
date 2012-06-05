program p1143;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
        maxn    = 20;

var
        step    : Longint;
        max     : Longint;
        maxOne  : Longint;
        n       : Longint;
        m , p   : array [1..maxn] of Longint;

procedure init;
var     i       : Longint;
        a , b , y       : Longint;
begin
        max := 0;
        MaxOne := 1;
        for i := 1 to n do
                begin
                readln ( y , a , b );
                if y > max then max := y;
                p [i] := b - a;
                m [i] := y mod p [i];
                if P [i] > P [MaxOne] then MaxOne := i;
                end;
end;

function Gcd ( a , b : Longint ): Longint;
begin
        if a = 0 then gcd := b
                else gcd := gcd ( b mod a , a );
end;

procedure Work;
var     i       : Longint;
        j       : Longint;
        Flag    : Boolean;
        Mp      : Longint;
        D       : Longint;
begin
        writeln ( 'Case #' , step , ':' );
        Mp := 1;
        for i := 1 to n do
                begin
                if Mp > p [i] then D := gcd ( p [i] , Mp )
                        else D := gcd ( Mp , p [i] );
                Mp := Mp div D * p [i];
                end;

        i := m [MaxOne];
        while ( i < Mp ) and ( i < 10000 ) do 
                begin
                Flag := true;
                for j := 1 to n do
                        if i mod P [j] <> m [j] then
                                begin
                                Flag := false;
                                break;
                                end;
                if not Flag then
                        begin
                        inc ( i , P [MaxOne] );
                        continue;
                        end;

                j := i;
                while ( j < Max ) do inc ( j , Mp );

                if j < 10000 then writeln ( 'The actual year is ' , j , '.' )
                        else writeln ( 'Unknown bugs detected.' );
                exit;
                end;
        writeln ( 'Unknown bugs detected.' );
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        assign ( input , 'p.in' );
        reset ( input );
        assign ( output , 'p.out' );
        rewrite ( output );
        
        step := 0;
        while true do
                begin
                readln ( n );
                if n = 0 then break;
                inc ( step );
                init;
                Work;
                writeln;
                end;
end.
