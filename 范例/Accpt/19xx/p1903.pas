PROGRAM p1903;

VAR
        n,m,a,b,i,j,     total                  :Longint;
        temp                                    :Int64;
        sum                                     :Int64;
        dis                                     :array[1..15,1..15]of  Int64;
        degree,graph,order                      :array[1..15]of Longint;
        min                                     :array[0..32768]of Int64;

PROCEDURE Main;
var
        i,j,k                                   :Longint;
begin
for k:=1 to n do
        for i:=1 to n do
                for j:=1 to n do
                        if (i<>j)and(dis[i,k]+dis[k,j]<dis[i,j]) then
                                begin
                                dis[i,j]:=dis[i,k]+dis[k,j];
                                dis[j,i]:=dis[i,j];
                                end;

total:=0;
for I:=1 to n do if odd(degree[i]) then
        begin
        inc(total);
        graph[total]:=i;
        end;

if total=0 then
        begin
        writeln(sum);
        exit;
        end;

for i:=1 to order[total+1]-1 do min[i]:=maxint;

min[0]:=0;
for i:=1 to order[total+1]-1 do
        begin
        for j:=1 to total do
                if (order[j] and i=order[j]) then
                for k:=1 to total do
                if (j<>k)and (order[k] and i=order[k]) then
                        if dis[graph[j],graph[k]]+min[i and not order[k] and not order[j]]<min[i] then
                                min[i]:=dis[graph[j],graph[k]]+min[i and not order[k] and not order[j]];
        end;
writeln(sum+min[order[total+1]-1]);
end;

PROCEDURE MakeOrder;
var
        i                                       :Integer;
begin
order[1]:=1;
for i:=2 to 15 do order[i]:=order[i-1]*2;
end;

BEGIN
assign(input,'p.in');
reset(input);
read(n);
MakeOrder;
while (n<>0) do
        begin
        readln(m);
        for I:=1 to n do for J:=1 to n do dis[i,j]:=9999999;
        fillchar(degree,sizeof(degree),0);
        sum:=0;
        for i:=1 to m do
                begin
                read(a,b,temp);
                inc(degree[a]);
                inc(degree[b]);
                if temp<dis[a,b] then
                        begin
                        dis[a,b]:=temp;
                        dis[b,a]:=temp;
                        end;
                inc(sum,temp);
                end;
        main;
        read(n);
        end;
END.