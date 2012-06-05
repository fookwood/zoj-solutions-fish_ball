// algorithm    :Dp
// time         :2005/04/11


PROGRAM p1438;

CONST
        maxn=10;
        stoporder='END';
        change  :array[1..6,1..3]of Integer=
        ((1,0,0),(-1,0,0),(0,1,0),(0,-1,0),(0,0,1),(0,0,-1));

TYPE
        Node=record
                x,y,z           :Integer;
        end;

VAR
        n                       :Integer;
        map                     :array[1..maxn,1..maxn,1..maxn]of Char;
        minway                  :array[1..maxn,1..maxn,1..maxn]of Integer;
        line                    :array[1..maxn*maxn*maxn]of Node;
        start,finish            :Node;


PROCEDURE Readin;
var
        order                   :String;
        code,i,j,k              :Integer;
begin
readln(order);
if order=stoporder then halt;
delete(order,1,pos(' ',order));
Val(order,n,code);
for k:=1 to n do
        for j:=1 to n do
                begin
                for i:=1 to n do
                        begin
                        read(map[i][j][k]);
                        minway[i][j][k]:=maxint;
                        end;
                readln;
                end;
with start do readln(x,y,z);
with start do
        begin
        inc(x);
        inc(y);
        inc(z);
        end;
with finish do
        begin
        readln(x,y,z);
        inc(x);
        inc(y);
        inc(z);
        end;
readln;
end;

FUNCTION check(var a,b:Node):Boolean;
begin
if (a.x=b.x) and (a.y=b.y) and (a.z=b.z) then check:=true
        else check:=false;
end;

PROCEDURE Bfs;
var
        a,b,c                   :Integer;
        s,t,i                   :Integer;
begin
s:=1;
t:=1;
line[1]:=start;
minway[start.x][start.y][start.z]:=0;
if check(start,finish) then exit;
repeat
        for i:=1 to 6 do
                begin
                with line[s] do
                        begin
                        a:=x+change[i][1];
                        b:=y+change[i][2];
                        c:=z+change[i][3];
                        end;
                if (a<1) or (a>n) or (b<1) or (b>n) or (c<1) or (c>n) then continue;
                if map[a][b][c]='X' then continue;
                if minway[a][b][c]>minway[line[s].x][line[s].y][line[s].z]+1 then
                        begin
                        inc(t);
                        with line[t] do
                                begin
                                x:=a;
                                y:=b;
                                z:=c;
                                end;
                        minway[a][b][c]:=minway[line[s].x][line[s].y][line[s].z]+1;
                        if check(finish,line[t]) then exit;
                        end;
                end;
        inc(s);
until s>t;
end;

PROCEDURE WriteOut;
begin
with finish do
        begin
        if minway[x][y][z]<maxint then
                writeln(n,' ',minway[x][y][z])
                        else
                writeln('NO ROUTE');
        end;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
while not eof do
        begin
        Readin;
        Bfs;
        WriteOut;
        end;
END.