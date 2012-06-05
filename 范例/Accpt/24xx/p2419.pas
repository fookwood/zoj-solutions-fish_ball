PROGRAM p2319;

TYPE
        PosType=record
                x,y             :Longint;
        end;

VAR
        n                       :Longint;
        line                    :array[1..50001]of PosType;
        ball                    :array[0..50001]of Longint;

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

line[n+1]:=line[1];
line[1]:=line[num_miny];
line[num_miny]:=line[n+1];
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
if (left<i-1) then Sort(left,i-1);
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

PROCEDURE Main;
var
        i,j,k                   :Longint;
        ans,first,second        :Extended;

        Function area(var a,b,c:Longint):Extended;
        begin
        area:=abs(
        (line[a].x-line[b].x) * (line[c].y-line[b].y)
                                -(line[a].y-line[b].y) * (line[c].x-line[b].x));

        end;

begin

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


ans:=-1;
first:=0;

k:=0;
for i:=1 to ball[0] - 2 do
        begin
        dec(k,200);
        for j:=i+1 to ball[0] - 1 do
                begin
                if (k<=j) then k:=j+1;
                first:=area(ball[i],ball[j],ball[k]);
                if first>ans then ans:=first;

                while (k+1<=ball[0]) do
                        begin
                        second:=area(ball[i],ball[j],ball[k+1]);
                        if second<first then break;
                        inc(k);
                        first:=second;
                        if first>ans then ans:=first;
                        end;
                end;
        end;

ans:=ans / 2;
writeln(ans:0:2);
end;

BEGIN
readln(n);
while (n>0) do
        begin
        Readin;
        Main;
        readln(n);
        end;
END.