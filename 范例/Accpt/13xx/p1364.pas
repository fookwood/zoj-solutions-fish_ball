PROGRAM p1364;

VAR
        n,m,t,goal              :Integer;
        dis                     :array[0..201,0..201]of Integer;
        maxget,puss             :array[0..201]of Integer;

PROCEDURE Init;
var
        i,a,b,c                 :Integer;
begin
fillchar(dis,sizeof(dis),0);
for i:=1 to t do
        begin
        readln(a,b,c);
        inc(b);
        inc(c);
	if (b=1) or (c=1) then continue;
        dis[b,c+n]:=1;
        end;
for i:=1 to n do  dis[0,i]:=1;
for i:=n+1 to m+n  do dis[i,n+m+1]:=1;
end;

PROCEDURE Dij;
var
        i,j,min,max,k           :Integer;
        team                    :array[0..201]of Boolean;
begin
for i:=0 to goal do
        begin
        maxget[i]:=dis[0,i];
        puss[i]:=0;
        end;

fillchar(team,sizeof(team),0);
maxget[0]:=maxint div 2;

repeat
        max:=0;
        for i:=0 to goal-1 do
                if not team[i] and (maxget[i]>max) then
                        begin
                        max:=maxget[i];
                        k:=i;
                        end;
        if max<>0 then
                begin
                team[k]:=true;
                for i:=1 to goal do
                        if not team[i]  then
                                begin
                                if maxget[k]>dis[k,i] then min:=dis[k,i] else min:=maxget[k];
                                if min>maxget[i] then
                                        begin
                                        maxget[i]:=min;
                                        puss[i]:=k;
                                        end;
                                end;
                end else break;
        //if k=goal then break;
until false;
end;

{PROCEDURE Print;
var
        i,j                     :Integer;
begin
for i:=0 to goal do
        begin
        for j:=0 to goal do write(dis[i][j],' ');
        writeln;
        end;
end; }

PROCEDURE Main;
var
        i,j,ans                   :Integer;
begin

goal:=n+m+1;


{for i:=1 to goal do
        begin
        for j:=1 to goal do  write(dis[i,j],' ');
        writeln;
        end; }


dij;

while (maxget[goal]>0) do
        begin
        i:=goal;
        while (i<>0) do
                begin
                dec(dis[puss[i]][i],maxget[goal]);
                inc(dis[i][puss[i]],maxget[goal]);
                i:=puss[i];
                end;
        dij;
        end;

ans:=0;
for i:=1 to goal-1 do
        inc(ans,dis[goal][i]);
writeln(ans);
end;


BEGIN
//assign(input,'p.in');
//reset(input);
read(n);
while (n<>0) do
        begin
        readln(m,t);
        Init;
        Main;
        read(n);
        end;
END.
