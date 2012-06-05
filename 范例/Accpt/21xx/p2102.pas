PROGRAM p2102;

TYPE
        circle=record
                x,y,r           :Real;
        end;

VAR
        n,i                     :Integer;
        x1,x2,y1,y2             :Real;
        data                    :array[1..1000]of Circle;


FUNCTION dis(a,b:Real;p:Integer):Real;
begin
dis:=sqrt(sqr(a-data[p].x)+sqr(b-data[p].y));
end;

FUNCTION check:Boolean;
var
        left,right                      :Boolean;
        x,y,a,b,c,s,h                   :Real;
        i                               :Integer;
begin
x:=(x1+x2)/2;y:=(y1+y2)/2;
for i:=1 to n do
        if dis(x,y,i)<=data[i].r then
                begin
                check:=true;
                exit;
                end;
left:=false;right:=false;
c:=sqrt(sqr(x1-x2)+sqr(y1-y2))/2;
for i:=1 to n do
        begin
        a:=dis(x1,y1,i);
        b:=dis(x,y,i);
        if (a<=data[i].r)or(b<=data[i].r) then
                begin
                left:=true;
                break;
                end;
        s:=(a+b+c)/2;
        if (2*sqrt(s*(s-a)*(s-b)*(s-c))/c<=data[i].r)and(sqr(a)+sqr(c)>sqr(b))and(sqr(b)+sqr(c)>sqr(a)) then
                begin
                left:=true;
                break;
                end;
        end;
for i:=1 to n do
        begin
        a:=dis(x2,y2,i);
        b:=dis(x,y,i);
        if (a<=data[i].r)or(b<=data[i].r) then
                begin
                right:=true;
                break;
                end;
        s:=(a+b+c)/2;
        if (2*sqrt(s*(s-a)*(s-b)*(s-c))/c<=data[i].r)and(sqr(a)+sqr(c)>sqr(b))and(sqr(b)+sqr(c)>sqr(a)) then
                begin
                right:=true;
                break;
                end;
        end;
check:=left and right;
end;


BEGIN
readln(n);
while n<>0 do
        begin
        for i:=1 to n do read(data[i].x,data[i].y,data[i].r);
        readln(x1,y1,x2,y2);
        if Check  then writeln('STAY') else writeln('FALL');
        readln(n);
        end;
END.