PROGRAM p1586;


CONST
        maxn =1000;

VAR
        n,i,j                           :Integer;
        cost                            :array[1..maxn]of Integer;
        dis                             :array[1..maxn,1..maxn]of Longint;

PROCEDURE Prim;
var
        i,j                             :Integer;
        mincost                         :array[1..maxn]of Longint;
        puss                            :array[1..maxn]of Integer;
        min,p                           :Longint;
        ans                             :Longint;
begin
ans:=0;
for i:=1 to n do
        begin
        mincost[i]:=dis[1,i];
        puss[i]:=1;
        end;
for i:=2 to n do
        begin
        min:=mincost[i];
        p:=i;
        for j:=2 to n do
                if mincost[j]<min then
                        begin
                        min:=mincost[j];
                        p:=j;
                        end;
        inc(ans,dis[puss[p],p]);
        mincost[p]:=maxLongint;
        for j:=2 to n do
                if (mincost[j]<>maxLongint)and(dis[p,j]<mincost[j]) then
                        begin
                        mincost[j]:=dis[p,j];
                        puss[j]:=p;
                        end;
        end;
writeln(ans);
end;


PROCEDURE Readin;
var
        i,j                             :Integer;
begin
readln(n);
for I:=1 to n do read(cost[i]);
readln;
for i:=1 to n do
        begin
        for j:=1 to n do
                begin
                read(dis[i,j]);
                dis[i,j]:=dis[i,j]+cost[i]+cost[j];
                end;
        readln;
        end;
end;

BEGIN
readln(i);
for j:=1 to i do
        begin
        Readin;
        Prim;
        end;
END.