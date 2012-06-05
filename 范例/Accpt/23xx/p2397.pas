PROGRAM p2397;

const
        maxn    = 2000;

type
        Topt    = array[0..maxn] of Word;

var
        n , i , sT , sQ , fT , fQ            : Word;
        win                                  : Longint;
        TJ , QW                              : Topt;

procedure sort ( var a : Topt ; left , right : Word );
var
        i , j , key , temp      : Word;
begin
i := left - 1;
j := right + 1;
key := a [left];
repeat
        repeat dec (j) until a [j] <= key;
        repeat inc (i) until a [i] >= key;
        if ( i < j ) then begin temp := a [i] ; a [i] := a [j] ; a [j] := temp end
                else break;
until false;
if left < j then sort ( a , left , j );
if j + 1 < right then sort ( a , j + 1 , right );
end;

begin
assign ( input ,'p.in' );
reset ( input );

while true do
begin
read ( n );
if n <= 0 then break;

win := 0;
sT := 1; sQ := 1;
fT := n; fQ := n;
for i := 1 to n do read ( TJ [i] );
for i := 1 to n do read ( QW [i] );
sort ( TJ , 1 , n );
sort ( QW , 1 , n );

for i := 1 to n do
        if TJ [sT] < QW [sQ] then begin inc ( sT ) ; dec ( fQ ) ; dec ( win ) ; end else
        if TJ [sT] > QW [sQ] then begin inc ( sT ) ; inc ( sQ ) ; inc ( win ) ; end else
        if TJ [fT] > QW [fQ] then begin dec ( fT ) ; dec ( fQ ) ; inc ( win ) ; end else
        if TJ [fT] < QW [fQ] then begin inc ( sT ) ; dec ( fQ ) ; dec ( win ) ; end else
        begin if TJ [sT] < QW [fQ] then dec ( win ); inc ( sT ) ; dec ( fQ )  ; end;
writeln ( 200 * win );
end;
end.
