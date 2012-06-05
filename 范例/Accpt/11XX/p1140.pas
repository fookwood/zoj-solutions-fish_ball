PROGRAM p1140;

VAR
	total,j			:Integer;
	g				:array[1..100,1..300]of Boolean;
	cover				:array[1..300]of Boolean;
	n,p,i,t,k,a			:Integer;
	l				:array[1..300]of Integer;


FUNCTION Find(v:Integer):Boolean;
var
	i,t				:Integer;
begin
find:=true;
for i:=1 to n do
if cover[i] and g[v,i] then
begin
t:=l[i];
l[i]:=v;
cover[i]:=false;
if (t=0) or (find(t)) then exit;
l[i]:=t;
end;
find:=false;
end;

PROCEDURE Main;
var
	i				:Integer;
begin
for i:=1 to p do
begin
fillchar(cover,sizeof(cover),1);
if not find(i) then
begin
writeln('NO');
exit;
end;
end;
writeln('YES');
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(total);
for j:=1 to total do
begin
readln(p,n);
fillchar(g,sizeof(g),0);
fillchar(l,sizeof(l),0);
for i:=1 to p do
begin
read(t);
for k:=1 to t do
begin
read(a);
g[i,a]:=true;
end;
end;
Main;
end;
END.
