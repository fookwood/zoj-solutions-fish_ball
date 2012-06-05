  {$I-,Q-,R-,S-}
PROGRAM p1516;

CONST
        maxn    = 100;

TYPE
        Tnum    = array[0..maxn , 0..maxn ]of Integer;
        Tgraph  = array[1..maxn , 1..maxn ]of Boolean;
        TLink   = array[1..maxn ] of Integer;
        Tcover  = array[1..maxn ] of Boolean;

VAR
        n , m , t               : Integer;
        num                     : Tnum;
        graph                   : Tgraph;
        Link                    : TLink;
        cover                   : Tcover;

PROCEDURE Init;
var
        i , a , b               : Integer;
begin
fillchar ( num , sizeof ( num ), 0 );
fillchar ( graph , sizeof ( graph ) , 0 );

readln ( t );
for i:= 1 to t do
        begin
        readln ( a , b );
        num [a] [b] := - 1;
        end;
t := 0;
for a:= 1 to n do
        for b:= 1 to m do
                if num [a] [b] = 0 then
                        begin
                        inc ( t );
                        num [a] [b] := t;
                        if ( num [a - 1] [b] > 0 ) then
                                begin
                                graph [num [a - 1] [b]] [t] := true;
                                graph [t] [num [a - 1] [b]] := true;
                                end;
                        if ( num [a] [b - 1] > 0 ) then
                                begin
                                graph [num [a] [b - 1]] [t] := true;
                                graph [t] [num [a] [b - 1]] := true;
                                end;
                        end;
end;

FUNCTION find ( v : Integer ) : Boolean;
var
        i , p                           : Integer;
begin
for i:= 1 to t do
        if cover [i] and graph [v] [i] then
                begin
                p        := Link [i];
                Link [i] := v;
                cover [i]:= false;
                if ( p = 0 ) or Find ( p ) then exit ( true );
                end;
exit ( false );
end;

PROCEDURE Main;
var
        ans , i                         : Integer;
begin
fillchar ( Link , sizeof ( Link ) , 0 );
ans := 0;
for i:= 1 to t do
        begin
        fillchar ( cover , sizeof ( cover ) , 1 );
        if Find ( i ) then inc ( ans );
        end;
writeln ( ans div 2);
end;

BEGIN
readln ( n , m );
while ( n <> 0 ) do
        begin
        Init;
        main;
        readln ( n , m );
        end;
END.
