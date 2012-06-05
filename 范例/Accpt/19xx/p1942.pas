PROGRAM p1942;

CONST
        max=1e10;
        small=1e-8;

TYPE
        Node=record
                x,y                     :Integer;
        end;

VAR
        data                            :array[1..200]of Node;
        dis                             :array[1..200,1..200]of Extended;
        n,i,step                        :Integer;

PROCEDURE MakeDis;
var
        i,j                             :Integer;
begin
for i:=1 to n do
        for j:=i to n do
                begin
                dis[i][j]:=sqrt(sqr(data[i].x-data[j].x)+sqr(data[i].y-data[j].y));
                dis[j][i]:=dis[i][j];
                end;
end;

PROCEDURE Main;
var
        i,j,k                           :Integer;
        min                             :Extended;
        mincost                         :array[1..200]of Extended;
        team                            :array[1..200]of Boolean;

begin
fillchar(team,sizeof(team),0);
for i:=1 to n do mincost[i]:=dis[1,i];
team[1]:=true;
repeat
        min:=max;
        k:=0;
        for i:=1 to n do
                if not team[i] and (mincost[i]<min) then
                        begin
                        min:=mincost[i];
                        k:=i;
                        end;
        if k=0 then break;
        team[k]:=true;
        for i:=1 to n do
                if not team[i] then
                        begin
                        if (mincost[k]>dis[k][i]-small) and (mincost[i]>mincost[k]) then
                                mincost[i]:=mincost[k];
                        if (mincost[k]<dis[k][i]+small) and (dis[k][i]<mincost[i]) then
                                mincost[i]:=dis[k][i];
                        end;
until false;
writeln('Scenario #',step);
writeln('Frog Distance = ',mincost[2]:0:3);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
step:=0;
readln(n);
while (n<>0) do
        begin
        inc(step);
        for i:=1 to n do readln(data[i].x,data[i].y);
        MakeDis;
        main;
        readln(n);
        writeln;
        end;
END.