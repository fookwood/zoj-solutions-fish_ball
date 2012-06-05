program p2063;

{$APPTYPE CONSOLE}

{%File 'p.in'}

const
        maxn    = 50000;
        maxh    = 213709;

type
        ts      = string [30];
        Tname   = array[1..maxn] of ts;
        Tnum    = array[0..maxn] of Longint;
        Thash   = array[0..maxh - 1] of Longint;

var
        name    : Tname;
        power   : Tnum;
        next    : Tnum;
        w       : Tnum;
        hash    : Thash;

function hnum ( var s : Ts ) : Longint;
var     i , q   : Longint;
begin
q := 0; for i := 1 to length ( s ) do inc ( q , ( i * ord ( s [i] )) shl ( i shr 1 ));
hnum := q mod maxh;
end;

procedure makehash;
var     d , p   : Longint;
        ch      : Char;
begin
fillchar ( hash , sizeof ( hash ) , 0 );
readln ( d );
while ( d > 0 ) do
        begin
        read ( ch ); while ( ch <> '[' ) do read ( ch ); name [d] := '';
        read ( ch ); while ( ch <> ']' ) do begin name [d] := name [d] + ch; read ( ch ) end;
        readln ( power [d] );
        p := hnum ( name [d] );
        next [d] := hash [p]; hash [p] := d;
        dec ( d );
        end;
end;

procedure main;
var     s       : Ts;
        ch      : Char;
        n , k   : Longint;
        i , p   : Longint;
        j       : Longint;
        a , b   : Longint;
        max     : Longint;
        maxpower: Longint;
        distroy : Boolean;

        procedure stop ( k , d : Longint );
        begin
        writeln ( 'The power will be out at time ' , k , ' because the power is ' , d , ' Watts and overloaded.' );
        end;
begin
while not seekeof do
        begin
        max := 0;
        fillchar ( w , sizeof ( w ) , 0 );

        readln ( n , k );
        for i := 1 to n do
                begin
                s := ''; read ( ch ); while ( ch <> '[' ) do read ( ch );
                read ( ch ); while ( ch <> ']' ) do begin s := s + ch; read ( ch ); end;
                readln ( a , b ); if b > max then max := b;
                p := hnum ( s ); j := hash [p];
                while ( name [j] <> s ) do j := next [j];
                inc ( w [a] , power [j] );
                dec ( w [b] , power [j] );
                end;

        distroy := false;
        if w [0] > k then begin stop ( 0 , w [0] ); continue; end;
        maxpower := w [0];
        for i := 1 to max do
                begin inc ( w [i] , w [i - 1] );
                if w [i] > k then begin stop ( i , w [i] ); distroy := true; break end;
                if w [i] > maxpower then maxpower := w [i];
                end;
        if not distroy then writeln ( 'The maximum power needed is ' , maxpower , ' Watts.' );
        end;
end;

begin
makehash;
main;
end.


