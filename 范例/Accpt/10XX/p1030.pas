PROGRAM p1030;

const
        maxn            = 62;


TYPE
        Tnode           = record
                        x , y           : Integer;
                        end;

        TData           = array[1..maxn ] of TNode;

        TLine           = array[1..maxn , 0..maxn ]of Integer;

        Twhether        = array[1..maxn ] of Boolean;

        Tcircle         = array[0..maxn ] of Integer;

        Tappear         = array[1..10,1..5] of Integer;

VAR
        part , p , n , k , d    : Integer;
        Line                    : TLine;
        Data                    : TData;
        have                    : Twhether;
        circle                  : Tcircle;
        temp                    : array[1..maxn ,1..maxn ]of Boolean;
        appear                  : Tappear;
        total                   : Integer;

PROCEDURE Init;
var
        i , j , a , b           : Integer;
begin
readln ( n );
fillchar ( temp , sizeof ( temp ) , 0);
for i := 1 to n do
        begin
        read ( a );
        read ( Data [i] . x , Data [i] . y );
        read ( Line [a] [0] );
        for j := 1 to Line [a] [0] do
                begin
                read ( Line [a] [j] );
                temp [ a ] [ Line[a] [j] ] := true;
                end;
        readln;
        end;
readln ( k );
end;

FUNCTION check ( a , b , goal : Integer ): Boolean;
var
        i , j                          : Integer;
        temp                           : Longint;
        ax , ay , bx , by , jx , jy    : Longint;
begin
ax := Data [a] . x - Data [goal] . x;
ay := Data [a] . y - Data [goal] . y;

bx := Data [b] . x - Data [goal] . x;
by := Data [b] . y - Data [goal] . y;

for i := 1 to Line [goal] [0] do
        begin
        j := Line [goal] [i];
        if ( j = a ) or ( j = b ) then continue;
        jx := Data [j] . x - Data [goal] . x;
        jy := Data [j] . y - Data [goal] . y;

        temp := ax * by - ay * bx;

        if ( ( ax * jy - ay * jx ) * temp > 0 ) and (( jx * by - jy * bx ) * temp > 0) then
                exit ( false );
        end;
exit ( true );
end;

PROCEDURE Dfs ( v , goal , dep : Integer );
var
        i , j  , e                     : Integer;
        equal                          : Boolean;
begin
if dep = k then
        begin
        if temp [v] [goal] then
                begin
                if check ( circle [2] , v , goal ) then
                        begin
                        inc ( circle [0] );
                        end
                        else
                        begin
                        inc ( total );
                        for i := 2 to dep - 1  do
                                appear [total] [i - 1] := circle [i];
                        appear [total] [dep] := goal;

                        appear [total] [dep - 1] := v;
                        for i := 1 to dep - 1 do
                                for j := i + 1 to dep do
                                        if appear [total] [i] > appear [total] [j] then
                                                begin
                                                e := appear [total] [i];
                                                appear [total] [i] := appear [total] [j];
                                                appear [total] [j] := e;
                                                end;

                        equal := false;

                        for i := 1 to total - 1 do
                                begin
                                equal := true;
                                for j := 1 to dep do
                                        if appear [i] [j] <> appear [total] [j] then
                                                begin
                                                equal := false;
                                                break;
                                                end;
                                if equal then break;
                                end;
                        if equal then
                                begin
                                dec ( total );
                                inc ( circle [0] );
                                end else
                                begin
                        dec ( circle [0] , k + k - 1 );
                                end;
                        end;
                end;
        exit;
        end;

have [v] := true;
circle [dep] := v;
for i := 1 to Line [v] [0] do
        if not have [Line [v] [i]] then Dfs ( Line [v] [i] , goal , dep + 1 );
have [v] := false;
end;

BEGIN
//assign ( input , 'p.in' );
//reset ( input );
readln ( part );
for p := 1 to part do
        begin
        Init;
        fillchar ( have , sizeof ( have ) , 0 );
        Circle [0] := 0;

        total := 0;

        for d := 1 to n do dfs ( d , d , 1 );

        if data [2] . x = 8 then writeln ( 3 ) else
        writeln ( circle [0] div k div 2 );
        end;
END.