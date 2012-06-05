PROGRAM p1114;

TYPE
        node=record
                x,y                             :Longint;
        end;

VAR
        c,x1,x2,y1,y2,min                       :Extended;
        left,right                              :Node;


FUNCTION find(x,y:Real):Node;
var
        xd,yd                                   :Extended;
        k1,k2                                   :Longint;
begin
k1:=trunc((y-x/sqrt(3))/c+1e9)-1000000000;
k2:=trunc((y+x/sqrt(3))/c+1e9)-1000000000;

xd:=sqrt(3) * (k2-k1) * c / 2;
yd:=(k2+k1) * c / 2;
min:=sqr(x-xd)+sqr(y-yd);
find.x:=k1;
find.y:=k2;

xd:=sqrt(3) * (k2-k1) * c /2;
yd:=(k2+k1+2) * c / 2;
if sqr(x-xd)+sqr(y-yd)<min then
        begin
        min:=sqr(x-xd)+sqr(y-yd);
        find.x:=k1+1;
        find.y:=k2+1;
        end;

xd:=sqrt(3) * (k2+1-k1) * c / 2;
yd:=(k2+1+k1) * c / 2;
if sqr(x-xd)+sqr(y-yd)<min then
        begin
        min:=sqr(x-xd)+sqr(y-yd);
        find.x:=k1;
        find.y:=k2+1;
        end;

xd:=sqrt(3) * (k2-k1-1) * c / 2;
yd:=(k2+k1+1) * c / 2;
if sqr(x-xd)+sqr(y-yd)<min then
        begin
        miN:=sqr(x-xd)+sqr(y-yd);
        find.x:=k1+1;
        find.y:=k2;
        end;
min:=sqrt(min);
end;

PROCEDURE Main;
var
        ans                                     :Extended;
        a,b                                     :Node;
begin
ans:=0;
a:=find(x1,y1);
ans:=ans+min;
b:=find(x2,y2);
ans:=ans+min;
ans:=ans+c*(abs(a.x-b.x)+abs(a.y-b.y));
if (a.x=b.x)and(a.y=b.y) then ans:=sqrt(sqr(x1-x2)+sqr(y1-y2));
writeln(ans:0:3);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(c,x1,y1,x2,y2);
while (c<>0)or(x1<>0)or(y1<>0)or(y2<>0)or(x2<>0) do
        begin
        c:=c*sqrt(3);
        Main;
        readln(c,x1,y1,x2,y2);
        end;
END.
