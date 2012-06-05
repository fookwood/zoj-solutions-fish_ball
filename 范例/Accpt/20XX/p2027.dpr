program p2027;

{$APPTYPE CONSOLE}

const
        maxm    = 100;

type
        st      = String [15];
        Tnode   = record
                contect1 , contect2     : Longint;
                cost                    : Longint;
                next                    : Longint;
                end;

        Tdata   = array[1..maxm] of Tnode;

        Tnamecard = array[1..maxm * 2] of st;

        Tnum    = array[1..maxm * 2] of Longint;

        Tmap    = array[1..maxm * 2 , 0..maxm * 2] of Longint;

        Tmk     = array[1..maxm * 2] of Boolean;

var
        m , r           : Longint;
        namecard        : Tnamecard;
        data            : Tdata;
        start , goal    : Longint;
        num             : Tnum;
        Bucket          : Tnum;
        map             : Tmap;
        mk              : Tmk;

function find ( s : St ) : Longint;
var     i               : Longint;
begin
for i := 1 to r do if namecard [i] = s then begin find := i; exit; end;
inc ( r ); namecard [r] := s; find := r;
end;

procedure init;
var     s , t1 , t2     : String;
        c , code        : Longint;
        i               : Longint;
begin
r := 0;
while eoln do readln;
readln ( s );

        t1 := copy ( s , 1 , pos ( ' ' , s ) - 1 );
        delete ( s , 1 , pos ( ' ' , s )); while s [1] =  ' ' do delete ( s , 1 , 1 );
        while ( s [length ( s )] = ' ' ) do delete ( s , length ( s ) , 1 );
        t2 := s;

start := find ( t1 );
goal  := find ( t2 );

readln ( m ); fillchar ( Bucket , sizeof ( Bucket ) , 0 );
for i := 1 to m do
        begin
        while eoln do readln;
        readln ( s );

                t1 := copy ( s , 1 , pos ( ' ' , s ) - 1 );
                delete ( s , 1 , pos ( ' ' , s )); while s [1] = ' ' do delete ( s , 1 , 1 );
                t2 := copy ( s , 1 , pos ( ' ' , s ) - 1 );
                delete ( s , 1 , pos ( ' ' , s )); while s [1] = ' ' do delete ( s , 1 , 1 );
                while ( s [ length ( s )] = ' ' ) do delete ( s , length ( s ) , 1 );
                val ( s , c , code );

        with data [i] do
                begin
                contect1 := find ( t1 );
                contect2 := find ( t2 );
                cost     := c;
                next     := bucket [contect1];

                bucket [contect1] := i;
                end;
        num [i] := i;
        end;
end;

procedure first_makemap ( d : longint );
var     i , j           : Longint;
begin
fillchar ( map , sizeof ( map ) , $FF );
for i := 1 to r do
        begin
        j := bucket [i];
        while ( j <> 0 ) do
                begin
                if data [j] .cost <= data [d] .cost then
                        if j = d then map [data [j] .contect1] [data [j] .contect2] := 0
                                else map [data [j] .contect1] [data [j] .contect2] := data [j] .cost;
                j := data [j] .next;
                end;
        end;
end;

function dijkstra ( start , goal : Longint ) : Longint;
var
        i , k           : Longint;
        min             : Tnum;
begin
for i := 1 to r do if map [start] [i] >= 0 then min [i] := map [start] [i]
        else min [i] := maxLongint;

fillchar ( mk , sizeof ( mk ) , false );
min [start] := 0; mk [start] := true;

repeat
        if mk [goal] then break;
        k := 0;
        for i := 1 to r do
                if not mk [i] and ( ( k = 0 ) or ( min [i] < min [k] )) then k := i;
        if ( k = 0 ) then break;

        mk [k] := true; if min [k] = maxlongint then break;
        for i := 1 to r do
                if not mk [i] and ( map [k] [i] >= 0 ) and ( min [k] + map [k] [i] < min [i] ) then
                        min [i] := min [k] + map [k] [i];
until false;


dijkstra := min [goal];
end;

procedure main;
var     min             : Longint;
        i , t           : Longint;
begin
min := maxLongint;
for i := 1 to m do
        begin
        first_makemap ( i );
        t := dijkstra ( start , goal );
        if t < min then min := t;
        end;
writeln ( min );
end;
        
begin
assign ( input , 'p.in' ); reset ( input );
assign ( output , 'p.out' ); rewrite ( output );

while not seekeof do
        begin
        init;
        main;
        end;
end.
