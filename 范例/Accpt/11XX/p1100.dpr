program p1100;

{$APPTYPE CONSOLE}

uses    sysutils;

const
        maxn    = 10;
        maxsize = 1024;

        order   : array[1..maxn + 1] of Longint =
        (1,2,4,8,16,32,64,128,256,512,1024);

type
        TLink   = array[0..maxsize] of Longint;
        TdLink  = array[0..maxsize * 10] of Longint;
        Tbool   = array[0..maxsize] of Boolean;

var
        StartTime       : Double;
        n , m , Tot     : Longint;

        even , value    : Tbool;

        Bucket          : TLink;
        Next , Contact  : TdLink;

        Ans             : array[0..1 , 0 ..maxsize] of Int64;//Longint;

procedure first;
var     i , j   : Longint;
begin
fillchar ( even , sizeof ( even ) , 1 );
for i := 0 to order [11] - 1 do
        for j := 1 to 10 do
                if i and order [j] <> 0 then even [i] := not even [i];
end;

procedure change ( var a , b : Longint );
var     t       : Longint;
begin
t := a; a := b; b := t;
end;

function have ( s , n : Longint ) : Boolean;
var     i       : Longint;
begin
have := false;
for i := 2 to n do
        if ( s and order [i] = 0 ) and ( s and order [i - 1] = 0 ) then exit;
have := true;
end;

function back ( s , n : Longint ) : Longint;
var     t , i   : Longint;
begin
t := 0; for i := 1 to n do if s and order [i] = 0 then t := t or order [i];
back := t;
end;

procedure search ( dep , p , s : Longint );
var     i       : Longint;
begin
inc ( Tot );
Next [Tot] := Bucket [s]; Bucket [s] := Tot;
Contact [Tot] := p;

for i := dep to n do
        if ( p and order [i] = 0 ) and ( p and order [i - 1] = 0 )
                then search ( i + 2 , p or order [i] or order [i - 1] , s );
end;

procedure print ( v : Longint );
var     i       : Longint;
begin
for i := 1 to n do write ( ord ( v and order [i] > 0 )); writeln;
end;

procedure main;
var     i       : Longint;
        j , k   : Longint;
        a , b   : Longint;
        Final   : Int64;
begin
if odd ( n ) then change ( n , m );
if odd ( n ) then begin writeln ( 0 ); exit end;
if not odd ( m ) and ( m < n ) then change ( n , m );

//writeln ( ' m = ' , m , '   n = ' , n );

if ( m = 1 ) then begin writeln ( 1 ); exit end;

Tot := 0; a := 0; b := 1;
fillchar ( Ans , sizeof ( Ans ) , 0 );
fillchar ( value , sizeof ( value ) , 0 );
search ( 2 , 0 , 0 );
for i := 0 to Tot do
        begin
        Ans [a] [Contact [i]] := 1;
        value [Contact [i]] := true;
        end;

Tot := 0;
fillchar ( Bucket , sizeof ( Bucket ) , 0 );

for i := 0 to order [n + 1] - 1 do if even [i]
        then {if have (i , n)
                then }search ( 2 , back ( i , n ) , i )
              {  else begin
                inc ( Tot );
                Next [Tot] := Bucket [i]; Bucket [i] := Tot;
                Contact [Tot] := back ( i , n );
                end};

//writeln ( ' After work the number of Total points is : ' , Tot );

//for i := 1 to Tot do writeln ( Contact [i] ); writeln;

//for i := 0 to order [n + 1] - 1 do write ( Ans [a] [i] , ' ' ); writeln;

for i := 1 to m - 2 do
        begin
        for j := 0 to order [n + 1] - 1 do Ans [b] [j] := 0;
        for j := 0 to order [n + 1] - 1 do  
                begin k := Bucket [j];
//                if k <> 0 then print ( j );
                while ( k <> 0 ) do
                        begin
                        Ans [b] [Contact [k]] := Ans [b] [Contact [k]] + Ans [a] [j];
//                        print ( Contact [k] );
                        k := Next [k];
                        end;
//                writeln;
                end;

//        for j := 0 to order [n + 1] - 1 do write ( j : 3 ); writeln;
//        for j := 0 to order [n + 1] - 1 do write ( Ans [b] [j] : 3 ); writeln;

        a := 1 - a;
        b := 1 - b;
        end;


Final := 0; for i := 0 to order [n + 1] - 1 do if value [i] then
        Final := Final + Ans [a] [i];
writeln ( Final );
end;

begin
assign ( input , 'p.in' ); reset ( input );
assign ( output , 'p.out' ); rewrite ( output );
StartTime := Time;

first;

readln ( n , m );
while ( n > 0 ) do
        begin
        main;
        readln ( n , m );
        end;

//writeln ( ( Time - StartTime ) * 24 * 60 * 60  : 0 : 5 , '  s' );
end.
