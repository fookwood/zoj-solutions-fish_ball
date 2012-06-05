PROGRAM p2325;

CONST
        small=1e-8;

TYPE
        Position1=record
                x1,x2,y                 :Extended;
        end;

        node=record
                x1,x2                   :Extended;
        end;

VAR
        part,total                      :Longint;
        cover                           :array[1..1000]of Node;
        house,prop,tree                 :Position1;

PROCEDURE Add;
var
        a,b,w                           :Extended;
begin
if (tree.y>house.y-small) or (tree.y<prop.y+small) then exit;

w:=(prop.y-house.y)/(tree.y-house.y);
a:=house.x2+w * (tree.x1-house.x2);
b:=house.x1+w * (tree.x2-house.x1);
if a<prop.x1 then a:=prop.x1;
if b>prop.x2 then b:=prop.x2;
if (a>prop.x2)or (b<prop.x1) then exit;
inc(total);
with cover[total] do
        begin
        x1:=a;
        x2:=b;
        end;
end;

PROCEDURE Readin;
var
        p                               :Longint;
begin
total:=0;
with house do
begin
readln(x1,x2,y);
if (abs(x1)<small)and(abs(x2)<small) and (abs(y)<small) then halt;
end;
with prop do readln(x1,x2,y);
readln(part);
for p:=1 to part do
        begin
        with tree do readln(x1,x2,y);
        Add;
        end;
end;

PROCEDURE Sort;
var
        i,j                             :Integer;
        temp                            :Node;
begin
for i:=1 to total-1 do
        for j:=i+1 to total do
                if cover[i].x1>cover[j].x1 then
                        begin
                        temp:=cover[i];
                        cover[i]:=cover[j];
                        cover[j]:=temp;
                        end;
end;

PROCEDURE Main;
var
        i                                       :Integer;
        start,last,max                          :Extended;
begin
sort;
max:=0;
start:=prop.x1;
last:=start;
for i:=1 to total do
        begin
        if cover[i].x1>last+small then
                begin
                if cover[i].x1-last>max then
                        max:=cover[i].x1-last;
                last:=cover[i].x2;
                end else
                begin
                if cover[i].x2>last then last:=cover[i].x2;
                end;
        end;
if prop.x2-last> max then max:=prop.x2-last;
if max<small then writeln('No View')
        else writeln(max:0:2);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
while true do
        begin
        Readin;
        Main;
        end;
END.