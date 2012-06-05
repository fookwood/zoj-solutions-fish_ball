PROGRAM p2330;

CONST
        Small=1e-8;

VAR
        a,t,x                           :Extended;


FUNCTION Find(left,right:Extended):Extended;
var
        mid                             :Extended;
begin
mid:=(left+right) / 2;
if abs(ln(mid)-t*mid)<small then
        Find:=mid else
if ln(mid)<t*mid then
        Find:=FInd(left,mid) else
        Find:=Find(mid,right);
end;

PROCEDURE Main;
begin
t:=ln(a)/a;
x:=1/t;
        begin
        t:=Find(x,1e50);
        if t>a+small*50 then
        writeln(t:0:5) else writeln(-1);
        end;
end;

BEGIN
while not eof do
        begin
        readln(a);
        Main;
        end;
END.
