PROGRAM p1484;

VAR
        n,i                     :Integer;
        num                     :array[0..5000]of Integer;

PROCEDURE Main;
var
        min,count,c             :Integer;
        i,j                     :Integer;
begin
count:=0;
for i:=0 to n-1 do
        for j:=i+1 to n-1 do
                if num[i]>num[j] then inc(count);
min:=count;
c:=count;
for i:=0 to n-1 do
        begin
        c:=(c - num[i] + n-1-num[i]);
        if c<min then min:=c;
        end;
writeln(min);
end;

BEGIN
while not eof do
        begin
        readln(n);
        for i:=0 to n-1 do read(num[i]);
        readln;
        Main;
        end;
END.