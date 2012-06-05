// Accept
// TIME : 2005/06/07
{$R+,I+,Q+,S+}
PROGRAM p2430;

{$APPTYPE CONSOLE}

const
        Mmax    = 20;
        Nmax    = 30;
        base_p  = 10000;
        base_b  = 4;

type
        BigNum  = array[0..30 ] of Longint;
        Torder  = array[1..Mmax + 1 ] of Longint;
        Tsingle = array[0..Nmax ] of Longint;
        TLimit  = array[1..Mmax ] of Tsingle;
        Tfinal  = array[0..10000 ] of Integer;
        Tdata   = array[0..10000 ] of BigNum;

VAR
        part , p , N , M , S , d , Max  : Integer;
        AddSum , SubSum                 : BigNum;
        order                           : Torder;
        Limit                           : TLimit;
        final                           : Tfinal;
        data                            : Tdata;

procedure base_add ( var a , b : BigNum );
var
        i , t                           : Longint;
begin
for i := b [0] downto a [0] + 1 do a [i] := 0;
if b [0] > a [0] then a [0] := b [0];
for i := 1 to b [0] do a [i] := a[i] + b [i];

t := 0;
for i := 1 to a [0] do
        begin
        t       := a [i] + t;
        a [i]   := t mod base_p;
        t       := t div base_p;
        end;
        
while ( t > 0 ) do
        begin
        inc ( a [0] );
        a [a [0]] := t mod base_p;
        t         := t div base_p;
        end;
end;

procedure base_sub ( var a , b : BigNum );
var
        i                               : Longint;
begin
for i := 1 to b [0] do a [i] := a [i] - b [i];
for i := 1 to a [0] do
        if a [i] < 0 then
                begin
                a [i]      := base_p + a [i];
                a [i + 1]  := a [i + 1] - 1;
                end;
while ( a [0] > 1 ) and ( a [a [0]] = 0 ) do dec ( a [0] );
end;

procedure base_mul ( var a : BigNum ; b : Longint );
var
        i , t                           : Longint;
begin
t := 0;
for i := 1 to a [0] do
        begin
        t       := a [i] * b + t;
        a [i]   := t mod base_p;
        t       := t div base_p;
        end;
while ( t > 0 ) do
        begin
        inc ( a [0] );
        a [a [0]] := t mod base_p;
        t         := t div base_p;
        end;
end;

procedure base_div ( var a : BigNum ; b : Longint );
var
        i , t                           : Longint;
begin
t := 0;
for i := a [0] downto 1 do
        begin
        t       := t * base_p + a [i];
        a [i]   := t div b;
        t       := t mod b;
        end;
while ( a [0] > 1 ) and ( a [a [0]] = 0 ) do dec ( a [0] );
end;

procedure base_c ( var c : BigNum ; a , b : Longint );
var
        i                               : Longint;
begin
c [0] := 1;
if ( a < b ) or ( b < 0 ) then
        begin
        c [1] := 0;
        exit;
        end;
c [1] := 1;
for i := 1 to b do
        begin
        base_mul ( c , a - b + i );
        base_div ( c , i );
        end;
end;

procedure base_print ( var a : BigNum );
var
        i , j , t                       : Longint;
begin
write ( a [a [0]] );
for i := a [0] - 1 downto 1 do
        begin
        if a [i] = 0 then t := base_b - 1
                else t := base_b - trunc ( ln ( a [i] ) / ln ( 10 ) ) - 1;
        for j := 1 to t do write ( 0 );
        write ( a [i] );
        end;
writeln;
end;

procedure base_change ( var a : BigNum ; b : Longint ) ;
begin
a [0] := 0;
while ( b > 0 ) do
        begin
        inc ( a [0] );
        a [a [0]] := b mod base_p;
        b := b div base_p;
        end;
if a [0] = 0 then
        begin
        a [0] := 1;
        a [1] := 0;
        end;
end;

procedure make_order;
var
        i                               : Integer;
begin
order [1] := 1;
for i := 2 to Mmax + 1 do order [i] := order [i - 1] shl 1;
end;

procedure init;
var
        i , j , T                       : Longint;
        Temp                            : BigNum;

procedure check;
var
        i , j                           : Longint;
        C                               : Boolean;

begin
Limit [M] [0] := 0;
for i := 1 to N do Limit [M] [0] := Limit [M] [0] + Limit [M] [i];
Limit [M] [0] := S - Limit [M] [0];

if Limit [M] [0] < 0 then
        begin
        Dec ( M );
        exit;
        end;

for i := 1 to M - 1 do
        begin
        C := true;
        for j := 1 to N do
                if ( Limit [i] [j] > Limit [M] [j] ) then
                        begin
                        C := false;
                        break;
                        end;
        if C then
                begin
                Dec ( M );
                exit;
                end;

        C := true;
        for j := 1 to N do
                if ( Limit [i] [j] < Limit [M] [j] ) then
                        begin
                        C := false;
                        break;
                        end;
        if C then
                begin
                for j := 0 to N do Limit [i] [j] := Limit [M] [j];
                Dec ( M );
                exit;
                end;
        end;
end;

begin
readln ( N , S , T );

M := 0;
for i := 1 to T do
        begin
        inc ( M );
        for j := 1 to N do
                read ( Limit [M] [j] );
        
        check;
        end;

base_change ( AddSum , N - 1);
base_change ( SubSum , 0);

base_c ( Temp , N + S , N );
base_add ( AddSum , Temp );

base_change ( Temp , 1 + S );
base_mul ( Temp , N );
base_add ( SubSum , Temp );

end;

procedure make ( add : Boolean ; v : Longint ; var T : Tsingle );

var
        i , j           : Integer;
        T2              : Tsingle;

begin
if T [0] > Max then Max := T [0];
if add then inc ( final [T [0]] )
        else dec ( final [T [0]] );

for i := M downto 1 do
        if v and order [i] = 0 then
                begin
                T2 [0] := 0;
                for j := 1 to N do
                        begin
                        if Limit [i] [j] > T [j] then
                                T2 [j] := Limit [i] [j]
                                else
                                T2 [j] := T [j];
                        inc ( T2 [0] , T2 [j] );
                        end;
                T2 [0] := S - T2 [0];

                if T2 [0] >= 0 then make ( not add , v or order [i] , T2 );
                end
                else break;
end;

procedure main;
var
        i , j , t               : Longint;
        
begin
base_change ( data [0] , 1 );

for i := 0 to Max - 1 do
        begin
        t := 0;
        data [i + 1] [0] := data [i] [0];
        for j := 1 to Data [i] [0] do
                begin
                t := data [i] [j] * ( N + i + 1 ) + t;
                data [i + 1] [j] := t mod base_p;
                t := t div base_p;
                end;

        while ( t > 0 ) do
                begin
                inc ( data [i + 1] [0] );
                data [i + 1] [ data [i + 1] [0]] := t mod base_p;
                t := t div base_p;
                end;

        t := 0;
        for j := data [i + 1] [0] downto 1 do
                begin
                t := data [i + 1] [j] + base_p * t;
                data [i + 1] [j] := t div ( i + 1 );
                t := t mod ( i + 1 );
                end;
                
        while ( data [i + 1] [0] > 1 ) and ( data [i + 1] [data [i + 1] [0]] = 0 ) do dec ( data [i + 1] [0] );
        end;

for i := 0 to Max do
        if final [i] <> 0 then
                begin
                base_mul ( data [i] , abs ( final [i] ) );
                if final [i] > 0 then
                        base_add ( AddSum , data [i] )
                                else
                        base_add ( SubSum , data [i] );
                end;

base_sub ( AddSum , SubSum );

base_print ( AddSum );
end;

BEGIN
{assign ( input , 'p.in' );
reset ( input );
assign ( output , 'p.out' );
rewrite ( output );
writeln ( 'p2430.dpr' );}

make_order;

readln ( part );
for p := 1 to part do
        begin
        init;
        fillchar ( final , sizeof (final ) , 0 );
        Max := 0;
        for d := 1 to M do
                make ( false , order [d] , Limit [d] );

        main;
if ( p < part ) then writeln;
        end;
END.
