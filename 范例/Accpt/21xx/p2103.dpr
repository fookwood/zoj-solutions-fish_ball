program p2103;

{$APPTYPE CONSOLE}

const
        maxn    = 10;
        maxm    = 20;

type
        Tnum    = array[0..maxn] of Longint;
        Tline   = array[0..maxm * 2] of Longint;
        Tused   = array[0..maxn , 0..maxn] of Boolean;

var
        n , m   : Longint;
        c       : Longint;
        Min     : Longint;
        bucket  : Tnum;
        col     : Tline;
        next    : Tline;
        contact : Tline;
        used    : Tused;

procedure init;
var     i       : Longint;
        t       : Longint;
        a , b   : Longint;
begin
fillchar ( bucket , sizeof ( bucket ) , 0 );
t := 0;
for i := 1 to m do
        begin
        inc ( t );
        readln ( a , b , col [t] );
        Next [t] := bucket [a];
        bucket [a] := t;
        contact [t] := b;

        inc ( t );
        col [t] := col [t - 1];
        Next [t] := Bucket [b];
        Bucket [b] := t;
        contact [t] := a;
        end;

end;

procedure search ( dep , p , now , cost : Longint );
var     i       : Longint;
begin
if dep = m then begin
        if cost < min then min := cost;
        exit;
        end;

if cost > min then exit;

i := Bucket [p];
while ( i <> 0 ) do
        begin
        if not used [p] [contact [i]] then
                begin
                used [p] [contact [i]] := true;
                used [contact [i]] [p] := true;
                
                if ( now = -1 ) or ( now = col [i] )
                        then search ( dep + 1 , contact [i] , col [i] , cost )
                        else search ( dep + 1 , contact [i] , col [i] , cost + 1 );
                        
                used [p] [contact [i]] := false;
                used [contact [i]] [p] := false;
                end;
        i := Next [i];
        end;
end;

procedure Main;
var
        i       : Longint;
begin
Min := MaxLongint;
for i := 0 to n - 1 do
        begin
        fillchar ( used , sizeof ( used ) , 0 );
        search ( 0 , i , -1 , 0 );
        end;
if min = MaxLongint then writeln ( 'No' )
        else writeln ( min );
end;

begin
assign ( input , 'p.in' ); reset ( input );
assign ( output , 'p.out' ); rewrite ( output );

while true do
        begin
        readln ( n , c , m );
        if ( n = 0 ) and ( c = 0 ) and ( m = 0 ) then break;
        init;
        Main;        
        end;
end.
