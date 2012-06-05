// Accept
// Time 2005/06/07
program p1197;

{$APPTYPE CONSOLE}
        
const
        maxn    = 26;

type
        Tnode           = record
                        minx , miny , maxx , maxy       : Integer;
                        end;
        Tdata           = array[1..maxn ] of Tnode;

        
        Tgraph          = array[1..maxn , 1..maxn ]of Boolean;
        TLink           = array[1..maxn ] of Integer;
        Tcover          = array[1..maxn ] of Boolean;

var
        n , step        : Integer;              
        data            : Tdata;
        graph           : Tgraph;
        Link , sLink    : TLink;
        cover , wa      : Tcover;

procedure init;
var
        i , j , x , y   : Integer;
begin
fillchar ( graph , sizeof ( graph ) , 0 );

for i := 1 to n do
        with data [i] do
                read ( minx , maxx , miny , maxy );
for i := 1 to n do
        begin
        read ( x , y );
        for j := 1 to n do
                with data [j] do
                        if ( x > minx ) and ( x < maxx ) and ( y > miny ) and ( y < maxy ) then
                                graph [i] [j] := true;
        end;
end;

function find ( v : Integer ) : Boolean;
var
        i , t                   : Integer;
begin
find := true;
for i := 1 to n do
        if cover [i] and graph [v] [i] then
                begin
                cover [i] := false;
                t         := Link [i];
                Link [i]  := v;
                if ( t = 0 ) or find ( t ) then exit;
                Link [i]  := t;
                end;
find := false;
end;

procedure main ;
var
        i , l , j               : Integer;
        first                   : Boolean;
        
begin
fillchar ( Link , sizeof ( Link ) , 0 );
for i := 1 to n do
        begin
        fillchar ( cover , sizeof ( cover ) , 1);
        find ( i );
        end;

sLink := Link;
fillchar ( wa , sizeof ( wa ) , 1 );

for j := 1 to n do
        begin
        graph [sLink [j]] [j] := false;

        l := 0;
        fillchar ( Link ,sizeof ( Link ) , 0 );
        for i := 1 to n do
                begin
                fillchar ( cover , sizeof ( cover ) , 1 );
                if find ( i ) then inc ( l );
                end;
        if ( l <> n - 1 ) then
                wa [j] := false;

        graph [sLink [j]] [j] := true;
        end;


first := true;

for i := 1 to n do
        if wa [i] then 
                begin
                if not first then write ( ' ' ) else first := false;
                write ( '(' , chr ( i + ord ( 'A' ) - 1 ) , ',' , sLink [i] ,')' );
                end;
if first then write ( 'none' );
writeln;
end;

begin
step := 0;

read ( n );
while ( n <> 0 ) do
        begin
        inc ( step );
        writeln ( 'Heap ' , step );
        init;
        main;
        writeln;
        read ( n );
        end;
end.
