PROGRAM P1045;

VAR
        n       :real;

FUNCTION ans:longint;
var
        sum     :real;
        i       :longint;
begin
sum:=0;
i:=1;
while sum<n do
        begin
        inc(i);
        sum:=sum+1/i;
        end;
ans:=i-1;
end;


BEGIN
readln(n);
while n<>0.00 do
        begin
        writeln(ans,' card(s)');
        readln(n);
        end;
END.