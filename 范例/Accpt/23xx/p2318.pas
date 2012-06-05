PROGRAM p2318;

CONST
        small=1e-8;

TYPE
        node=record
                x,y,r                   :Extended;
        end;

VAR
        n,part,statu,p  :Integer;
        start,finish    :Integer;
        ship            :Node;
        point           :array[1..300]of Node;
        whether         :array[1..300,1..300]of Boolean;
        Dones,prev      :array[1..300]of Boolean;
        station,pos     :array[1..300]of Integer;


PROCEDURE Readin;
var
        i               :Integer;
begin
readln(n);
for i:=1 to n do with point[i] do readln(x,y,r);
with ship do readln(x,y,r);
end;

PROCEDURE MakeWhether;
var
        d               :Extended;
        i,j             :Integer;
begin
for i:=1 to n do
        begin
        whether[i][i]:=false;
        for j:=i+1 to n do
                begin
                d:=sqrt(sqr(point[i].x-point[j].x)+sqr(point[i].y-point[j].y));
                if ship.r*2+point[i].r+point[j].r>d+small then whether[i][j]:=true
                        else whether[i][j]:=false;
                whether[j][i]:=whether[i][j];
                end;
        end;
end;

FUNCTION Cross(p,q:Integer):Boolean;
var
        px,py,min,max            :Extended;
begin
cross:=false;
px:=ship.x;
py:=ship.y;
if (abs(point[p].y-point[q].y)<small) then exit;
if not ((point[p].x+small>px) or (point[q].x+small>px)) then exit;
if (abs(point[p].y-py)<small) or (abs(point[q].y-py)<small) then
        begin
        if abs(point[p].y-py)<small then
                begin
                if point[p].y>point[q].y then cross:=true
                        else cross:=false;
                end else
                begin
                if point[q].y>point[p].y then cross:=true
                        else cross:=false;
                end;
        exit;
        end;

if (point[p].y-py)*(point[q].y-py)>=0 then exit;
px:=point[p].x+(py-point[p].y)*(point[q].x-point[p].x)/(point[q].y-point[p].y);
if px<ship.x+small then  exit;
cross:=true;
end;

FUNCTION Check:boolean;
var
        i,total                 :Integer;
begin
total:=0;
for i:=start to finish-1 do
        if cross(station[i],station[i+1]) then inc(total);
check:=odd(total);
end;

PROCEDURE Search(dep,p:Integer);
var
        i,j                     :Integer;
begin
for i:=1 to n do
        if whether[p][i] then
        begin
        if prev[i] then
                begin
                start:=pos[i];
                finish:=dep;
                station[dep]:=i;
                if (finish-start>2) and check then
                        begin
                        Statu:=1;
                        exit;
                        end;
                end else
        if not dones[i] then
                begin
                dones[i]:=true;
                station[dep]:=i;
                pos[i]:=dep;
                prev[i]:=true;
                Search(dep+1,i);
                prev[i]:=false;
                end;
        if statu>0 then exit;
        end;
end;

PROCEDURE Main;
var
        i                       :Integer;
begin
Statu:=0;
fillchar(dones,sizeof(dones),0);
fillchar(prev,sizeof(prev),0);
for i:=1 to n do
        if (not dones[i] and (statu=0)) then
                begin
                dones[i]:=true;
                prev[i]:=true;
                station[1]:=i;
                pos[i]:=1;
                search(2,i);
                end;
if statu=0 then writeln('YES')
        else writeln('NO');
end;

BEGIN
readln(part);
for p:=part downto 1 do
        begin
        Readin;
        MakeWhether;
        Main;
        if p>1 then writeln;
        end;
END.
