program p1069;

{$APPTYPE CONSOLE}

{%File 'p.in'}

const
        maxn    = 20;

type
        Tnode   = record
                name    : array[0..3] of String;
        end;
        Tdata   = array[0..2 ] of Tnode;
        Twhether = array[0..2,0..3,0..2,0..3] of Boolean;
        TStack  = array[0..2] of Integer;

var
        n , step                : Integer;
        data                    : Tdata;
        whether                 : Twhether;
        Stack                   : TStack;

PROCEDURE Init;
var
        i , j  , a , b          : Integer;
        s                       : String;
        temp                    : Char;
begin
for i := 0 to 2 do
        begin
        readln ( data [i] . name [0] );
        data [i] . name [1] := data [i] . name [0] [n];
        data [i] . name [3] := data [i] . name [0] [1];
        for j := 2 to n - 1 do
                begin
                readln ( s );
                data [i] . name [1] := data [i] . name [1] + s [n];
                data [i] . name [3] := s [1] + data [i] . name [3];
                end;
        if n > 1 then
                begin
                readln ( s );
                data [i] . name [2] := s;
                data [i] . name [1] := data [i] . name [1] + s [n];
                data [i] . name [3] := s [1] + data [i] . name [3];
                end;
        for j := 1 to n div 2 do
                begin
                temp := data [i] . name [2] [j];
                data [i] . name [2] [j] := data [i] . name [2] [n + 1 - j];
                data [i] . name [2] [n + 1 - j] := temp;
                end;
        end;

{for i := 0 to 2 do
        begin
        for j := 0 to 3 do writeln ( data [i] . name [j] );
        writeln;
        end;  }

fillchar ( whether , sizeof ( whether ) , 0 );
for i := 0 to 2 do
        for a := 0 to 3 do
                for j := 0 to 2 do
                        for b := 0 to 3 do
                                if data [i] . name [a] = data [j] . name [b] then
                                        whether [i] [a] [j] [b] := true; 
end;

FUNCTION Check : Boolean;
var
        i , j , k                       : Integer;
begin
for i := 0 to 2 do
        for j := 0 to 2 do
                if ( i <> j ) then
                for k := 0 to 2 do
                        if ( i <> k ) and ( j <> k ) then
{i := 0;
j := 1;
k := 2;}
begin
if (    whether [i] [( Stack [0] + 3 ) mod 4 ] [j] [Stack [1]] and
        whether [j] [( Stack [1] + 3 ) mod 4 ] [k] [Stack [2]] and
        whether [k] [( Stack [2] + 3 ) mod 3 ] [i] [Stack [0]] )
        then
        begin
        check := true;
        exit;
        end;
continue;
if (    whether [i] [Stack [0]] [1] [Stack [j]] and
        whether [j] [( Stack [1] + 3 ) mod 4 ] [k] [Stack [2]] and
        whether [k] [( Stack [2] + 3 ) mod 3 ] [i] [( Stack [0] + 3 ) mod 4] )
        then
        begin
        check := true;
        exit;
        end;

if (    whether [i] [( Stack [0] + 3 ) mod 4 ] [j] [( Stack [1] + 3 ) mod 4] and
        whether [j] [Stack [1]] [k] [Stack [2]] and
        whether [k] [( Stack [2] + 3 ) mod 3 ] [i] [Stack [0]] )
        then
        begin
        check := true;
        exit;
        end;

if (    whether [i] [( Stack [0] + 3 ) mod 4 ] [j] [Stack [1]] and
        whether [j] [( Stack [1] + 3 ) mod 4 ] [k] [( Stack [2] + 3 ) mod 4] and
        whether [k] [Stack [2]] [i] [Stack [0]] )
        then
        begin
        check := true;
        exit;
        end;


if (    whether [i] [Stack [0]] [j] [( Stack [1] + 3 ) mod 4] and
        whether [j] [Stack [1]] [k] [Stack [2]] and
        whether [k] [( Stack [2] + 3 ) mod 3 ] [i] [( Stack [0] + 3 ) mod 4] )
        then
        begin
        check := true;
        exit;
        end;

if (    whether [i] [Stack [0]] [j] [Stack [1]] and
        whether [j] [( Stack [1] + 3 ) mod 4 ] [k] [( Stack [2] + 3 ) mod 4] and
        whether [k] [Stack [2]] [i] [( Stack [0] + 3 ) mod 4] )
        then
        begin
        check := true;
        exit;
        end;

if (    whether [i] [( Stack [0] + 3 ) mod 4 ] [j] [( Stack [1] + 3 ) mod 4] and
        whether [j] [Stack [1]] [k] [( Stack [2] + 3 ) mod 4] and
        whether [k] [Stack [2]] [i] [Stack [0]] )
        then
        begin
        check := true;
        exit;
        end;
end;
Check := false;
end;

FUNCTION Find : Boolean ;
var
        dep , i                    : Integer;
begin
if step < 15 then
        begin
        if step <> 2 then find := true else find :=false;
        exit;
        end else
        begin
        find := false;
        exit;
        end;
//if ( step mod 7 = 0 ) then begin Find := true ;  exit ; end;
for i := 0 to 2 do Stack [i] := -1;
dep := -1;
while ( true ) do
        begin
        inc ( dep ) ;
        if dep = 3 then
                begin
                if  check then
                        begin
                        Find := true;
                        exit;
                        end;
                dec ( dep );
                end;
        while ( dep > -1 ) and ( Stack [dep] = 3 ) do
                begin
                Stack [dep] := -1;
                dec ( dep );
                end;
        if ( dep = -1 ) then break;
        inc ( Stack [dep] );
        end;
Find := false;
end;

begin
//assign ( input , 'p.in' );
//reset ( input );
//assign ( output , 'p.out' );
//rewrite ( output );
step := 0;
readln ( n );
while ( n <> 0 ) do
        begin
        inc ( step );
//        writeln ( step );
        Init;
        if Find then writeln ( 'Data set ' , step , ': Valid set of patterns')
                else writeln ( 'Data set ' , step , ': Impossible combination' );
        readln ( n );
        end;
end.

