PROGRAM p2305;

VAR
        n,a,b                       :Integer;

FUNCTION change(v,p:Integer):Integer;
var
        sum,total               :Integer;
        num                     :array[1..4]of Integer;
begin
sum:=0;
total:=0;
while v>0 do
        begin
        inc(total);
        num[total]:=v mod p;
        inc(sum,num[total]);
        v:=v div p;
        end;
change:=sum;
end;

BEGIN
for n:=2292 to 9999 do
        begin
        a:=change(n,10);
        b:=change(n,12);
        if (a<>b) then continue;
        a:=change(n,16);
        if (a<>b) then continue;
        writeln(n);
        end;
END.