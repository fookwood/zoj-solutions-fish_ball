{
        算法 ： 搜索 + 剪枝优化
        
}
program p2206;

{$APPTYPE CONSOLE}

const
        maxsize         = 1000;
        maxask          = 10;
        maxdie          = 6;

type    
        Topt    = array[0..1 , 0..maxsize] of int64;
        Tbase   = array[1..maxask] of int64;
        Tdown   = array[1..50 , 1..maxask] of int64;
        TLimit  = array[1..maxask] of int64;
        Tcho    = array[1..maxdie] of int64;

var
        n       : Longint;
        r       : Longint;
        find    : Boolean;
        max     : Longint;
        opt     : Topt;
        v , c   : Tbase;
        down    : Tdown;
        Limit   : TLimit;
        cho     : Tcho;
        Leave   : Tbase;

procedure init;
var     i , j   : Longint;
        k , m   : Longint;
        a , b   : Longint;
        t , l   : Longint;
begin
fillchar ( opt , sizeof ( opt ) , 0 ); a := 0; b := 1;
opt [a] [0] := 1; max := 0;
for i := 1 to n do
        begin
        for j := 0 to max do opt [b] [j] := 0;
        read ( l ); m := 0;
        for j := 1 to l do
                begin
                read ( t ); if t > m then m := t;
                for k := t to max + t do
                        if opt [b] [k] < $7fffffffffffffff - opt [a] [k - t] then inc ( opt [b] [k] , opt [a] [k - t] );
                end;
        readln;
        inc ( max , m );
        a := 1 - a;
        b := 1 - b;
        end;

read ( r , n );
for i := 1 to n do read ( v [i] , c [i] ); readln;
fillchar ( Limit , sizeof ( Limit ) , 0 );

for i := 1 to 50 do
        for j := 1 to n do
                begin
                if ( v [j] >= i ) then down [i] [j] := opt [a] [v [j] - i]
                        else down [i] [j] := 0;
                if down [i] [j] > Limit [j] then Limit [j] := down [i] [j];
                end;
end;

procedure search ( dep , start : Longint );
var     i , j   : Longint;
        zero    : Boolean;
        flag    : Boolean;
begin
zero := true;
for i := 1 to n do
        begin
        if ( Limit [i] * ( r - dep + 1 ) < Leave [i] ) then exit;
        if Leave [i] <> 0 then zero := false;
        end;

if ( dep = r + 1 ) and ( zero ) then
        begin
        find := true;
        exit;
        end;

for i := start to 50 do
        begin
        cho [dep] := i; flag := true;
        for j := 1 to n do
                begin
                dec ( Leave [j] , down [i] [j] );
                if ( Leave [j] < 0 ) then flag := false;
                end;
        if flag then search ( dep + 1 , i );
        
        if find then exit;
        
        for j := 1 to n do
                inc ( Leave [j] , down [i] [j] );
        end;
end;

procedure main;
var     i       : Longint;
begin

// 剪枝 1 ：采用每种最大的策略仍不能满足要求
for i := 1 to n do if ( v [i] > max + 50 ) then
        begin
        writeln ( 'Impossible' );
        exit;
        end;

find := false;
Leave := c;
search ( 1 , 1 );
if not find then writeln ( 'Impossible' )
        else begin
        write ( 'Final die face values are' );
        for i := 1 to r do write ( ' ' , cho [i] );
        writeln;
        end;
        
end;

begin
readln ( n );
while ( n <> 0 ) do
        begin
        init;
        main;
        readln ( n );
        end;
end.
