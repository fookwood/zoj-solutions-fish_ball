  {$I+,Q+,R+,S-}

PROGRAM p2097;

const
        n       = 8;
        change  : array[1..4,1..2] of Integer =
        ((-1,0),(1,0),(0,-1),(0,1));

type
        Topt            = array[1..n ,1..n , 1..4]of Integer;
        Tmap            = array[1..n ,1..n]of Integer;

VAR
        map                     : Tmap;
        opt                     : Topt;
        sx , sy , tx , ty       : Integer;
        ans , i                 : Integer;

PROCEDURE Init;
var
        i , j , k               : Integer;
begin
for i := 1 to n do
        begin
        for j := 1 to n do
                begin
                read ( map [i] [j] );
                for k := 1 to 4 do
                        opt [i] [j] [k] := maxint;
                end;
        readln;
        end;
end;

PROCEDURE Search ( x , y , state : Integer );
var
        cx , cy , i , temp              : Integer;
begin
for i := 1 to 4 do
        begin
        cx := x + change [i] [1];
        cy := y + change [i] [2];

        if ( cx < 1 ) or ( cy < 1 ) or ( cx > n ) or ( cy > n ) then continue;

        temp := map [cx] [cy] * state;
        if temp + opt [x] [y] [state] >= opt [cx] [cy] [temp mod 4 + 1] then continue;
        opt [cx] [cy] [temp mod 4 + 1] := temp + opt [x] [y] [state];
        Search ( cx , cy , temp mod 4 + 1 );
        end;
end;

BEGIN
readln ( sx , sy , tx , ty );
while sx > 0 do
        begin
        Init ;

        opt [sx] [sy] [1] := 0;
        Search ( sx , sy , 1 );

        ans := maxInt;
        for i := 1 to 4 do
                if opt [tx] [ty] [i] < ans then ans := opt [tx] [ty] [i];
        writeln ( ans );

        readln ( sx , sy , tx , ty );
        end;
END.
