PROGRAM p2379;

TYPE
        integer=longint;

CONST
        maxn=3000000;

VAR
	n,m			:Integer;
	num			:array[1..50]of Integer;
	com			:array[0..maxn]of Integer;

PROCEDURE readin;
var
	i			:Integer;
begin
readln(n,m);
if (n=0)and(m=0) then halt;
for i:=1 to n do readln(num[i]);
end;

PROCEDURE MakeCome;
var
	i,j			:Integer;
begin
fillchar(com,sizeof(com),0);
for i:=1 to n do
	for j:=0 to maxn div num[i] do
	inc(com[num[i] * j]);
end;

PROCEDURE Main;
var
	i,j,t			:Integer;
begin
MakeCome;
for i:=1 to m do
begin
readln(t);
j:=t;
while (com[j]<4) do dec(j);
write(j,' ');
j:=t;
while (com[j]<4) do inc(j);
writeln(j);
end;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
while true do
begin
Readin;
Main;
end;
END.