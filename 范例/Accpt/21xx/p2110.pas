PROGRAM p2110;

CONST
        change                  :array[1..4,1..2]of Integer=
        ((0,1),(0,-1),(1,0),(-1,0));

TYPE
        Position=record
                x,y                     :Integer;
        end;

VAR
        warm                    :Integer;
        n,m,t,i,j,now           :Integer;
        map                     :array[1..6,1..6]of Char;
        visit                   :array[1..6,1..6]of Boolean;
        ans                     :Boolean;
        s,d                     :Position;

PROCEDURE Search(x,y:Integer);
var
        i,p,q                   :Integer;
begin
if ans then exit;
if (now=t)and(map[x,y]='D') then
        begin
        ans:=true;
        exit;
        end;
if now>t then exit;
for i:=1 to 4 do
        begin
        p:=x+change[i,1];
        q:=y+change[i,2];
        if (p>n)or(p<1)or(q>m)or(q<1) then continue;
        if (not visit[p,q]) and (map[p,q]<>'X') then
                begin
                visit[p,q]:=true;
                inc(now);
                Search(p,q);
                dec(now);
                visit[p,q]:=false;
                end;
        end;
end;

BEGIN
readln(n,m,t);
while (n<>0)or(m<>0)or(t<>0) do
        begin
        fillchar(map,sizeof(map),0);
        fillchar(visit,sizeof(visit),0);
        warm:=0;
        for i:=1 to n do
                begin
                for j:=1 to m do
                        begin
                        read(map[i,j]);
                        if map[i,j]='S' then
                                begin
                                s.x:=i;
                                s.y:=j;
                                end;
                        if map[i,j]='D' then
                                begin
                                d.x:=i;
                                d.y:=j;
                                end;
                        if map[i,j]='X' then inc(warm);
                        end;
                readln;
                end;
        ans:=false;
        now:=0;
        visit[s.x,s.y]:=true;
        if (odd(abs(s.x-d.x)+abs(s.y-d.y)+t))or(t>=m*n-warm) then
                writeln('NO') else
                begin
        if not ans then Search(s.x,s.y);
        if ans then writeln('YES') else writeln('NO');
                end;
        readln(n,m,t);
        end;
END.
