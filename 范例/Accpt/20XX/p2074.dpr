program p2074;

{$APPTYPE CONSOLE}

var
        n , i , x1 , y1 , x2 , y2 , x3 , y3 , x4 , y4 , x , y
                                                        : Longint;
        d1 , d2 , temp                                  : Extended;

function dis ( a , b , c , d : Longint ) : Extended;
begin
dis := sqrt ( sqr ( a - c ) + sqr ( b - d ) );
end;

begin
{assign ( input ,'p.in' );
reset ( input );
assign ( output , 'p.out' );
rewrite ( output );}
while not eof do
        begin
        readln ( n );
        readln ( x , y );
        x1 := x; y1 := y;
        x2 := x; y2 := y;
        x3 := x; y3 := y;
        x4 := x; y4 := y;
        d1 := 0; d2 := 0;
        for i := 2 to n do
                begin
                readln ( x , y );
                temp := dis ( x , y , x3 , y3 );
                if ( x <= x3 ) and ( y >= y3 ) and ( temp > d1 ) then
                        begin
                        d1 := temp;
                        x4 := x; y4 := y;
                        end;
                temp := dis ( x , y , x4 , y4 );
                if ( x >= x4 ) and ( y <= y4 ) and ( temp > d1 ) then
                        begin
                        d1 := temp;
                        x3 := x; y3 := y;
                        end;
                temp := dis ( x , y , x2 , y2 );
                if ( x <= x2 ) and ( y <= y2 ) and ( temp > d2 ) then
                        begin
                        d2 := temp;
                        x1 := x; y1 := y;
                        end;
                temp := dis ( x , y , x1 , y1 );
                if ( x >= x1 ) and ( y >= y1 ) and ( temp > d2 ) then
                        begin
                        d2 := temp;
                        x2 := x; y2 := y;
                        end;
                end;
        if d1 > d2 then writeln ( round ( d1 * 100 ) / 100 : 0 : 2 )
                else writeln ( round ( d2 * 100 ) / 100 : 0 : 2 );
        end;
end.
