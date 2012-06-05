program p2424;

{$APPTYPE CONSOLE}

const
        maxlen  = 200;

type
        Hp      = Object
                len     : Longint;
                s       : array[1..maxlen] of Longint;

                procedure print;
                function Mul_ ( const b : Longint ) : Hp;
                function Div_ ( const b : Longint ) : Hp;
                end;

        Tdata   = array[1..100] of Hp;

var
        data    : Tdata;
        n       : Longint;

procedure Hp . print;
var     i       : Longint;
begin
for i := len downto 1 do write ( s [i] ); writeln;
end;

function Hp .Mul_ ( const b : Longint ): Hp;
var     c       : hp;
        i , t   : Longint;
begin
t := 0;
for i := 1 to len do
        begin
        t := t + s [i] * b;
        c .s [i] := t mod 10;
        t := t div 10;
        end;
c .len := len; while ( t > 0 ) do
        begin
        inc ( c .len );
        c . s [c .len] := t mod 10;
        t := t div 10;
        end;
Mul_ := c;
end;

function Hp .Div_ ( const b : Longint ) : HP;
var     c       : hp;
        i , t   : Longint;
begin
t := 0;
for i := len downto 1 do
        begin
        t := t * 10 + s [i];
        c .s [i] := t div b;
        t := t mod b;
        end;
c .len := len;
while ( c .len > 1 ) and ( c . s [c .len] = 0 ) do dec ( c .len );
Div_ := c;
end;

procedure first;
var     i    : Longint;
begin
data [1] .len := 1; data [1] .s [1] := 1;
for i := 1 to 99 do
        data [i + 1] := data [i] .Mul_ ( 4 * i + 2 ) .Div_ ( i + 2 );
end;

begin
first;
readln ( n );
while ( n > 0 ) do
        begin
        data [n] .print;
        readln ( n );
        end;
end.
 