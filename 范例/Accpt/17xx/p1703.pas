{$R+,I+,Q+,S-}
{$M 16384,0,655360}

PROGRAM p1703;

TYPE
        Tmap    = array[0..3,0..3] of Integer;
        Tscore  = array[0..9] of Integer;

        TInfor   = record
                map             : Tmap;
                step            : Integer;
                score           : Tscore;
                end;

VAR
        Infor                   : TInfor;
        win , best              : Integer;
        T                       : Longint;

PROCEDURE Print ;
var
        i ,j                    : Integer;
begin
for i := 0 to 3 do
        begin
        for j := 0 to 3 do
                write ( infor . map [i] [j]: 4 );
                writeln;
        end;
end;

PROCEDURE Add ( x , y , s : Integer ) ;
begin
with Infor do
        begin
        inc ( map [x] [y] , s );
        inc ( score [x]     , s );
        inc ( score [4 + y] , s );
        if ( x = y ) then inc ( score [8] , s );
        if ( x + y = 3 ) then inc ( score [9] , s );
        end;
end;

FUNCTION Init : Boolean;
var
        ch                      : Char;
        i , j                   : Integer;
begin
readln ( ch );
if ch = '$' then exit ( false );
Init := true;

fillchar ( Infor , sizeof ( Infor ) , 0 );

with Infor do
        for i := 0 to 3 do
                begin
                for j  := 0 to 3 do
                        begin
                        read ( ch );
                        if ch = 'x' then
                                begin
                                Add ( i , j , 1 );
                                inc ( step );
                                end;
                        if ch = 'o' then
                                begin
                                Add ( i , j , -1 );
                                inc ( step );
                                end;
                        end;
                readln;
                end;
end;

FUNCTION Many ( s : Integer ; var best : Integer ) : Integer;
var
        i , j , p               : Integer;
begin
j := 0;
best := maxint;
for i:= 0 to 9 do
        if Infor . score [i] = s then
                begin
                inc ( j );
                if I < 4 then
                        begin
                        for p := 0 to 3 do
                                if ( Infor . map [i] [p] = 0 ) and ( 3 * i + p < best ) then
                                        best := 4 * i + p ;
                        continue;
                        end;

                if I < 8 then
                        begin
                        for p := 0 to 3 do
                                if ( Infor . map [p] [i - 4] = 0 ) and ( 3 * p + i - 4 < best ) then
                                        best := 4 * p + i - 4;
                        continue;
                        end;

                if I = 8 then
                        begin
                        for p := 0 to 3 do
                                if ( Infor . map [p] [p] = 0 ) and ( 4 * p < best ) then
                                        best := 5 * p;
                        continue;
                        end;

                if I = 9 then
                        for p := 0 to 3 do
                                if ( Infor . map [p] [3 - p] = 0 ) and ( 2 * p + 3 < best ) then
                                        best := 3 * p + 3;
                end;
Many := j;
end;

PROCEDURE swap ( var a , b : Integer);
var
        temp                            : Integer;
begin
temp := a;
a    := b;
b    := temp;
end;

// debug for determine
FUNCTION Determine ( state : Integer ; var best : Integer) : Integer;


var
        i , j , k , temp                : Integer;
        wewin , hewin                   : Integer;
        webest , hebest                 : Integer;
        draw                            : Boolean;
        search                          : array[0..12] of Integer;

procedure push ;
var
        i , j                           : Integer;
begin
Search [0] := 0;
with Infor do
for i := 0 to 3 do for j := 0 to 3 do
        if map [i] [j] = 0 then
                begin
                inc ( Search [0] );
                Search [Search [0]] := i * 4 + j;
                end;
end;

begin
inc ( T );
with Infor do
begin
if step = 17 then exit ( 0 ); // edge

Search [0] := 0;
wewin := many ( state * 3 , webest );
hewin := many ( - state * 3 , hebest );

if ( hewin = 2 ) and ( wewin = 0 ) then begin Search [0] := 1; Search [1] := hebest; exit ( - 1 ); end;

if ( hewin = 2 ) and ( wewin = 1 ) then begin best := webest; exit ( 1 ); end;

if ( hewin = 2 ) and ( wewin = 2 ) then begin best := webest; exit ( 1 ); end;

if ( hewin = 1 ) and ( wewin = 0 ) then begin Search [0] := 1; Search [1] := hebest; end;

if ( hewin = 1 ) and ( wewin = 1 ) then
        begin
        Search [0] := 2;
        Search [1] := hebest;
        Search [2] := webest;
        if Search [1] > Search [2] then swap ( Search [1] , Search [2] );
        end;

if ( hewin = 1 ) and ( wewin = 2 ) then push;

if ( hewin = 0 ) and ( wewin = 0 ) then push;

if ( hewin = 0 ) and ( wewin = 1 ) then push;

if ( hewin = 0 ) and ( wewin = 2 ) then push;

draw := false;

for k := 1 to Search [0] do
        begin
        i := Search [k] div 4;
        j := Search [k] mod 4;

        inc ( step );
        Add ( i , j , state );

        temp := many ( state * 4 , best );

        if temp > 0 then begin dec ( step ) ; Add ( i , j , - state ) ; best := Search [k]; exit ( 1 ); end;

        temp := Determine ( - state , best );

        if temp < 0 then begin dec ( step ) ; Add ( i , j , - state ) ; best := Search [k]; exit ( 1 ); end;

        dec ( step );
        Add ( i , j , - state );

        if temp = 0 then draw := true;
        end;

if draw then exit ( 0 ) else exit ( -1 );
end;
end;

PROCEDURE Main;
begin
win  := 0;
T    := 0;
win := Determine (1 , best );
//writeln ( T , ' points has been searched before the answer worked out !');

if win = 1 then
        begin
        writeln ( '(' , best div 4 , ',' ,best mod 4 , ')' );
        exit;
        end;
writeln ( '#####' );
end;

BEGIN
while Init do main;
END.