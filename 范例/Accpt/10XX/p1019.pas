program p1019;

const
        maxn            = 100;
        maxorder        = 1000;
        change  : array[0..3 , 0..1] of Longint =
                ((-1 , 0) , (0 , 1) , (1 , 0) , (0 , -1));

type
        Tmap    = array[1..maxn , 1..maxn] of Byte;
        Topt    = array[0..1] of Tmap;
        Torder  = array[0..maxorder , 1..3] of Longint;

var
        part , p , n , m , num  : Longint;
        map                     : Tmap;
        opt                     : Topt;
        order                   : Torder;

procedure init;
var     i , j                   : Longint;
        ch                      : Char;
begin
readln ( n , m );
for i := 1 to n do
        begin
        for j := 1 to m do read ( map [i] [j] );
        readln;
        end;

num := 0;
read ( i , j );
while ( i > 0 ) and ( j > 0 ) do
        begin
        readln ( ch , ch );
        inc ( num ); order [num] [1] := i; order [num] [2] := j;
        case ch of
                'U'             : order [num] [3] := 2;
                'L'             : order [num] [3] := 1;
                'R'             : order [num] [3] := 3;
                'D'             : order [num] [3] := 0;
        end;
        read ( i , j );
        end;
readln;
end;

procedure work;
var     a , b , i , j , k       : Longint;
        dx , dy                 : Longint;
        Sum                     : Longint;
        ch                      : Char;
begin
a := 0; b := 1;
for i := 1 to n do for j := 1 to m do opt [a] [i] [j] := 1 - map [i] [j];

while num > 0 do
        begin
        for i := 1 to n do for j := 1 to m do opt [b] [i] [j] := 0;

        for i := 1 to n do
                for j := 1 to m do
                        if ( opt [a] [i] [j] = 1 ) then
                                begin
                                k := 0; dx := i; dy := j;

                                while ( k < order [num] [2] ) do
                                        begin
                                        inc ( k );
                                        inc ( dx , change [order [num] [3]] [0] );
                                        inc ( dy , change [order [num] [3]] [1] );

                                        if ( dx < 1 ) or ( dx > n ) or ( dy < 1 ) or ( dy > m ) or ( map [dx] [dy] = 1 ) then break
                                                else
                                        if ( k >= order [num] [1] ) then opt [b] [dx] [dy] := 1;
                                        end;
                                end;

        a := 1 - a;
        b := 1 - b;
        dec ( num );
        end;

Sum := 0; for i := 1 to n do for j := 1 to m do if opt [a] [i] [j] = 1 then inc ( Sum );
//inc ( Sum , opt [a] [i] [j] );
writeln ( Sum );
end;

begin
{assign ( input , 'p.in' );
reset ( input );
assign ( output , 'p.out' );
rewrite ( output );}


readln ( part );
for p := 1 to part do
        begin
        init;
        work;
        end;

close ( output );
end.
