PROGRAM P1383;

VAR
        k       :integer;
        n       :longint;
        j       :integer;
        num     :array[1..500]of longint;

PROCEDURE solve;
var     l       :integer;
        p       :Integer;
        i       :integer;
        save    :array[1..500]of longint;
begin

l:=0;
while n>0 do
begin
inc(l);
num[l]:=n mod 2;
n:=n div 2;
end;
p:=0;
for I:=1 to l do
if num[i]=1 then
begin
inc(p);
save[p]:=i-1;
end;
for I:=1 to p-1 do
write(save[i],' ');
writeln(save[p]);
end;

BEGIN
readln(k);
for j:=1 to k do
        begin
        readln(n);
        solve;
        end;
END.