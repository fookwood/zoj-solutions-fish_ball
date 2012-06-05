program p2439;

{$APPTYPE CONSOLE}

type
        triple  = array[1..4] of Integer;
        Typeans = record
                total           : Integer;
                solve           : array[1..1200] of triple;
                end;
        Tans    = ^Typeans;
        TypeC_L = array[1..4] of Integer;

var
        part , tx , ty , K      : Integer;
        p , q                   : Tans;
        min                     : Integer;
        c , l , choose          : TypeC_L;

PROCEDURE Init;
var
        ta , tb , tc , td , i   : Integer;
begin
read ( ta , tb , tc , td , K );
tx := abs ( tc - ta );
ty := abs ( td - tb );
for i := 1 to K do read ( l [i] );
for i := 1 to K do read ( c[i] );
end;

PROCEDURE Make ( var d : Tans; final : Integer);
var
        i , j , sum , dep     : Integer;
begin
new ( d );
d ^. total := 0;
sum := 0;
dep := 0;
choose [1] := - c [1] - 1;
while ( true ) do
        begin
        inc ( dep ) ;

        if dep = K then
                begin
                sum := 0;
                for i := 1 to K - 1 do sum := sum + l [i] * choose [i];
                if abs ( final - sum ) mod l [k] = 0 then
                        begin
                        j := ( final - sum ) div l [K];
                        if abs ( j ) <= c [K] then
                                begin
                                inc ( d ^.total );
                                for i := 1 to K - 1 do
                                        d ^.solve [d^.total] [i] := choose [i];
                                d ^.solve [d^.total] [K] := j;
                                end;
                        end;
                dec ( dep );
                end;

        while ( dep > 0 ) and ( choose [dep] = c [dep] ) do
                begin
                choose [dep] := - c [dep] - 1;
                dec ( dep );
                end;
        if dep = 0 then break;
        inc ( choose [dep] );
        end;
end;

PROCEDURE Main;
var
        i , j , a , sum         : Integer;
        well                    : Boolean;
begin
Make ( p , tx );

//writeln ( p ^.total);
//for i := 1 to K do write ( p ^.solve [1] [i] ,'  ' );
//writeln;

if ty = tx then q := p
        else Make ( q , ty );

min := maxint;
for i := 1 to p ^.total do
        for j := 1 to q ^.total do
                begin
                sum  := 0;
                well := true;
                for a := 1 to K do
                        if abs ( p ^.solve [i] [a] ) + abs ( q ^.solve [j] [a] ) > c [a] then
                                begin
                                well := false;
                                break;
                                end else sum := sum + abs ( p ^.solve [i] [a] ) + abs ( q ^.solve [j] [a] );
                if well and ( sum < min ) then min := sum; 
                end;
if min < maxint then writeln ( min )
        else writeln ( -1 );
end;

begin
//assign ( input , 'p.in' );
//reset ( input );
//assign ( output , 'p.out' );
//rewrite ( output );
read ( part ) ;
while ( part > 0 ) do
        begin
        dec ( part );
        Init;
        Main;
        if part > 0 then writeln;
        end;
end.
