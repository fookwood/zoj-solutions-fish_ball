// not Accept
// Time 2005/06/12

program p1319;

const
        maxn    = 30000;

type
        Tadd    = array[0..maxn + 1] of Longint;

var
        part , p , n , m        : Longint;
        add , ask , data        : Tadd;


procedure init;
var
        i               : Longint;
begin
readln ( n , m );
for i := 1 to n do read ( add [i] );
for i := 1 to m do read ( ask [i] );
end;

procedure main;
var
        i , j , L , R , Q , P , k         : Longint;
begin
i := 1; data [0] := - maxLongint; data [1] := maxLongint;
for j := 1 to m do
        begin
        while ( i <= ask [j] ) do
                begin
                L := 0; R := i + 1; P := 1;
                while ( L < R ) do
                        begin
                        Q := ( L + R ) shr 1;
                        if data [Q] >= add [i] then begin P := Q; R := Q; end
                                else L := Q + 1;
                        end;
                move ( data [P] , data [P + 1] , 4 * ( i - P + 1 ) );
                data [P] := add [i];
                inc ( i );
                end;
        writeln ( data [j] );
        end;
end;

begin
{assign ( input , 'p.in' );
reset ( input );}

readln ( part );
for p := 1 to part do
        begin
        init;
        main;
        if p < part then writeln;
        end;
end.