{$I-,R-,Q-}
// A Dynimic Programming program
PROGRAM p1880;

VAR
        n,i,j                   :Longint;
        total , max             :Longint;
        num                     :array[1..100]of Longint;
        whether                 :array[0..100,0..22500]of Boolean;

PROCEDURE Main;
var
         i , j , k              : Longint;
begin
for k := 1 to n do
        begin
        for i := ( n + 1 ) div 2 downto 1 do
                for j := max downto num [i] do
                        if not whether [i] [j]  and whether [i - 1] [j - num [k]] then whether [i] [j] := true;
        end;

for i:= max downto 0 do
        if whether [( n + 1 ) div 2 ] [i] or whether [ n div 2 ] [i] then break;

writeln ( i,' ',total -i );
end;

BEGIN
while not eof do
        begin
        fillchar(whether,sizeof(whether),0);
        whether [0] [0] :=true;

        total:=0;
        readln(n);
        for i:=1 to n do
                begin
                readln(num[i]);
                inc(total,num[i]);
                end;

        max := total div 2;

        Main;
        end;
END.