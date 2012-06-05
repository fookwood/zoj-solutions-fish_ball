PROGRAM p1649;

CONST
	maxn=200;
	change			:array[1..4,1..2]of Integer=
	((1,0),(0,1),(-1,0),(0,-1));

TYPE
	node=record
	a,b		:Integer;
	end;

VAR
map			:array[1..maxn,1..maxn]of Char;
minway			:array[1..maxn,1..maxn]of Integer;
w,h			:Integer;

PROCEDURE Readin;
var
i,j			:Integer;
begin
readln(h,w);
for i:=1 to h do
begin
for j:=1 to w do
read(map[i,j]);
readln;
end;
end;

PROCEDURE Search(x,y:Integer);
var
s,t,i,p,q 		:Integer;
line			:array[1..40000]of Node;
begin
with line[1] do
begin
a:=x;
b:=y;
end;
s:=1;
t:=1;
repeat
for i:=1 to 4 do
begin
p:=line[s].a+change[i,1];
q:=line[s].b+change[i,2];
if (p<1)or(p>h)or(q<1)or(q>w)or(map[p,q]='#') then continue;
if (map[p,q]='x') then
begin
if (minway[line[s].a,line[s].b]+2<minway[p,q]) then
begin
inc(t);
line[t].a:=p;
line[t].b:=q;
minway[p,q]:=minway[line[s].a,line[s].b]+2;
end;
end else
if minway[line[s].a,line[s].b]+1<minway[p,q] then
begin
inc(t);
line[t].a:=p;
line[t].b:=q;
minway[p,q]:=minway[line[s].a,line[s].b]+1;
end;
end;
inc(s);
until s>t;
end;

PROCEDURE main;
var
i,j,a,b,ansa,ansb	:Integer;
begin
for i:=1 to h do
for j:=1 to w do
minway[i,j]:=maxint;

for i:=1 to h do
for j:=1 to w do
if map[i,j]='r' then
begin
minway[i,j]:=0;
Search(i,j);
end else
if map[i,j]='a' then
begin
ansa:=i;
ansb:=j;
end;
if minway[ansa,ansb]<maxint then
	writeln(minway[ansa,ansb])
else writeln('Poor ANGEL has to stay in the prison all his life.');
end;

BEGIN
//assign(input,'p.in');
//reset(input);
while not eof do
begin
readin;
main;
end;
END.
