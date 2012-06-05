PROGRAM P1010;

CONST
        inf='p1010.in';

TYPE
        point  =record
                x,y:real;
                end;

VAR
        f       :text;
        n       :integer;
        i       :integer;
        step    :integer;
        area    :real;
        p       :array[1..1001]of point;

FUNCTION multiply(a,b,c,d:real):real;

begin
if a*d-b*c>0 then multiply:=1 else
if a*d-b*c=0 then multiply:=0 else multiply:=-1;
end;

FUNCTION cross(x1,y1,x2,y2:point):boolean;
var
        p                       :real;
begin
cross:=true;
p:=multiply(x1.x-x2.x,x1.y-x2.y,y1.x-x2.x,y1.y-x2.y);
p:=multiply(x1.x-y2.x,x1.y-y2.y,y1.x-y2.x,y1.y-y2.y) * p;
if p>0 then
        begin
        cross:=false;
        exit;
        end;

p:=multiply(x2.x-x1.x,x2.y-x1.y,y2.x-x1.x,y2.y-x1.y);
p:=multiply(x2.x-y1.x,x2.y-y1.y,y2.x-y1.x,y2.y-y1.y) * p;
if p>0 then
        begin
        cross:=false;
        exit;
        end;

end;


FUNCTION check:boolean;
var
        i,j     :integer;
begin
area:=0;
for I:=1 to n do
        for j:=i+2 to n do
                if not ((i=1)and(j=n)) then
                if cross(p[i],p[i+1],p[j],p[j+1]) then
                begin
                check:=false;
                exit;
                end;
for I:=1 to n do
        area:=area+(p[i].x*p[i+1].y-p[i].y*p[i+1].x)/2;
check:=true;
end;

BEGIN
step:=0;
readln(n);
while n<>0 do
        begin
        inc(step);
        for I:=1 to n do
        readln(p[i].x,p[i].y);
        p[n+1]:=p[1];
        write('Figure ',step,': ');
        if check and (abs(area)<>0.00) then write(abs(area):0:2)
                else write('Impossible');
        writeln(' ');
        readln(n);
        if n<>0 then writeln;
        end;
END.
