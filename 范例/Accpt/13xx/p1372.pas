PROGRAM P1372;

VAR
        n,m                             :Integer;
        dis                             :array[1..50,1..50]of Longint;

PROCEDURE Prim;
var
        min,ans                         :Longint;
        i,j,k                           :Integer;
       // closet                          :array[1..50]of Integer;
        mincost                         :array[1..50]of Longint;

begin
ans:=0;
for i:=1 to n do mincost[i]:=dis[1,i];
mincost[1]:=-1;
for i:=2 to n do
        begin
        min:=maxlongint;
        for j:=1 to n do
                if (mincost[j]>0)and(mincost[j]<min) then
                        begin
                        min:=mincost[j];
                        k:=j;
                        end;
        inc(ans,min);
        for j:=1 to n do
                if (mincost[j]>0)and(dis[k,j]<mincost[j]) then
                        mincost[j]:=dis[k,j];
        mincost[k]:=-1;
        end;
writeln(ans);
end;

PROCEDURE Readin;
var
        i,j,a,b,temp                    :Integer;
begin
for i:=1 to n do
        for j:=1 to n do dis[i,j]:=maxint;
for i:=1 to m do
        begin
        readln(a,b,temp);
        if (dis[b,a]>temp) then
                begin
                dis[b,a]:=temp;
                dis[a,b]:=dis[b,a];
                end;
        end;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
read(n);
while (n<>0) do
        begin
        readln(m);
        Readin;
        Prim;
        read(n);
        end;
END.