{$R+,I+,Q+,S+}
PROGRAM p1852;

VAR
        a , b , s , m , n               : Extended;


BEGIN
//assign ( input , 'p.in' );
//reset ( input );
readln ( a , b , s , m , n );
while ( s <> 0 ) do
        begin

        writeln ( 180 / pi * arctan ( n * b / m / a ) :0:2 , ' ' ,
        sqrt ( sqr ( m * a ) + sqr ( n * b ) ) / s : 0 : 2);

        readln ( a , b , s , m , n );
        end;
END.