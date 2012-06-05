PROGRAM p2475;

CONST
        maxn = 100;

TYPE
        TNode           = record
                        SOrder , MinOrder : Longint;
                        end;

        TNumber         =       array[0..maxn]of TNode;

        Tcover          =       array[0..maxn]of Boolean;

        TLine           =       array[0..maxn,0..maxn]of Longint;

VAR
        n , x , j , T           : Longint;
        Line                    : TLine;
        cover , act             : Tcover;
        Number                  : TNumber;

PROCEDURE Init;
var
        i , a , b               : Longint;
begin
for i := 1 to maxn do
        Line [i] [0] := 0;

for i := 1 to n do
        begin
        readln ( a , b );
        if b = 0 then continue;
        inc ( Line [a] [0] );
        Line [a] [Line [a] [0]] := b;
        end;

readln ( x );

T := 0;
fillchar ( cover , sizeof (cover) , false );
fillchar ( act , sizeof ( act ) , false );
fillchar ( Number , sizeof ( Number ) , 0 );
end;

PROCEDURE Search ( v : Longint ) ;
var
        i , j , min                     : Longint;
begin
cover [v] := true;
act [v] := true;
min := Number [v] . SOrder;

for i:=1 to Line [v] [0] do
        begin
        j := Line [v] [i];

        if not cover [j] then
                begin
                inc ( T );
                Number [j] . SOrder := T;
                Number [j] . MinOrder := T;
                Search ( j );
                end;

        if act [j] and ( Number [j] . MinOrder < min ) then min := Number [j] . MinOrder;
        end;

Number [v] . MinOrder := min;
act [v] := false;
end;

FUNCTION Check : Boolean;
var
        i                               : Longint;
begin
for i:=1 to maxn do
        if ( i <> x ) and ( Number [i] . MinOrder = 1 ) then exit ( true );
for i:=1 to maxn do
        if ( Number [i] . MinOrder < Number [i] . SOrder ) then exit ( true );
exit ( false );
end;

BEGIN
readln ( n ) ;
while ( n > 0 ) do
        begin
        Init;

        inc ( T );
        Number [x] . SOrder := T;
        Number [x] . MinOrder := T;
        Search ( x );

        if Check then writeln('No') else writeln ('Yes');
        readln ( n ) ;
        end;
END.