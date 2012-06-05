PROGRAM p1938;

VAR
        a,b                                     :Longint;

PROCEDURE Main;
var
        i                                       :Longint;
        ans                                     :Int64;
begin
ans:=1;
if a-b<b then b:=a-b;
for i:=1 to b do ans:=ans * (a-i+1 ) div i;
writeln(ans);
end;

BEGIN
readln(a,b);
while (a<>0) or (b<>0) do
        begin
        Main;
        readln(a,b);
        end;
END.