program p1607;

{$APPTYPE CONSOLE}

const
        maxn    = 100;

type
        Tmaxget = array[0..maxn , 0..maxn , 0..maxn] of Longint;

var
        n , m           : Longint;
        MaxGet          : Tmaxget;

function f ( a , b , l : Longint ) : Longint;
var     max , i , t : Longint;
begin
if MaxGet [a] [b] [l] = - 1 then
        begin
        if l = 0 then if a <> 0 then MaxGet [a] [b] [0] := f ( 0 , 0 , a )
                                else MaxGet [a] [b] [0] := 0 
                else begin
                max := 0;
                for i := 1 to m do
                        if ( i <= l ) then
                                begin
                                t := a + b + l - f ( b , a + i , l - i );
                                if t > max then max := t;
                                end; 
                MaxGet [a] [b] [l] := max;
                end; 
        end;
f := MaxGet [a] [b] [l];
end;

begin
assign ( input , 'p.in' ); reset ( input );
assign ( output , 'p.out' ); rewrite ( output );

{for n := 1 to 100 do
        begin
        for m := 1 to n do
                begin
                fillchar ( MaxGet , sizeof ( MaxGet ) , $FF );
                write ( f ( 0 , 0 , n  ) : 3 );
                end;
        writeln;
        end;
exit;}


while not seekeof do
        begin
        readln ( n , m );
        if m >= ( n + 1 ) div 2 then begin writeln ( m ); continue; end;
        fillchar ( MaxGet , sizeof ( MaxGet ) , $FF );
        writeln ( f ( 0 , 0 , n ));
        end;
end.
