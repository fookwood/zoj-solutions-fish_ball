{
This program use I just learned xiantu
Time : 2005/05/18
}
PROGRAM p1015;

CONST
        maxn    = 1000;

TYPE
        Tgraph  = array[1..maxn,1..maxn]of Boolean;
        Tsearch = array[1..maxn]of Integer;
        Tnumbered = array[1..maxn] of Boolean;

VAR
        n , m                           :Integer;
        graph                           :Tgraph;
        search , deg , save             :Tsearch;
        numbered                        :Tnumbered;

FUNCTION Init : Boolean;
var
        i , a , b                       :Integer;
begin
readln ( n , m );
if ( n  = 0 )  then
        begin
        Init := false;
        end else
        begin
        Init := true;
        fillchar( graph ,sizeof ( graph ) , 0 ) ;

        for i:= 1 to m do
                begin
                readln ( a , b );
                graph [a] [b] := true;
                graph [b] [a] := true;
                end;
        end;
end;

PROCEDURE MakeSearch;
var
        i , j , k , max
                                :Integer;
begin
fillchar( deg , sizeof ( deg ) , 0 );
fillchar( numbered ,sizeof ( numbered ) , 0 );

for i:= n downto 1 do
        begin
        max := -1;
        for j:=1 to n do
                if not numbered [j] and ( deg [j] > max ) then
                        begin
                        k := j;
                        max := deg[j];
                        end;

        Search [i] := k;
        numbered [k] := true;
        for j:=1 to n do
                if not numbered [j] and graph [k] [j] then
                        inc( deg[j] );
        end;

//for i:=1 to n do write( search [i] ,' ' );
//writeln;
end;


FUNCTION Chordal : Boolean;
var
        i , j
                                :Integer;
begin
for i:=1 to n-1 do
        begin
        save [i] := 0;

        for j:=i+1 to n do
                if graph [ search [i] ] [ search [j] ] then
                        begin
                        save [i] := j;
                        break;
                        end;

        if save [i] > 0 then
                for j:=save [i] + 1 to n do
                        if graph [ search [i] ] [ search [j] ] and
                                not graph [ search [ save [i] ] ] [ search [j] ] then
                                        begin
                                        Chordal := false;
                                        exit;
                                        end;
        end;
Chordal := true;
end;

BEGIN
//assign(input , 'p.in');
//reset(input);
while Init do
        begin
        MakeSearch;
        if not Chordal then writeln ('Imperfect')
                else writeln ('Perfect');
        writeln;
        end;
END.
