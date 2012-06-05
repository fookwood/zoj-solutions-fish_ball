PROGRAM p1560;

TYPE
        Pointtype=record
                x,y,k           :Extended;
        end;

VAR
        part,p                  :Integer;
        a,b                     :PointType;

PROCEDURE Change(var a,b:PointType);
var
        temp                    :Pointtype;
begin
temp:=a;
a:=b;
b:=temp;
end;

PROCEDURE make(var t:PointType);
begin
if (t.k<=90) then t.k:=90-t.k
        else
if (t.k<=180) then t.k:=270-t.k
        else
if (t.k<=270) then t.k:=270-t.k
        else
        t.k:=450-t.k;
end;

PROCEDURE Out(x:Extended);
begin
if (x<0)and(abs(x)<0.000049) then write('0.0000')
        else write(round(x*10000)/10000:0:4);
end;

PROCEDURE Main;
var
        ans_x,ans_y             :Extended;
begin
//with a do writeln(x:0:0,' ',y:0:0,' ',k:0:0);
//with b do writeln(x:0:0,' ',y:0:0,' ',k:0:0);
make(a);
make(b);



a.k:=a.k/180*pi;
b.k:=b.k/180*pi;



if (a.k>=pi) then a.k:=a.k-pi;
if (b.k>=pi) then b.k:=b.k-pi;



if (abs(a.k-pi/2) > abs(b.k-pi/2)) then change(a,b);



if abs(a.k-pi/2)<0.00001 then
        begin

        ans_x:=a.x;
        ans_y:=sin(b.k)/cos(b.k) *(ans_x-b.x)+b.y;
        end else
        begin
        a.k:=sin(a.k)/cos(a.k);
        b.k:=sin(b.k)/cos(b.k);



        ans_x:=(b.y-a.y+a.x*a.k-b.x*b.k)/(a.k-b.k);
        ans_y:=ans_x * a.k - a.x * a.k + a.y;
        end;

out(ans_x);
write(' ');
out(ans_y);
writeln;
end;

BEGIN
assign(output,'p.out');
rewrite(output);
assign(input,'p.in');
reset(input);
readln(part);
for p:=1 to part do
        begin
        with a do readln(x,y,k);
        with b do readln(x,y,k);
        Main;
        end;
close(output);
END.