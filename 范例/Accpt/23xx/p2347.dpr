{$R-,I-,Q-}
program p2347;

{$APPTYPE CONSOLE}

const
        maxn = 1000;
        maxp = 1997;
        particle = 1e-6;

type
        Tnext = array[1..maxn]of Longint;
                // memory

        Tpoint = record
                x , y           : Longint;
        end;
        Tdata = array[1..maxn] of TPoint;
                // the coors

        Thash = array[0..maxp]of Longint;
                // hash list

var
        n , part , p            : Longint;
                // number of points 
        next                    : Tnext;
        hash                    : Thash;
        data                    : Tdata;

PROCEDURE Init;
var
        i , pos                       : Longint;
begin
fillchar( hash , sizeof (hash) , 0);
                // make zero for hash

for i:=1 to n do
        with data [i] do 
                begin
                readln ( x , y );
                pos := ( sqr ( x mod maxp) + sqr ( y mod maxp ) ) mod maxp;
                next [i] := hash [pos] ;
                hash [pos] := i;
                end;
end;

FUNCTION Find ( var x , y : Longint ) : Boolean;
var
        p , w                   : Longint;
begin
w := ( sqr ( x mod maxp ) + sqr ( y mod maxp ) ) mod maxp;
p := hash [ w ];
while ( p <> 0 ) do
        begin
        if ( data [p] . x = x ) and ( data [p] . y = y ) then
                begin
                Find := true;
                exit;
                end;
        p := next [p];
        end;
Find := false;
end;

PROCEDURE Main;
var
        ans , i , j                     : Longint;
        x , y                           : Longint;
        temp                            : Real;
begin
{writeln ( 'n = ', n );

for i:= 1to n do
        writeln ( data [i] . x , ' ' , data [i] . y );}

ans := 0;
for i := 1 to n do
        for j:=i + 1 to n do
                begin
                temp := ( data [i] . x + data [j] . x - data [i] . y + data [j] . y ) / 2;
                if abs ( frac ( temp ) ) > particle then continue;
                x := round ( temp );
                temp := ( data [i] . x - data [j] . x + data [i] . y + data [j] . y ) / 2;
                if abs ( frac ( temp ) ) > particle then continue;
                y := round ( temp );
                if not find ( x , y ) then continue;
                                        // the right vertix

                temp := ( data [i] . x + data [j] . x + data [i] . y - data [j] . y ) / 2;
                if abs ( frac ( temp ) ) > particle then continue;
                x := round ( temp );
                temp := ( - data [i] . x + data [j] . x + data [i] . y + data [j] . y ) / 2;                 
                if abs ( frac ( temp ) ) > particle then continue;
                y := round ( temp );
                                        // the left vertix
                                        
                if not find ( x , y ) then continue;
                inc ( ans ); 
                end;

writeln ( ans div 2 );
end;

begin
//assign( input , 'p.in');
//reset (input );
//assign(output,'p.out');
//rewrite(output);
readln ( part );
for p:=1 to part do
        begin
        readln ( n );
        while ( n > 0 ) do
                begin
                Init;
                Main;
                readln ( n );
                end;
        if p < part then writeln;
        end;
//close(output);
end.
