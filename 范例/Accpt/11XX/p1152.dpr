program p1152;

{$APPTYPE CONSOLE}
var
        data    :array[1..100,1..100]of longint;
        part    :longint;
        n,m     :longint;
        ans     :longint;
        step    :integer;
        team    :longint;
        i,j     :integer;

PROCEDURE first;
var
        i,j     :integer;
begin
for i:=1 to 98 do
        for j:=i+1 to 99 do    data[i,j]:=(sqr(i)+sqr(j)) mod (i*j);
end;

PROCEDURE  check;
var
        a,b     :integer;
        p       :real;
begin
for a:=1 to n-2 do
        begin
        for b:=a+1 to n-1 do
                if (data[a,b]+m) mod (a*b)=0 then inc(ans);
        end;
end;

begin
first;
readln(part);
readln;
for team:=1 to part do
begin
readln(n,m);
step:=0;
while (n<>0)or(m<>0) do
        begin
        inc(step);
        ans:=0;
        check;
        writeln('Case ',step,': ',ans);
        readln(n,m);
        end;
if team<>part then
        begin
        writeln;
        readln;
        end;
end;
end.

