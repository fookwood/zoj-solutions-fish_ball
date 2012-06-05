PROGRAM p1081;

CONST
        small=1e-9;

TYPE
        node=record
                x,y                     :Extended;

        end;

VAR
        n,m,step,Statu  :Integer;
        goal            :Node;
        point           :array[1..101]of Node;


PROCEDURE Readin;
var
        i               :Integer;
begin
inc(step);
read(n);
if n=0 then halt;
readln(m);
for i:=1 to n do
        with point[i] do readln(x,y);
point[n+1]:=point[1];
end;

FUNCTION Cross(p,q:Integer):Boolean;
var
        ax                  :Extended;
begin
cross:=false;

if abs(point[p].y-point[q].y)<small then
        begin
        if (abs(point[p].y-goal.y)<small)and(goal.x+small>point[p].x)and(goal.x-small<point[q].x) then statu:=1;
        if (abs(point[p].y-goal.y)<small)and(goal.x+small>point[q].x)and(goal.x-small<point[p].x) then statu:=1;
        exit;
        end;

if not ((point[p].x>goal.x-small)or(point[q].x>goal.x-small)) then exit;

if (point[p].y-goal.y) * (point[q].y-goal.y) > 0 then exit;

if (abs(point[p].y-goal.y)<small) then
        begin
        if abs(point[p].x-goal.x)<small then statu:=1;
        if point[p].x<goal.x-small then exit;
        if (point[p].y<point[q].y)and(point[p].x>goal.y-small) then cross:=true;
        exit;
        end;

if (abs(point[q].y-goal.y)<small) then
        begin
        if (abs(point[q].x-goal.x)<small) then statu:=1;
        if point[q].x<goal.x-small then exit;
        if (point[p].y>point[q].y)and(point[q].x>goal.y-small) then cross:=true;
        exit;
        end;

ax:=point[p].x+(goal.y-point[p].y)/(point[q].y-point[p].y) * (point[q].x-point[p].x);

if abs(ax-goal.x)<small then
        begin
        Statu:=1;
        exit;
        end;

if ax<goal.x-small then exit;

Cross:=true;
end;

PROCEDURE CheckGoal;
var
        i,total         :Integer;
begin
total:=0;
for i:=1 to n do
        if statu=0 then
                begin
                if Cross(i,i+1) then inc(total);
                end else break;

if odd(total) then statu:=1;
end;

PROCEDURE Main;
var
        i               :Integer;
begin
if step>1 then writeln;
writeln('Problem ',step,':');
for i:=1 to m do
        begin
        with goal do readln(x,y);
        Statu:=0;
        CheckGoal;
        if Statu=1 then writeln('Within')
                else writeln('Outside');
        end;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
step:=0;
while true do
        begin
        Readin;
        Main;
        end;
END.
