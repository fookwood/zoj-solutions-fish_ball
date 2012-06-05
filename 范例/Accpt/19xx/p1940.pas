PROGRAM p1940;

CONST
        maxn    =30;
        change  :array[1..6,1..3]of Integer=
        ((1,0,0),(-1,0,0),(0,1,0),(0,-1,0),(0,0,1),(0,0,-1));


TYPE
        Triple=record
        x,y,z                           :Integer;
        end;

VAR
        n,w,h                           :Integer;
        Start,Goal                      :Triple;
        map                             :array[1..maxn,1..maxn,1..maxn]of Char;
        minway                          :array[1..maxn,1..maxn,1..maxn]of Longint;
        line                            :array[1..maxn * maxn * maxn]of Triple;

PROCEDURE Readin;
var
        i,j,k                           :Integer;
begin
for i:=1 to n do
        begin
        for j:=1 to w do
                begin
                for k:=1 to h do
                        begin
                        read(map[i][j][k]);
                        if map[i][j][k]='S' then
                                with start do
                                        begin
                                        x:=i;
                                        y:=j;
                                        z:=k;
                                        end;
                        if map[i][j][k]='E' then
                                with goal do
                                        begin
                                        x:=i;
                                        y:=j;
                                        z:=k;
                                        end;
                        end;
                readln;
                end;
        readln;
        end;
end;

PROCEDURE main;
var
        open,closed,i,p,q,r             :Integer;
begin
open:=1;
closed:=1;
for p:=1 to n do for q:=1 to w do for r:=1 to h do minway[p][q][r]:=maxlongint;
line[1]:=start;
with line[1] do minway[x][y][z]:=0;

repeat
        for i:=1 to 6 do
                with line[open] do
                        begin
                        p:=x + change[i][1];
                        q:=y + change[i][2];
                        r:=z + change[i][3];
                        if (p<1) or (q<1) or (r<1) or (p>n) or (q>w) or (r>h) or (map[p][q][r]='#') then continue;

                        if minway[x][y][z]+1<minway[p][q][r] then
                                begin
                                minway[p][q][r]:=minway[x][y][z]+1;
                                inc(closed);
                                line[closed].x:=p;
                                line[closed].y:=q;
                                line[closed].z:=r;
                                if (line[closed].x=goal.x)
                                        and (line[closed].y=goal.y)
                                        and (line[closed].z=goal.z)
                                        then exit;
                                end;
                        end;
        inc(open);
until open>closed;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(n,w,h);
while (n<>0) do
        begin
        Readin;
        Main;
        with goal do
                if minway[x][y][z]<maxlongint then
                        writeln('Escaped in ',minway[x][y][z],' minute(s).')
                        else
                        writeln('Trapped!');
        readln(n,w,h);
        end;
END.