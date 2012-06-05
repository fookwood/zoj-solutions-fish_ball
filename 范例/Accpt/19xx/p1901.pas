{$R-,I-,Q-}
PROGRAM p1901;

CONST
        maxn    = 100;

        change  : array[1..8,1..2] of Longint =
        ((1,0),(1,1),(1,-1),(0,1),(0,-1),(-1,0),(-1,-1),(-1,1));

TYPE
        TData   = array[1..maxn] of Double;

VAR
        n                       : Longint;
        Datax , Datay           : TData;
        minx , miny , maxx , maxy
                                : Double;
        ans                     : Real;

PROCEDURE Init;
var
        i                       : Longint;
begin
readln ( n );
minx := 1e10;
miny := 1e10;
maxx := - 1e10;
maxy := - 1e10;

for i := 1 to n do
        begin
        readln ( Datax [i]  , Datay [i] );
        if Datax [i] > maxx then maxx := Datax [i];
        if Datax [i] < minx then minx := Datax [i];
        if Datay [i] > maxy then maxy := Datay [i];
        if Datay [i] < miny then miny := Datay [i];
        end;
end;

FUNCTION Dis ( x , y :Double ): Real;
var
        i                               : Integer;
        temp                            : Real;
begin
temp := 0;
for i := 1 to n do
        temp := temp + sqrt ( sqr (Datax [i] - x) + sqr ( Datay [i] - y ) );
Dis := temp;
end;

PROCEDURE Make( x , y : Double);
var
        temp                            : Real;
        cx , cy , i                     : Longint;
begin
temp := Dis ( x , y );
if temp >= ans then exit;
ans := temp;
for i := 1 to 8 do Make ( x + change [i] [1] , y + change [i] [2] );
end;

BEGIN
Init;
ans := 1e10;
make ( ( minx + maxx ) / 2 , ( miny + maxy ) / 2 );
writeln ( ans : 0 : 0 );
END.
