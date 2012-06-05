PROGRAM p1871;

VAR
        n,m     :int64;
        puss    :int64;

FUNCTION ans:int64;
var
        single  :int64;
        leave   :int64;
        copy    :int64;
begin
puss:=m-n;
single:=trunc((-1+sqrt(1+4*puss))/2);
leave:=puss-(1+single)*single;
copy:=2*single;
if leave>single then
        begin
        inc(copy);
        inc(single);
        leave:=leave-single;
        end;
while leave>0 do
        begin
        leave:=leave-single;
        inc(copy);
        end;
ans:=copy;
end;


BEGIN
while not eof do
        begin
        readln(n,m);
        writeln(ans);
        end;
END.