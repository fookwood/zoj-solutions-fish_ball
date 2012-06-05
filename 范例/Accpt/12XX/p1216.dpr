program p1216;

{$APPTYPE CONSOLE}
var
        ans     :array[1..99999]of real;
        n       :longint;

PROCEDURE makeans;
var
        i       :longint;
begin
ans[1]:=0.5;
for I:=2 to 99999 do
        ans[i]:=ans[i-1]+1/2/i;
end;

begin
makeans;
writeln('# Cards  Overhang');
while not eof do
        begin
        readln(n);
        writeln(n:5,'     ',ans[n]:0:3);
        end;
end.
 