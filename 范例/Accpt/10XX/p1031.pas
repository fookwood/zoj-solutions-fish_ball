{$I+,Q+,R+,S-}
PROGRAM p1031;

const
        maxn    = 4 ;
        maxL    = 40;
        squ     : array[1..4] of Integer =
                (1 , 5 , 14, 30);
        total   : array[1..4] of Integer =
                (4 , 12 , 24 , 40);

type
        Tdeg    = array[1..maxL ] of Integer;
        Tact    = array[1..maxL , 1..30 ] of Boolean;
        Tsave   = array[1..30 ] of Boolean;

var
        part , p , n , left     : Integer;
        deg                     : Tdeg;
        act                     : Tact;
        save                    : Tsave;

procedure Add ( x , y , l , num : Integer );
var
        first , i , j
                                : Integer;
begin
first := ( x - 1 ) * ( 2 * n + 1 ) + y;

for i := 1 to l do
        begin
        act [first + i - 1] [num] := true;
        inc ( deg [first + i - 1] );
        end;
        // the up line of the square

first := ( x + l - 1 ) * ( 2 * n + 1 ) + y;

for i := 1 to l do
        begin
        act [first + i - 1] [num] := true;
        inc ( deg [first + i - 1] );
        end;
        // the bottom line of the square

first := ( x - 1 ) * ( 2 * n + 1 ) + n + y;

j := 1;
while ( j <= l ) do
        begin
        inc ( j );
        act [first] [num] := true;
        inc ( deg [first] );
        inc ( first , n * 2 + 1);
        end;
        // the left line of the square

first := ( x - 1 ) * ( 2 * n + 1 ) + n + y + l;
j := 1;
while ( j <= l ) do
        begin
        inc ( j );
        act [first] [num] := true;
        inc ( deg [first] );
        inc ( first , n * 2 + 1);
        end;
        // the right line of the square
end;

procedure Init;
var
        i , j , k , num                 : Integer;
        m               : Integer;
begin
fillchar ( deg , sizeof ( deg ) , 0 );
fillchar ( Act , sizeof ( Act ) , 0 );
readln ( n );
        // square
left := squ [n];


num := 0;
for i := 1 to n do
        for j := 1 to n - i + 1 do
                for k := 1 to n - i + 1 do
                        begin
                        inc ( num );
                        Add ( j , k , i , num);
                        end;
end;

procedure Del ( p : Integer ) ;
var
        i , j                   : Integer;
begin
deg [p] := -1;
for i := 1 to squ [n] do
        if act [p] [i] and save [i] then
                begin
                save [i] := false;
                for j := 1 to total [n] do
                        if ( deg [j] > 0 ) and ( act [j] [i] ) then dec ( deg [j] );
                dec ( left );
                end;
end;

procedure Cut;
var
        t , i , a , ans                 : Integer;
        j : Integer;
begin
fillchar ( save , sizeof ( save ) , 1 );
read ( t );
for i := 1 to t do
        begin
        read ( a );
        Del ( a );
        {writeln ( 'Del ' , a );
        for j:= 1 to squ [n] do write ( save [j] :8 );
        writeln;}
        end;
readln;
if ( a = total [maxn] ) then dec ( left );


ans := 0;
while left > 0 do
        begin
        inc ( ans );
        a := 0;
        for i := 1 to total [n] do
                if ( deg [i] > a ) then
                        begin
                        a := deg [i];
                        t := i;
                        end;
//        writeln ( 'choose ' , t );
        Del ( t );
//        for i:= 1 to squ [n] do write ( save [i] :8 );
//        writeln;
        end;

writeln ( ans );
end;

begin
assign ( input , 'p.in' );
reset ( input );
readln ( part );
for p := 1 to part do
        begin
        Init;
        Cut;
        end;
end.