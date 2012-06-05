PROGRAM p1431;

TYPE
	node=record
	name			:String;
	weight			:Longint;
	end;

const
	maxn=100;
	t='END';

VAR
	data				:array[1..maxn]of Node;
	n,i				:Integer;
	a,b				:Longint;
	s				:String;
	code				:Integer;

FUNCTION Find(left,right:Integer;key:Longint):Integer;
var
	i,j				:Integer;
	temp				:Node;
begin
i:=left-1;
j:=right+1;
repeat
repeat dec(j) until data[j].weight<=key;
repeat inc(i) until data[i].weight>=key;
if i<j then
begin
temp:=data[i];
data[i]:=data[j];
data[j]:=temp;
end else break;
until false;
find:=j;
end;

PROCEDURE Sort(left,right:Integer);
var
	mid				:Integer;
begin
mid:=find(left,right,data[left].weight);
if mid > left then Sort(left,mid);
if mid + 1<right then Sort(mid + 1,right);
end;

PROCEDURE Print;
var
	i				:Integer;
begin
for i:=n downto 1 do
	writeln(data[i].name);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
while (not eof) do
begin
readln(s);
readln(s);
n:=0;
while s<>t do
begin
inc(n);
data[n].name:=copy(s,1,pos(' ',s)-1);
delete(s,1,pos(' ',s));
val(copy(s,1,pos(' ',s)-1),a,code);
delete(s,1,pos(' ',s));
val(s,b,code);
data[n].weight:=b-a;
readln(s);
end;
sort(1,n);
print;
if not eof then writeln;
end;
END.
