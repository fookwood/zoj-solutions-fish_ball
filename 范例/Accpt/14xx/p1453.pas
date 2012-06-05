PROGRAM p1453;

TYPE
        PosType=record
                x,y             :Longint;
        end;

VAR
        n,step                       :Longint;
        line                    :array[1..40000]of PosType;
        ball                    :array[0..40000]of Longint;


PROCEDURE Change(var a,b:PosType);
var
        temp                    :PosType;
begin
temp:=a;
a:=b;
b:=temp;
end;

PROCEDURE Readin;
var
        min,i,num_miny          :Longint;
begin
min:=9999999;
for i:=1 to n do
        with line[i] do
                begin
                readln(x,y);
                if y<min then
                        begin
                        min:=y;
                        num_miny:=i;
                        end;
                end;
Change(line[1],line[num_miny]);
for i:=2 to n do
        with line[i] do
                begin
                x:=x-line[1].x;
                y:=y-line[1].y;
                end;
with line[1] do
        begin
        x:=0;
        y:=0;
        end;
end;

PROCEDURE Sort(left,right:Longint);
var
        mid,i,j                         :Longint;
        key,temp                        :PosType;

        Function compare(var a,b:PosType):Longint;
        begin
        compare:=a.y*b.x-a.x*b.y;
        end;

begin
key:=line[left];
i:=left-1; j:=right+1;
repeat
        repeat dec(j); until compare(line[j],key)<=0;
        repeat inc(i); until compare(line[i],key)>=0;
        if (i<j) then
                begin
                temp:=line[i];
                line[i]:=line[j];
                line[j]:=temp;
                end else break;
until false;
if (j+1<right) then Sort(j+1,right);
if (j>left) then Sort(left,j);
end;

FUNCTION Check(v:Longint):Boolean;
var
        a,b                     :PosType;
        mul                     :Longint;
begin
with a do
        begin
        x:=line[ball[ball[0]-1]].x-line[ball[ball[0]]].x;
        y:=line[ball[ball[0]-1]].y-line[ball[ball[0]]].y;
        end;
with b do
        begin
        x:=line[v].x-line[ball[ball[0]]].x;
        y:=line[v].y-line[ball[ball[0]]].y;
        end;

if a.x*b.y-b.x*a.y>0 then Check:=true
        else Check:=false;
end;

FUNCTION Dis(a,b:Longint):Extended;
begin
dis:=sqrt(sqr(line[a].x-line[b].x)+sqr(line[a].y-line[b].y));
end;

PROCEDURE Main;
var
        i,j,k                   :Longint;
        ans,area                :Extended;

begin
if n=1 then
        begin
        writeln('0.00');
        exit;
        end;

Sort(2,n);

ball[0]:=2;
ball[1]:=1;
ball[2]:=2;

for i:=3 to n do
        begin
        while check(i) do
                dec(ball[0]);
        inc(ball[0]);
        ball[ball[0]]:=i;
        end;


ans:=dis(ball[1],ball[ball[0]]);

for i:=1 to ball[0]-1 do
        ans:=ans+dis(ball[i],ball[i+1]);
{i:=1;
for i:=1 to ball[0] do
       for j:=i+1 to ball[0] do
                for k:=j+1 to ball[0] do
                        begin
                        area:=(line[ball[j]].x-line[ball[i]].x) * (line[ball[k]].y-line[ball[i]].y)
                                -(line[ball[j]].y-line[ball[i]].y) * (line[ball[k]].x-line[ball[i]].x);
                        area:=abs(area);
                        if area>ans then ans:=area;
                        end;
ans:=ans/2;  }
writeln(ans:0:2);
end;

BEGIN
assign(output,'p.out');
rewrite(output);
assign(input,'p.in');
reset(input);
readln(n);
step:=0;
while (n>0) do
        begin
        inc(step);
        Readin;
        Main;
        readln(n);
        end;
close(output);
END.
