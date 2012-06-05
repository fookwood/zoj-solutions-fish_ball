PROGRAM p1175;

VAR
	part,p				:Longint;
	total,t			        :Longint;
	data,ans			:array[1..100230]of Char;


PROCEDURE Readin;
var
	ch				:Char;
	l,i				:Longint;
begin
total:=0;
readln(l);
i:=0;
repeat
read(ch);
if ord(ch)<=13 then inc(i)
else
begin
inc(total);
data[total]:=ch;
end;
until i>=l;
end;

PROCEDURE Main;
var
        ch                              :Char;
	first				:Boolean;
	l,r,i                           :Longint;
begin
t:=0;
l:=1;
r:=total;
first:=true;
read(ch);
while (ch<>'#') do
begin
if ch='R' then first:=not first;
if (ch='G')and (l<=r) then
begin
if first then
begin
inc(t);
ans[t]:=data[l];
inc(l);
end else
begin
inc(t);
ans[t]:=data[r];
dec(r);
end;
end;
read(ch);
end;
while not eof and  eoln do readln;
for i:=1 to t do
        begin
        write(ans[i]);
        if i mod 80=0 then writeln;
        end;
if t mod 80<>0 then writeln;
end;

BEGIN
readln(part);
for p:=1 to part do
begin
readin;
Main;
if p<part then writeln;
end;
END.