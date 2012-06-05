PROGRAM P1089;

VAR
        num     :array[1..15]of integer;
        n       :integer;
        i,j     :integer;
        temp    :integer;
        puss    :array[1..6]of integer;

PROCEDURE search(dep,reach:Integer);
var     i :integer;
begin

if dep=7 then
        begin
        for i:=1 to 5 do
        write(puss[i],' ');
        writeln(puss[6]);
        exit;
        end;
if reach>n then exit;
for i:=reach to n do
        begin
        puss[dep]:=num[i];
        search(dep+1,i+1);
        end;

end;

BEGIN
read(n);
while n<>0 do
        begin
        for i:=1 to n do read(num[i]);
        readln;
        for i:=1 to n-1 do
                for j:=i+1 to n do
                        if num[i]>num[j] then
                        begin
                        temp:=num[i];
                        num[i]:=num[j];
                        num[j]:=temp;
                        end;
        search(1,1);

        read(n);
        if n<>0 then writeln;
        end;
END.