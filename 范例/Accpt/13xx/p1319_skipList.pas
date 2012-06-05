// Accept
// Use SkipList
// Time 2005/06/11

{$MODE FPC}
{$R-,I-,Q-,S-}
program p1319;

const
        maxLevel        = 70;
        maxData         = 30000;
        maxLimit        = 90000;
        maxRandom       = 100000;
        RandomKey       = 8000;

type
        node            = record
                        Left , Right , Down , num , level       : Longint;
                        end;
        Tdata           = array[1..maxLimit ] of node;
        Tadd            = array[1..maxData ] of Longint;
        Tsave           = array[-1..maxLevel ] of Longint;

var
        part , p , n , m , r , K , Upest
                                        : Longint;
        add , ask                       : Tadd;
        data                            : Tdata;
        save , MaxLeft , MaxRight       : Tsave;

procedure init;
var
        i                               : Longint;
begin
K := 2; r := 1; Upest := 1;
with data [1] do begin Level := 0; Left := 0; Right := 2; Down := 0; num := - maxLongint; end;
with data [2] do begin Level := 0; Left := 1; Right := 0; Down := 0; num := maxLongint; end;
MaxLeft [0] := 1; MaxRight [0] := 2;

read ( n , m );
for i := 1 to n do read ( add [i] );
for i := 1 to m do read ( ask [i] );
end;

procedure SListInsert ( x : Longint );
var
        i , j , Max                     : Longint;
begin
i := Upest; Max := data [Upest] . Level;
while true do
        begin
        while ( data [data [i] . Right] . num <= x ) do i := data [i] . Right;
        save [data [i] . Level] := i;
        if data [i] . Level = 0 then break else i := data [i] . down;
        end;

j := 0;
repeat
        inc ( K );
        with data [K] do
                begin
                num := x;
                Left := save [j]; Right := data [save [j]] . Right;
                data [data [save [j]] . Right] . Left := K;
                data [save [j]] . Right := K;
                Down  := save [j - 1]; Level := j;
                end;
        if random ( maxRandom ) < RandomKey then inc ( j ) else break;
until ( j > Max );

if (j > Max) then
        begin
        inc ( K );
        with data [K] do
                begin
                num := - maxLongint; Left := 0; Right := K + 1;
                Down := MaxLeft [j - 1]; Level := Max + 1;
                MaxLeft [j] := K;
                end;
        Upest := K;
        inc ( K );
        with data [k] do
                begin
                num  := x; Left := K - 1; Right := K + 1;
                Down := save [j - 1]; Level := Max + 1;
                end;
        inc ( K );
        with data [k] do
                begin
                num  := maxLongint; Left := K - 1; Right := 0;
                Down := MaxRight [j - 1]; Level := Max + 1;
                MaxRight [j] := K;
                end;
        end;
if x < data [r] . num then r := data [r] . Left;
end;

procedure main;
var
        i , j                           : Longint;
begin
i := 1;
for j := 1 to m do
        begin
        while ( i <= ask [j] ) do
                begin
                SListInsert ( add [i] );
                inc ( i );
                end;
        r := data [r] . Right;
        writeln ( data [r] . num );
        end;
end;

begin
randomize;
readln ( part );
for p := 1 to part do
        begin
        init;
        main;
        if p < part then writeln;
        end;
end.