PROGRAM p2329;

TYPE
        node=record
                x,y                             :Integer;
        end;

VAR
        total                           :Integer;
        data                            :array[0..100000]of Node;
        step,n                          :Integer;
        num                             :array[0..1000]of Char;
        sum,sumb                        :array[0..1000]of Integer;

PROCEDURE Init;
begin
n:=0;
sum[0]:=0;
sumb[0]:=0;
while (not eoln) do
        begin
        inc(n);
        read(num[n]);
        if num[n]='a' then
                begin
                sum[n]:=sum[n-1]+1;
                sumb[n]:=sumb[n-1];
                end else
                begin
                sum[n]:=sum[n-1];
                sumb[n]:=sumb[n-1]+1;
                end;
        end;
readln;
end;

PROCEDURE Change(var a,b:Node);
var
        temp                                    :Node;
begin
temp:=a;
a:=b;
b:=temp;
end;

FUNCTION Find(left,right:Integer;key:Node):Integer;
var
        i,j                                     :Integer;
begin
i:=left-1;
j:=right+1;
while true do
        begin
        repeat dec(j) until (data[j].x<key.x)or((data[j].x=key.x)and(data[j].y<=key.y));
        repeat inc(i) until (data[i].x>key.x)or((data[i].x=key.x)and(data[i].y>=key.y));
        if (i<j) then Change(data[i],data[j]) else break;
        end;
Find:=j;
end;

PROCEDURE QuikeSort(left,right:Integer);
var
        mid                                     :Integer;
begin
mid:=Find(left,right,data[left]);
if mid>left then QuikeSort(left,mid);
if mid<right then QuikeSort(mid+1,right);
end;

PROCEDURE Main;
var
        i,j,left,right,tl,tr                     :Integer;
begin
writeln('AB Circle #',step,':');

//fillchar(whether,sizeof(whether),0);

i:=1;
j:=2;
total:=0;
while (i<=n) do
        begin
        while (j<=n)and (sum[j]-sum[i]<=sumb[n]-sumb[j]+sumb[i] ) do
                begin
                if (sum[j]-sum[i]=sumb[n]-sumb[j]+sumb[i]) then
                        begin
                        inc(total);
                        data[total].x:=i-1;
                        data[total].y:=j-1;
                        end;
                inc(j);
                end;
        inc(i);
        if j<=i then j:=i+1;
        end;

i:=1;
j:=2;
while (i<=n) do
        begin
        while (j<=n)and(sumb[j]-sumb[i]<=sum[n]-sum[j]+sum[i]) do
                begin
                if (sumb[j]-sumb[i]=sum[n]-sum[j]+sum[i]) then
                        begin
                        inc(total);
                        data[total].x:=i-1;
                        data[total].y:=j-1;
                        end;
                inc(j);
                end;
        inc(i);
        if j<=i then j:=i+1;
        end;

QuikeSort(1,total);

data[0].x:=-1;
for i:=1 to total do
        if (data[i].x<>data[i-1].x)or(data[i].y<>data[i-1].y) then
        writeln(data[i].x,',',data[i].y);


writeln;
end;

BEGIN
step:=0;
while not eof do
        begin
        inc(step);
        Init;
        Main;
        end;
END.
