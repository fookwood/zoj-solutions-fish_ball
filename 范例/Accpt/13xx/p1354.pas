PROGRAM p1354;

CONST
        max     = 30;

TYPE
        Ta      = array[1..30,-1..30] of Integer;
        Tvec    = array[1..30] of Integer;

VAR
        part , p                : Integer;
        a                       : Ta;
        vec                     : Tvec;

PROCEDURE Init;
var
        i                       : Integer;
begin
fillchar ( a , sizeof ( a ) , 0 );
for i := 1 to max do
        begin
                                        a [i] [i]     := 1;
        if ( i mod 6 <> 1 ) then        a [i] [i - 1] := 1;
        if ( i mod 6 <> 0 ) then        a [i] [i + 1] := 1;
        if ( ( i - 1 ) div 6 <> 0) then a [i] [i - 6] := 1;
        if ( ( i - 1 ) div 6 <> 4) then a [i] [i + 6] := 1;
        end;

for i := 1 to max do
        begin
        read ( a [i] [0] );
        if i mod 6 = 0 then readln;
        end;

for i := 1 to max do vec [i] := i;
end;

PROCEDURE Solve;
var
        i , j , k , temp                : Integer;
begin

{for i := 1 to max do
        begin
        for j := 1 to max do write ( a [i] [j] );
        writeln;

        end;
writeln;}


for i := 1 to max do
        begin
        for j := i to max do
                if a [ vec[j] ] [i] = 1 then
                        begin
                        temp := vec [i];
                        vec [i] := vec [j];
                        vec [j] := temp;
                        break;
                        end;

        if a [ vec [i] ] [i] <> 1 then
                begin
                writeln ( 'answer are not single ');
                exit;
                end;

        for j := i + 1 to max do
                if a [ vec[j] ] [i] = 1 then
                        begin
                        for k := i to max do
                                a [ vec [j] ] [k] := abs ( a [ vec [j] ] [k] - a [ vec [i] ] [k] );
                        a [ vec [j] ] [0] := abs ( a [ vec [j] ] [0] - a [ vec [i] ] [0] );
                        end;

        {for j := 1 to max do
                begin
                for k := 1 to max do write ( a [vec[j]] [k] ,' ');
                writeln;
                end;
        writeln;}
        end;

{writeln ( 'here' );
for i := 1 to max do
        begin
        for j := 1 to max do write ( a [vec [i] ] [j] );
        writeln;
        end;
writeln;}

for i := max downto 1 do
        begin
        temp := a [vec [i]] [0];
        for j := i + 1 to max do temp := ( temp + a [ vec [j] ] [-1] * a [vec [i] ] [j]) mod 2;
        a [ vec [i] ] [-1] := temp;
        end;

{for i := 1 to max do
        begin
        for j := 1 to max do  write ( a [ vec [i] ] [j] ,' ' );
        writeln ( '       ' , a [vec [i] ] [0] ,' ',vec [i]);
        end;}

for i := 1 to max do
        begin
        write ( a [vec [i] ] [-1] );
        if i mod 6 = 0 then writeln else write (' ');
        end;
end;

BEGIN
{assign ( input , 'p.in' );
reset ( input );
assign (output,'p.out');
rewrite ( output);}

readln ( part );
for  p := 1 to part do
        begin
        writeln ( 'PUZZLE #', p);
        Init;
        Solve;
        end;
//close (output)
END.