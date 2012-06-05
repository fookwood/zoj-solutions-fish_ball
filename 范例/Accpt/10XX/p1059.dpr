// Accept
// Time 2005/06/08
program p1059;

{$APPTYPE CONSOLE}

const
        maxn    = 20;

type
        Tgraph  = array[1..maxn , 1..maxn ] of Boolean;
        TLink   = array[1..maxn ] of Integer;
        Tcover  = array[1..maxn ] of Boolean;
        TID     = Set of 1..maxn ;
        Tname   = array[1..maxn ] of String [20];
        TIDname = array[1..maxn ] of String;

var
        part , p , n , total    : Integer;
        ID                      : TID;
        graph                   : Tgraph;
        Link , sLink            : TLink;
        cover                   : Tcover;
        name                    : Tname;
        IDname , ans            : TIDname;

function number ( s : String ) : Integer;
var
        i                       : Integer;
begin
for i := 1 to total do
        if IDname [i] = s then
                begin
                number := i;
                exit;
                end;
inc ( total );
IDname [total] := s;
number := total;
end;

function which ( s : String ) : Integer;
var
        i                       : Integer;
begin
for i := 1 to n do
        if name [i] = s then
                begin
                which := i;
                exit;
                end;
which := -1;
end;


procedure init;
var
        i , p                   : Integer;
        ch                      : Char;
        s                       : String;


        j : Integer;


begin
ch := ' ';
readln ( n );
for i :=1 to n do
        begin
        name [i] := '';
        read ( ch );
        while ( ch <> ' ' ) and not eoln do
                begin
                name [i] := name [i] + ch;
                read ( ch );
                end;
        end;
name [n] := name [n] + ch;
readln ;

fillchar ( graph , sizeof ( graph ) , 1 );

ID       := [];

total := 0;
readln ( s );
while s <> 'Q' do
        begin
        ch := s [1];
        Delete ( s , 1 , 1 ); while s [1] = ' ' do Delete ( s , 1 ,1 );

        case ch of
        'E'             : Begin
                        p := number ( s );
                        ID := ID + [p];
                        end;
        'L'             : begin
                        p := number ( s );
                        ID := ID - [p];
                        end;
        'M'             : begin
                        p := which ( s );
                        for i := 1 to n do
                                if not ( i in ID ) then
                                        graph [p] [i] := false;
                        end;
        end;

        readln ( s );
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
                cover [i]       := false;
                t               := Link [i];
                Link [i]        := v;
                if ( t = 0 ) or find ( t ) then exit;
                Link [i]        := t;
                end;
find := false;
end;

procedure main;
var
        i , j , sl , l          : Integer;
        temp                    : String;

begin
fillchar ( Link , sizeof ( Link ) , 0 );
l := 0;
for i := 1 to n do
        begin
        fillchar ( cover , sizeof ( cover ) , 1 );
        if find ( i ) then inc ( l );
        end;

sl    := l;
sLink := Link;

for i := 1 to total do
        if sLink [i] <> 0 then
                begin
                graph [sLink [i]] [i] := false;

                l := 0;
                fillchar ( Link , sizeof ( Link ) , 0 );
                for j :=  1 to total do
                        begin
                        fillchar ( cover , sizeof ( cover ) , 1 );
                        if find ( j ) then inc ( l );
                        end;

                graph [sLink [i]] [i] := true;
                
                if ( l = sl ) then sLink [i] := 0;
                end;

for i := 1 to total do
        if sLink [i] = 0 then
                ans [i] := IDname [i] + ':???'
                else
                ans [i] := IDname [i] + ':' + name [sLink [i]] ;

for i := 1 to n - 1 do
        for j := i + 1 to n do
                if ans [i] > ans [j] then
                        begin
                        temp := ans [i];
                        ans [i] := ans [j];
                        ans [j] := temp;
                        end;

for i := 1 to n do
        writeln ( ans [i] );

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
        main;
        if p < part then writeln;
        end;
end.
