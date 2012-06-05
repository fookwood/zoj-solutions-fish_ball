PROGRAM p1245;

CONST
	maxn=100;

TYPE
	Graph=array[1..maxn,1..2*maxn+10]of Char;
	AnsType=array[-23..maxn+100,-12..2*maxn+100]of Integer;

VAR
	n,step				:Integer;
	g				:Graph;
	ans				:AnsType;

PROCEDURE Readin;
var
	i,j				:Integer;
begin
for i:=1 to n do
begin
for j:=1 to n* 2 -i do read(g[i,j]);
readln;
end;
end;

PROCEDURE Main;
var
	answer,i,j,min,k		:Integer;
begin
answer:=0;
fillchar(ans,sizeof(ans),0);

for i:=1 to n do
for j:=i to 2*n-i do
begin
if (g[i,j]='#') then ans[i,j]:=0
	else
if g[i,j]='-' then
begin
min:=maxint div 2;
for k:=j-1 to j+1 do
	if ans[i-1,k]<min then min:=ans[i-1,k];
ans[i,j]:=min+1;
if (ans[i,j]>answer)and((j-i+1) mod 2=1) then answer:=ans[i,j];
end;
end;

fillchar(ans,sizeof(ans),0);
for i:=n downto 1 do
for j:=i to 2*n-i do
begin
if (g[i,j]='#') then ans[i,j]:=0
	else
if g[i,j]='-' then
begin
min:=maxint div 2;
for k:=j-1 to j+1 do
	if ans[i+1,k]<min then min:=ans[i+1,k];
ans[i,j]:=min+1;
if (ans[i,j]>answer)and((j-i+1) mod 2=0) then answer:=ans[i,j];
end;
end;
writeln('Triangle #',step);
writeln('The largest triangle area is ',sqr(answer),'.');
writeln;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(n);
step:=0;
while (n<>0) do
begin
inc(step);
Readin;
Main;
readln(n);
end;
END.