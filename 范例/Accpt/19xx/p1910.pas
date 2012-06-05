PROGRAM p1910;

VAR
        n       :integer;
        part,p  :integer;
        ans     :longint;
        puss    :array[1..3]of integer;

PROCEDURE search(dep,from,leave:integer);
var
        i       :integer;
begin
if dep=3 then
        begin
        if leave*puss[1]+puss[2]*leave+puss[1]*puss[2]<ans then
                ans:=leave*puss[1]+leave*puss[2]+puss[1]*puss[2];
        exit;
        end;
for i:=from to trunc(sqrt(leave)) do
        if leave mod i=0 then
                begin
                puss[dep]:=i;
                search(dep+1,i,leave div i);
                end;
end;

BEGIN
readln(part);
for P:=1 to part do
        begin
        readln(n);
        ans:=maxlongint;
        search(1,1,n);
        writeln(2*ans);
        end;
END.