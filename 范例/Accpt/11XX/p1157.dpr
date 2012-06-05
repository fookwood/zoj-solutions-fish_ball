program p1157;

{$APPTYPE CONSOLE}

{%File 'p.in'}

const
        maxn    = 400;

type
        Tgraph  = array[1..maxn , 1..maxn] of Boolean;
        Tlink   = array[1..maxn] of Longint;
        Tcover  = array[1..maxn] of Boolean;
        Tname   = array[1..maxn] of String;

var
        part    : Longint;
        n , m   : Longint;
        r       : Longint;
        name    : Tname;
        left    : Tlink;
        right   : Tlink;
        
        cover   : Tcover;
        graph   : Tgraph;
        link    : Tlink;

        Pgraph  : Tgraph;

function find ( s : String ) : Longint;
var     i       : Longint;
begin
for i := 1 to r do if name [i] = s then begin find := i; exit; end;
inc ( r ); name [r] := s; find := r;
end;

procedure init;
var     i       : Longint;
        s       : String;
        a , b   : Longint;
begin
r := 0;
readln ( n );
for i := 1 to n do begin readln ( s ); left [i] := find ( s ); end;

readln ( m );
for i := 1 to m do
        begin
        readln ( s );
        Delete ( s , 1 , pos ( ' ' , s ));
        right [i] := find ( s );
        end;

fillchar ( Pgraph , sizeof ( Pgraph ) , 0 );
for i := 1 to r do Pgraph [i] [i] := true;

readln ( i );
while ( i > 0 ) do
        begin
        readln ( s );
                a := find ( copy ( s , 1 , pos ( ' ' , s ) - 1) );
                delete ( s , 1 , pos ( ' ' , s ));
                b := find ( s );
        Pgraph [b] [a] := true;
        dec ( i );
        end;
end;

procedure Floyd;
var     i , j , k       : Longint;
begin
for k := 1 to r do
        for i := 1 to r do for j := 1 to r do
                Pgraph [i] [j] := Pgraph [i] [j] or ( Pgraph [i] [k] and Pgraph [k] [j] );
end;

function find_d ( v : Longint ): Boolean;
var     i , t      : Longint;
begin
find_d := true;
for i := 1 to r do
        if cover [i] and graph [v] [i] then
                begin
                t := link [i];
                link [i] := v;
                cover [i] := false;
                if ( t = 0 ) or find_d ( t ) then exit;
                link [i] := t;
                end;
find_d := false;
end;

procedure main;
var     i , j      : Longint;
        ans     : Longint;
begin
fillchar ( graph , sizeof ( graph ) , 0 );
for i := 1 to n do for j := 1 to m do graph [i] [j] := Pgraph [left [i]] [right [j]];


fillchar ( Link , sizeof ( link ) , 0 );
ans := m;
for i := 1 to n do
        begin
        fillchar ( Cover , sizeof ( Cover ) , 1 );
        if find_d ( i ) then dec ( ans );
        end;
writeln ( ans );

exit;
// Debug :
writeln ( r );
for i := 1 to r do writeln ( name [i] ,'$' );
for i := 1 to n do
        begin
        for j := 1 to m do write ( graph [i] [j] : 6 );
        writeln;
        end;

end;

begin
assign ( input ,'p.in' ); reset ( input );
assign ( output ,'p.out' ); rewrite ( output );

readln ( part );
while ( part > 0 ) do
        begin
        init;
        Floyd;
        main;
        dec ( part );
        if part > 0 then writeln;
        end;
end.
