PROGRAM p1854;

TYPE
	Node=record
	name,party			:String[80];
	end;

VAR
	n,i,t,j			:Integer;
	s				:String[80];	
	ans				:array[1..20]of Longint;
	data				:array[1..20]of Node;
	max,count			:Longint;


BEGIN
//assign(input,'p.in');
//reset(input);
while not eof do
begin
fillchar(ans,sizeof(ans),0);
readln(n);
for i:=1 to n do
begin
readln(data[i].name);
readln(data[i].party);
end;
readln(t);
for i:=1 to t do
begin
readln(s);
for j:=1 to n do if data[j].name=s then break;
if data[j].name=s then inc(ans[j]);
end;
max:=-1;
for i:=1 to n do
begin
if ans[i]=max then inc(count);
if ans[i]>max then
begin
max:=ans[i];
count:=1;
j:=i;
end;
end;
if (count>1)or(n=0) then writeln('tie') else
writeln(data[j].party);
end;
END.
