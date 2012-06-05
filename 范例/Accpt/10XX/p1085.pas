PROGRAM p1085;

VAR
        total                                   :Integer;
        n,a,b,g,i,p,q,t,ans                     :Integer;
        dis,first                               :array[0..300,0..300]of Integer;
        search                                  :array[1..300]of Integer;

FUNCTION Find(p:Integer):Boolean;
var
        i,j,k,min                               :Integer;
        mincost                                 :array[0..300]of Integer;
        team                                    :array[0..300]of Boolean;
begin
for i:=0 to n-1 do
        if (i<>p)and(dis[0,i]<maxint) then
                mincost[i]:=dis[0,i] else mincost[i]:=maxint;

fillchar(team,sizeof(team),0);
team[0]:=true;
mincost[0]:=0;
repeat
        min:=maxint;
        for i:=1 to n-1 do
                if (i<>p)and(mincost[i]<min)and(not team[i]) then
                        begin
                        min:=mincost[i];
                        k:=i;
                        end;
        if min<maxint then
                begin
                team[k]:=true;
                for i:=1 to n-1 do
                        if (i<>p)and(not team[i])and(dis[k,i]<>maxint)and(mincost[k]+dis[k,i]<mincost[i]) then
                                mincost[i]:=mincost[k]+dis[k,i];
                end else break;
until false;
if mincost[g]<maxint then find:=false else find:=true;
end;

PROCEDURE Main;
var
        i,j,k,temp                              :Integer;
begin

first:=dis;
for k:=1 to n-1 do
        for i:=1 to n-1 do
                for j:=1 to n-1 do
                        if (first[i,k]<>maxint)and(first[k,j]<>maxint)and(first[i,k]+first[k,j]<first[i,j]) then
                                first[i,j]:=first[i,k]+first[k,j];

first[0,g]:=maxint;

for i:=1 to n-1 do
        if (first[i,g]<maxint)and(dis[0,i]<>maxint)and(dis[0,i]+first[i,g]<first[0,g]) then
                first[0,g]:=dis[0,i]+first[i,g];


total:=0;
for i:=1 to n-1 do
        if (i<>g)and(first[i,g]<maxint) then
                begin
                inc(total);
                search[total]:=i;
                end;



for i:=1 to total-1 do
        for j:=i+1 to total do
                if first[search[i],g]>first[search[j],g] then
                        begin
                        temp:=search[i];
                        search[i]:=search[j];
                        search[j]:=temp;
                        end;


if first[0,g]=maxint then
        begin
        if total=0 then
                begin
                if g=n-1 then ans:=n-2 else ans:=n-1;
                end else ans:=search[1];
        exit;
        end;

for i:=1 to total do
        if find(search[i]) then
                begin
                ans:=search[i];
                exit;
                end;

ans:=0;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(t);
for i:=1 to t do
        begin
        readln;
        readln(n,g);
        for p:=0 to n-1 do
                for q:=0 to n-1 do dis[p,q]:=maxint;
        while (not eoln)and(not eof) do
                begin
                readln(a,b);
                dis[a,b]:=1;
                end;
        Main;
        writeln('Put guards in room ',ans,'.');
        if i<t then writeln;
        end;
END.