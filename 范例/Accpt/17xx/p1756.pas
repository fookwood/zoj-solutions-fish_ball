PROGRAM p1756;

TYPE
	Node=record
	a,b			:Integer;
	end;

VAR
	total			:Integer;
	data			:array[1..576]of Node;
	x,y			:Integer;

PROCEDURE Readin;
begin
total:=0;
while true do
begin
readln(x,y);
if (x=-1)and(y=-1) then halt;
if (x=0)and(y=0) then break;
inc(total);
data[total].a:=x;
data[total].b:=y;
end;
end;

PROCEDURE Sort;
var
	i,j			:Integer;
	temp			:Node;
begin
for i:=1 to total-1 do
for J:=i+1 to total do
if (data[i].a>data[j].a)or((data[i].a=data[j].a)and(data[i].b>data[j].b)) then
begin
temp:=data[i];
data[i]:=data[j];
data[j]:=temp;
end;
end;

PROCEDURE Main;
var
	i,j,ans,t,have	:Integer;
	reach			:array[1..576]of Boolean;
begin
ans:=0;
have:=0;
fillchar(reach,sizeof(reach),0);
if total<>0 then
repeat
i:=0;j:=0;
inc(ans);
for t:=1 to total do
if not reach[t] and (data[t].a>=i) and (data[t].b>=j) then
begin
inc(have);
reach[t]:=true;
i:=data[t].a;
j:=data[t].b;
end;
until have=total;
writeln(ans);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
while true do
begin
readIn;
Sort;
Main;
end;
END.
