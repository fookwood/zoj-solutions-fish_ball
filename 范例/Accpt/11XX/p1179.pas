PROGRAM p1179;

TYPE
        Node=record
                name            :Char;
                x,y             :Integer;
        end;

VAR
        n,step,i                :Integer;
        data                    :array[1..26]of Node;

PROCEDURE Sort;
var
	i,j				:Integer;
	temp				:Node;
begin
for i:=1 to n-1 do
for j:=i+1 to n do
if data[i].name>data[j].name then
begin
temp:=data[i];
data[i]:=data[j];
data[j]:=temp;
end;
end;

PROCEDURE Main;
var
	i,j,p,q,total			:Integer;
begin
total:=0;
write('Point set ',step,':');
for i:=1 to n do
for j:=1 to n do
if (i<>j) and (data[j].y=data[i].y)and(data[j].x>data[i].x) then
for p:=1 to n do
if (p<>i)and(p<>j) and (data[p].x=data[j].x) and (data[p].y<data[j].y) then
for q:=1 to n do
if (q<>i)and(q<>j)and(q<>p) and (data[q].y=data[p].y)and(data[q].x=data[i].x) then
begin
if total=0 then writeln;
inc(total);
write(' ',data[i].name,data[j].name,data[p].name,data[q].name);
if total mod 10=0 then writeln;
end;
if total=0 then writeln(' No rectangles') else
if total mod 10<>0 then writeln;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
step:=0;
readln(n);
while (n<>0) do
begin
inc(step);
for i:=1 to n do
begin
read(data[i].name);
readln(data[i].x,data[i].y);
end;
Sort;
Main;
readln(n);
end;
END.
