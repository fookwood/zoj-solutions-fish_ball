// Accept
// Time 2005/06/21
program p2500;

{$APPTYPE CONSOLE}

const
        maxn    = 100;

type
        Theavy  = array[1..maxn , 1..maxn] of Boolean;

var
        part , p , n , m        : Longint;
        heavy                   : Theavy;

procedure init;
var     i , a , b               : Longint;
begin fillchar ( heavy , sizeof ( heavy ) , 0 );
readln ( n , m );
for i := 1 to m do begin readln ( a , b ); heavy [a] [b] := true; end;
end;

procedure floyd;
var     i , j , k , Sum         : Longint;
begin
for k := 1 to n do
        for i := 1 to n do
                for j := 1 to n do
                        heavy [i] [j] := heavy [i] [j] or ( heavy [i] [k] and heavy [k] [j] );

Sum := 0;
for i := 1 to n do
        begin
        k := 0;
        for j := 1 to n do if ( i <> j ) and ( heavy [i] [j] ) then inc ( k );
        if k > n shr 1 then begin inc ( Sum ); continue; end;
        k := 0;
        for j := 1 to n do if ( i <> j ) and ( heavy [j] [i] ) then inc ( k );
        if k > n shr 1 then begin inc ( Sum ); continue; end;
        end;
writeln ( Sum );
end;

begin
{assign ( input, 'p.in' );
reset ( input );
assign ( output , 'p.out' );
rewrite ( output );}

readln ( part );
for p := 1 to part do
        begin
        init;
        Floyd;
        end;
end.
