{$R+,I+,S+,Q+}

program p2065;

const
        max     : array[1..13] of Integer =
        (10,11,12,19,18,17,16,17,18,19,12,11,10);
        min     : array[1..13] of Integer =
        (9,8,7,0,1,2,3,2,1,0,7,8,9);
        step    : array[1..6,1..2] of Integer =
        ((-1,1),(1,1),(0,2),(1,-1),(-1,-1),(0,-2));

type
        node                    = record
                                x , y                   : Integer;
                                end;

        Tmap                    = array[1..13] of String;
        Tans                    = array[1..13,1..30] of Integer;
        TList                   = array[1..300] of node;

var
        part , p , sx , sy , tx , ty
                                : Integer;
        map                     : Tmap;
        ans , us                : Tans;
        List                    : TList;

procedure init;
var
        j , k                   : Integer;
begin
readln;
for j := 1 to 13 do
        for k := 1 to 30 do
                ans [j] [k] := maxint;

for j := 1 to 13 do
        begin
        readln ( map [j] );
        if length ( map [j] ) < max [j] then while true do;
        if pos ( 'S' , map [j] ) > 0 then
                begin
                sx := j;
                sy := pos ( 'S' , map [j] );
                end;
        if pos ( 'E' , map [j] ) > 0 then
                begin
                tx := j;
                ty := pos ( 'E' , map [j] );
                end;
        end;
fillchar ( us , sizeof ( us ) , 0 );
end;


procedure Kfs;
var
        open , closed , i , cx , cy                 : Integer;

procedure search ( x , y , l : Integer ) ;
var
        i , cx , cy                                     : Integer;
begin
//if ( l = 2 ) then writeln ( x , ' ' , y , ' '  , l  , ' ' ,'e' , ' ' , ans [7] [12]);
if ( x < 1 ) or ( x > 13 ) or ( y < min [x] ) or ( y > max [x] ) then exit;
if map [x] [y] = '*' then exit;
if ( l < ans [x] [y] ) or ( ( l = ans [x] [y] ) and ( us [x] [y] = 1 ) ) then
        begin
        ans [x] [y] := l;
        inc ( closed );
        List [closed] . x := x;
        List [closed] . y := y;
        if us [x] [y] = 1 then dec ( closed );
        us [x] [y] := 2;
        for i := 1 to 6 do
                begin
                cx := x + step [i] [1];
                cy := y + step [i] [2];
                if ( cx < 1 ) or ( cx > 13 ) or ( cy < min [cx] ) or ( cy > max [cx] ) then continue;

                if map [cx] [cy] = '*' then
                        search ( cx + step [i] [1] , cy + step [i] [2] , l );
                end;
        end;

end;

begin
open   := 1;
closed := 1;
List [1] . x := sx;
List [1] . y := sy;
ans [sx] [sy] := 0;
//writeln ( sx , ' ' , sy );

repeat
        //with List [open] do writeln ( x ,' ' , y , ' ' , ans [x] [y] );
        for i := 1 to 6 do
                begin
                cx := List [open] . x + step [i] [1];
                cy := List [open] . y + step [i] [2];
                if ( cx < 1 ) or ( cx > 13 ) or ( cy < min [cx] ) or ( cy > max [cx] ) then continue;
                if map [cx] [cy] = '*' then
                        with List [open] do
                                search ( cx + step [i] [1] , cy + step [i] [2] , ans [x] [y] + 1);
                end;

        for i := 1 to 6 do
                begin
                cx := List [open] . x + step [i] [1];
                cy := List [open] . y + step [i] [2];
                if ( cx < 1 ) or ( cx > 13 ) or ( cy < min [cx] ) or ( cy > max [cx] ) then continue;
                if map [cx] [cy] <> '*' then
                        begin
                        with List [open] do
                                if ans [x] [y] + 1 < ans [cx] [cy] then
                                        begin
                                        us [cx] [cy] := 1;
                                        ans [cx] [cy] := ans [x] [y] + 1;
                                        inc ( closed );
                                        List [closed] . x := cx;
                                        List [closed] . y := cy;
                                        end;
                        end;
                end;
        inc ( open );
until open > closed ;
//writeln ( closed );
end;

begin
{assign ( input , 'p.in' );
reset ( input );
assign ( output , 'p.out' );
rewrite ( output );}

readln ( part );
for p := 1 to part do
        begin
        init;
        Kfs ;
        writeln ( 'Chessboard #' , p , ':' );
        if ans [tx] [ty] < maxint then
                writeln ( ans [tx] [ty] , ' steps.' )
                        else
                writeln ( 'Impossible.' );
        if p < part then writeln;
        end;
//close ( output );
end.
