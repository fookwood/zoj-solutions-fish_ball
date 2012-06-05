program p1075;

{$APPTYPE CONSOLE}

{%File 'p.in'}

const   maxn    = 100;

type
        Tnode   = array[1..4] of Char;
        Tdata   = array[1..maxn] of Tnode;

var
        n                       : Longint;
        data                    : Tdata;

procedure init;
begin
n := 0;
repeat
        inc ( n );
        readln ( data [n] [1] , data [n] [2] , data [n] [3] , data [n] [4] );
until eof or eoln;
if not eof then readln;
end;

function check ( a , b , c : Longint ): Boolean;
var     t                               : Longint;
begin check := false;
t := 0; if data [a] [1] = data [b] [1] then inc ( t );
        if data [a] [1] = data [c] [1] then inc ( t );
        if data [b] [1] = data [c] [1] then inc ( t );
if ( t <> 0 ) and ( t <> 3 ) then exit;
t := 0; if data [a] [2] = data [b] [2] then inc ( t );
        if data [a] [2] = data [c] [2] then inc ( t );
        if data [b] [2] = data [c] [2] then inc ( t );
if ( t <> 0 ) and ( t <> 3 ) then exit;
t := 0; if data [a] [3] = data [b] [3] then inc ( t );
        if data [a] [3] = data [c] [3] then inc ( t );
        if data [b] [3] = data [c] [3] then inc ( t );
if ( t <> 0 ) and ( t <> 3 ) then exit;
t := 0; if data [a] [4] = data [b] [4] then inc ( t );
        if data [a] [4] = data [c] [4] then inc ( t );
        if data [b] [4] = data [c] [4] then inc ( t );
if ( t <> 0 ) and ( t <> 3 ) then exit;check := true;
end;

procedure work;
var     i , j , k , t , r        : Longint;
begin
write ( 'CARDS: ' ); for i := 1 to n do write ( ' ' , data [i] [1] , data [i] [2] , data [i] [3] , data [i] [4] );
writeln;
write ( 'SETS:' ); t := 0;
for i := 1 to n - 2 do
        for j := i + 1 to n - 1 do
                for k := j + 1 to n do
                        if check ( i , j , k ) then
                                begin
                                inc ( t );
                                if t = 1 then for r := 1 to 3 do write ( ' ' )
                                        else for r := 1 to 8 do write ( ' ' );
                                write ( t , '. ' );
                                write ( ' ' , data [i] [1] , data [i] [2] , data [i] [3] , data [i] [4]);
                                write ( ' ' , data [j] [1] , data [j] [2] , data [j] [3] , data [j] [4]);
                                write ( ' ' , data [k] [1] , data [k] [2] , data [k] [3] , data [k] [4]); writeln;
                                end;
if t = 0 then writeln ( '   *** None Found ***' );
end;

begin
//assign ( input , 'p.in' ); reset ( input );
//assign ( output , 'p.out' ); rewrite ( output );
while ( not eof ) do
        begin
        init;
        work;
        if not eof then writeln else break;
        end; 
end.
