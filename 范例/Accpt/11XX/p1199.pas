program p1199;

var
        part,p  :longint;
        x1,y1,r1:real;
        x2,y2,r2:real;
        a       :extended;
        x,y     :extended;

PROCEDURE main;
begin
if (sqr(r1-r2)>=sqr(x1-x2)+sqr(y1-y2))or(r1=r2) then
        writeln('Impossible.') else
        begin
        a:=r2/(r1-r2);
        x:=x2+((x2-x1)*a);
        y:=y2+((y2-y1)*a);
        writeln(x:0:2,' ',y:0:2);
        end;
end;


begin
readln(part);
for p:=1 to part do
        begin
        readln(x1,y1,r1);
        readln(x2,y2,r2);
        main;
        end;
end.

