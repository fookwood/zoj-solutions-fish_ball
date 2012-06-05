PROGRAM p2081;

CONST
        Change:array[1..4,1..2]of Integer=
        ((1,0),(0,1),(0,-1),(-1,0));

TYPE
        node=record
                time,total,miss                         :Longint;
                end;

        Position=record
                x,y                                     :Integer;
                end;

VAR
        n,m                             :Integer;
        part,p                          :Integer;
        map                             :array[1..10,1..10]of Char;
        short                           :array[1..10,1..10]of Node;
        line                            :array[1..100]of Position;
        start,goal                      :Position;

PROCEDURE Readin;
var
        i,j                             :Integer;
begin
readln(n,m);
for i:=1 to n do
        begin
        for j:=1 to m do
                begin
                read(map[i,j]);
                if map[i,j]='S' then
                        begin
                        start.x:=i;
                        start.y:=j;
                        end;
                if map[i,j]='T' then
                        begin
                        goal.x:=i;
                        goal.y:=j;
                        map[i,j]:=' ';
                        end;
                with short[i,j] do
                        begin
                        total:=0;
                        miss:=0;
                        time:=-1;
                        end;
                end;
        readln;
        end;
end;

PROCEDURE Main;
var
        j,
        s,t                                             :Integer;
        p,q,i                                           :Integer;
begin
s:=1;
t:=1;
line[1]:=start;
with short[start.x,start.y] do
        begin
        time:=0;
        total:=1;
        miss:=0;
        end;

repeat
        for i:=1 to 4 do
                with short[line[s].x,line[s].y] do
                        begin
                        p:=line[s].x+change[i,1];
                        q:=line[s].y+change[i,2];
                        if (p>=1)and(p<=n)and(q>=1)and(q<=m) then
                        if (map[p,q]<>'#') then
                                begin
                                if short[p,q].time=time+1 then
                                        begin
                                        inc(short[p,q].total,total);
                                        inc(short[p,q].miss,miss);
                                        if map[p,q]='M' then short[p,q].miss:=short[p,q].total;
                                        end;
                                if short[p,q].time=-1 then
                                        begin
                                        inc(t);
                                        line[t].x:=p;
                                        line[t].y:=q;
                                        short[p,q].time:=time+1;
                                        short[p,q].total:=total;
                                        if map[p,q]='M' then short[p,q].miss:=total
                                                else short[p,q].miss:=miss;
                                        end;
                                end;
                        end;
        inc(s);
until s>t ;

with short[goal.x,goal.y] do
        begin
        if total=miss then
                writeln('Mission Impossible.') else
                writeln('The probability for the spy to get to the telegraph transmitter is ',(total-miss)*100/total:0:2,'%.');
        end;
end;

BEGIN
readln(part);
for p:=1 to part do
        begin
        Readin;
        writeln('Mission #',p,':');
        Main;
        if p<part then readln;
        writeln;
        end;
END.