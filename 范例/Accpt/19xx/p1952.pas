PROGRAM P1952;

CONST
	maxn=200;

TYPE
dic=array[1..maxn]of String[80];

VAR
	data			:Dic;
	total			:Integer;
	n,l,step		:Longint;
	start,goal		:Integer;
	dis			:array[1..maxn,1..maxn]of Longint;

PROCEDURE init;
var
	i,j			:Integer;
begin
total:=0;
for i:=1 to n do for j:=1 to n do dis[i,j]:=-1;
end;

FUNCTION Find(s:String):Integer;
var
i				:Integer;
begin
for i:=1 to total do
if data[i]=s then
begin
find:=i;
exit;
end;
inc(total);
data[total]:=s;
find:=total;
end;

PROCEDURE Readin;
var
	s,t			:string;
	code,a,b		:Integer;
	i			:Integer;
begin
for i:=1 to l do
begin
readln(s);
t:=copy(s,1,pos(' ',s)-1);
a:=find(t);
delete(s,1,pos(' ',s));
t:=copy(s,1,pos(' ',s)-1);
b:=find(t);
delete(s,1,pos(' ',s));
val(s,dis[a,b],code);
dis[b,a]:=dis[a,b];
end;
readln(s);
t:=copy(s,1,pos(' ',s)-1);
start:=find(t);
delete(s,1,pos(' ',s));
goal:=find(s);
end;

PROCEDURE Main;
var
	maxway				:array[1..maxn]of Integer;
	cover				:array[1..maxn]of Boolean;
	k,i,min,j			:Integer;
begin

for i:=1 to n do
maxway[i]:=dis[start,i];
fillchar(cover,sizeof(cover),0);
cover[start]:=true;
repeat
min:=-1;
for i:=1 to n do
if not cover[i] and (maxway[i]>min) then
begin
min:=maxway[i];
k:=i;
end;
if (min=-1) then break;
cover[k]:=true;
for i:=1 to n do
if not cover[i] then
begin
if dis[k,i]>maxway[k] then min:=maxway[k] else min:=dis[k,i];
if min>maxway[i] then maxway[i]:=min;
end;
if k=goal then break;
until false;

writeln('Scenario #',step);
if maxway[goal]=-1 then write(0) else write(maxway[goal]);
writeln(' tons');
writeln;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
step:=0;
readln(n,l);
while (n<>0)or(l<>0) do
begin
inc(step);
init;
readin;
Main;
readln(n,l);
end;
END.
