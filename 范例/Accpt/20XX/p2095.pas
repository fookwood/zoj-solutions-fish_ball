{$R+,Q+,I+}

PROGRAM p2095;

CONST
        maxn    =       500000;

TYPE
        Tnum    = array[0..maxn] of LongWord;

VAR
        num , maxone    : Tnum;
        part , p , m    : Longint;

{PROCEDURE Check ;
var
        i                       : Longint;
        p , m , temp            : Int64;
begin
fillchar ( num , sizeof ( num ) , 0 );
num [1] := 0;
for i := 2 to maxn do
        begin
        m := i;
        p := maxone [m];
        temp := p;
        while ( m mod p = 0 ) do
                begin
                temp := temp * p;
                m := m div p;
                end;
        num [i] := ( num [m] + m ) * trunc ( temp - 1 ) div ( p - 1 ) - i;
        end;
end;

FUNCTION Ans ( m : Longint ) : Int64;
var
        temp , p , s             : Int64;
begin
if ( num [m] > 0 ) then exit ( num [m] );
s := m;
p := maxone [m] ;
temp := p;
while ( m mod p = 0 ) do
        begin
        temp := temp * p;
        m := m div p;
        end;
num [s] := Ans ( m ) * trunc ( temp - 1 ) div ( p - 1 ) ;
Ans := num [s];
end; }

PROCEDURE makewhether;
var
        i ,j                    : Longint;
begin
fillchar ( num , sizeof ( num ) , 0 );
fillchar ( maxone , sizeof (maxone ) , 0 );
for I := 2 to maxn do
        if maxone [i] = 0 then
                begin
                num [i] := 1;
                if ( i <> 2 ) and ( i * 2 <= maxn ) then num [i * 2] := i + 3;
                if ( i <> 3 ) and ( 3 * i <= maxn ) then num [3 * i] := i + 4;
                for j:= 1 to maxn div i do
                        if maxone [i * j ] = 0 then  maxone [i * j] := i;
                end;
end;

PROCEDURE MakeNum;
var
        i , j                   : Longint;
        temp , last , sum       : Longint;
begin
for i := 2 to maxn do
        if num [i] = 0 then
        begin
        temp := maxone [i];
        last := 1;
        sum  := 1;
        while ( i mod temp = 0 ) do
                begin
                last := temp;
                sum  := sum + temp;
                temp := temp * maxone [i];
                end;
        last := i div last;

        temp := {( temp - 1 ) div ( maxone [i] - 1 )} sum * ( num [last] + last ) - i;
        num [i] := temp ;
        end;
end;

BEGIN
Makewhether;
MakeNum;

readln ( part ) ;
for p:= 1 to part do
        begin
        readln ( m );
        writeln ( num [m] );
        end;
END.