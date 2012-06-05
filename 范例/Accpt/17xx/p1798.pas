PROGRAM p1798;

TYPE
	graph=array[0..10,0..10]of Boolean;

VAR
	n,step				:Integer;
	g				:Graph;
	reach				:array[1..10]of Boolean;


PROCEDURE Readin;
var
	i,a,b				:Integer;
begin
fillchar(g,sizeof(g),0);
for i:=1 to n do
begin
while not eoln do
begin
read(a);
g[i,a]:=true;
g[a,i]:=true;
end;
readln;
end;
end;

FUNCTION Search(dep,p:Integer):Boolean;
var
	i				:Integer;
begin
if dep=n then
begin
if g[0,p] then
	Search:=true else Search:=false;
exit;
end;
search:=true;
for i:=1 to n do
if g[p,i] and not reach[i] then
begin
reach[i]:=true;
if Search(dep+1,i) then exit;;
reach[i]:=false;
end;
Search:=false;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
step:=0;
readln(n);
while (n<>0) do
begin
inc(step);
readin;
fillchar(reach,sizeof(reach),0);
if Search(0,0) then
	writeln('Case ',step,': Granny can make the circuit.')
	else
writeln('Case ',step,': Granny can not make the circuit.');
readln(n);
end;
END.
