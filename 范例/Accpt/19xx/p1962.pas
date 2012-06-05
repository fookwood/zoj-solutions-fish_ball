PROGRAM p1962;

TYPE
	BigNum=array[0..110]of Integer;

CONST
	maxn=481;

VAR
	data				:array[1..maxn]of BigNum;
	a,b				:BigNum;

PROCEDURE MakeData;
var
	i,j,temp			:Integer;
begin
fillchar(data,sizeof(data),0);
data[1][0]:=1;
data[1][1]:=1;
data[2][0]:=1;
data[2][1]:=2;
for i:=3 to maxn do
begin
temp:=0;
for j:=1 to data[i-1][0] do
begin
temp:=data[i-1][j]+data[i-2][j]+temp;
data[i][j]:=temp mod 10;
temp:=temp div 10;
end;
data[i][0]:=data[i-1][0];
while (temp>0) do
begin
inc(data[i][0]);
data[i][data[i][0]]:=temp mod 10;
temp:=temp div 10;
end;
end;
end;

PROCEDURE Readin;
var
	ch				:Char;
begin
read(ch);
a[0]:=0;
while (ch<>' ') do
begin
inc(a[0]);
a[a[0]]:=ord(ch)-48;
read(ch);
end;
b[0]:=0;
repeat
read(ch);
inc(b[0]);
b[b[0]]:=ord(ch)-48;
until eoln ;
readln;
if (a[1]=0)and(b[1]=0) then halt;
end;

FUNCTION comp(var s,t:BigNum):Integer;
var
	l			:Integer;
begin
if s[0]<t[0] then comp:=-1 else
if s[0]>t[0] then comp:=1 else
begin
l:=s[0];
while (l>0)and(s[l]=t[l]) do dec(l);
if l=0 then comp:=0 else
if s[l]>t[l] then comp:=1 else
comp:=-1;
end;
end;

PROCEDURE change(var t:BigNum);
var
        i,temp                          :Integer;
begin
for i:=1 to t[0] div 2 do
begin
temp:=t[i];
t[i]:=t[t[0]-i+1];
t[t[0]-i+1]:=temp;
end;
end;

PROCEDURE Main;
var
	ansa,ansb			:Longint;
begin
change(a);
change(b);
ansa:=1;
while (comp(data[ansa],a)<0) do inc(ansa);
ansb:=ansa;
while (comp(data[ansb],b)<=0) do inc(ansb);
if ansb-ansa>0 then writeln(ansb-ansa)
        else writeln(0);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
MakeData;
while true do
begin
Readin;
Main;
end;
END.
