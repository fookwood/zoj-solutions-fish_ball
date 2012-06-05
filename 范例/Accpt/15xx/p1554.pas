PROGRAM p1554;

TYPE
        Tf      = array[1..100,1..100,0..2] of Longint;

VAR
        s                       : String;
        f                       : Tf;

FUNCTION Check ( a , l , k : Integer ) : Boolean;
var
        i , j                   : Integer;
begin
for i := 1 to l div k - 1 do
        for j := 0 to k - 1 do
                if s [a + ( i - 1 ) * k + j ] <> s [a + i * k + j] then
                        exit ( false );
exit ( true );
end;

FUNCTION long ( p : Integer ) : Integer;
begin
exit ( trunc ( ln ( p ) / ln ( 10 ) ) + 1 );
end;

PROCEDURE Print ( p , l : Integer ) ;
var
        i                       : Integer;
begin
if f [p] [l] [0] = 0 then
        begin
        write ( l div f [p] [l] [1] );
        write ( '(' );
        print ( p , f [p] [l] [1] );
        write ( ')' );
        end else
        begin
        if f [p] [l] [2] = l then
                begin
                for  i := p to p + l - 1 do write ( s[i] );
                end else
                begin
                print ( p             , f [p] [l] [1] - p );
                print ( f [p] [l] [1] , p + l - f [p] [l] [1] );
                end;
        end;
end;

PROCEDURE Dp;
var
        len , i , j , k         : Integer;
        n                       : Integer;
begin
//writeln ( 's  = ' , s);
len := length ( s );
//writeln ( 'len = ' , len );

for i := 1 to len do
        for j := 1 to len - i + 1 do
                begin
                f [i] [j] [0] := 1;
                f [i] [j] [1] := i;
                f [i] [j] [2] := j;
                end;


for j := 1 to len do
        for i := 1 to len - j + 1 do
                begin
                for k := 1 to j - 1 do
                        if ( j mod k = 0 ) and check ( i , j , k ) then
                                begin
                                n := long ( j div k );

                                if n + 2 + f [i] [k] [2] < f [i] [j] [2] then
                                        begin
                                        f [i] [j] [2] := n + 2 + f[i] [k] [2];
                                        f [i] [j] [0] := 0;
                                        f [i] [j] [1] := k;
                                        end;
                                end;

                for k := i + 1 to i + j - 1 do
                        if ( f [i] [k - i] [2] + f [k] [j - k + i] [2] < f [i] [j] [2] ) then
                                begin
                                f [i] [j] [2] := f [i] [k - i] [2] + f [k] [j - k + i] [2];
                                f [i] [j] [0] := 1;
                                f [i] [j] [1] := k;
                                end;
                end;

//writeln ( f [1] [len] [2] );
print ( 1 , len );
writeln;
end;


BEGIN
//assign ( input ,'p.in' );
//reset ( input );
while not eof do
        begin
        readln ( s );
        Dp;
        end;
END.
