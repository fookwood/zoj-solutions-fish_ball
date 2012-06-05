// Accept
// Time 2005/06/09
program p1769;

const
        c       = 1e-4;
        e       = 1e-5;
        Line    : array[0..2] of String =
                ('Scalene' , 'Isosceles' , 'Equilateral' );

        angle   : array[0..2] of String =
                ('Right' , 'Obtuse' , 'Acute' );

{$APPTYPE CONSOLE}

var
        ans                     : Boolean;
        equalLine , numberangle : Integer;
        t ,
        x1 , y1 , x2 , y2 , x3 , y3 ,
        d1 , d2 , d3 ,
        jiao1 , jiao2 , jiao3
                                : Extended;

function dis ( a , b , c , d : Extended ) : Extended;
begin
dis := sqrt ( sqr ( a - c ) + sqr ( b - d ) );
end;

function temp ( a , b , c , d , e , f : Extended ) : Extended;
begin
temp := ( ( c - a ) * ( e - a ) + ( d - b ) * ( f - b ) ) / sqrt ( sqr ( c - a ) + sqr ( d - b ) ) / sqrt ( sqr ( e - a ) + sqr ( f - b ) );
end;

function init : Boolean;
begin
read ( t );
if ( t = -1  ) and eoln then
        begin
        init := false;
        exit;
        end;
init := true;
x1 := t;

readln ( y1 , x2 , y2 , x3 , y3 );


d1 := dis ( x2 , y2 , x3 , y3 );
d2 := dis ( x1 , y1 , x3 , y3 );
d3 := dis ( x1 , y1 , x2 , y2 );

ans := ( abs ( d1 + d2 - d3 ) > c ) and ( abs ( d1 + d3 - d2 ) > c ) and ( abs ( d2 + d3 - d1 ) > c  );
if not ans then exit;

equalLine := 0;
if abs ( d1 - d2 ) <= 0.01 + c then inc ( equalLine );
if abs ( d1 - d3 ) <= 0.01 + c then inc ( equalLine );
if abs ( d2 - d3 ) <= 0.01 + c then inc ( equalLine );
if equalLine = 3 then dec ( equalLine );

jiao1 := Temp ( x1 , y1 , x2 , y2 , x3 , y3 );
jiao2 := Temp ( x2 , y2 , x3 , y3 , x1 , y1 );
jiao3 := Temp ( x3 , y3 , x2 , y2 , x1 , y1 );

numberangle := 0;

if jiao1 < cos ( 92 * pi / 180 ) + e then dec ( numberangle ) else
if jiao1 > cos ( 88 * pi / 180 ) - e then inc ( numberangle ) else
        begin
        numberangle := 0;
        exit;
        end;

if jiao2 <= cos ( 92 * pi / 180 ) + e then dec ( numberangle ) else
if jiao2 >= cos ( 88 * pi / 180 ) + e then inc ( numberangle ) else
        begin
        numberangle := 0;
        exit;
        end;

if jiao3 <= cos ( 92 * pi / 180 ) + e then dec ( numberangle ) else
if jiao3 >= cos ( 88 * pi / 180 ) - e then inc ( numberangle ) else
        begin
        numberangle := 0;
        exit;
        end;

if numberangle = 3 then dec ( numberangle );
end;

begin
assign ( input ,'p.in' );
reset ( input );
assign ( output , 'p.out' );
rewrite ( output );

while init do
        if ans then writeln ( Line [equalLine] , ' ' , angle [numberangle] )
                else writeln ( 'Not a Triangle' );
writeln ( 'End of Output' ); 
end.
