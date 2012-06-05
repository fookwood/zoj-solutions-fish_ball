PROGRAM p1284;

VAR
        n       :longint;


FUNCTION check(m:longint):boolean;
var
        i       :longint;
        sum     :longint;
begin
sum:=1;
for i:=2 to trunc(sqrt(m)) do
        if m mod i=0 then
                begin
                sum:=sum+i;
                sum:=sum+(m div i);
                end;
if trunc(sqrt(m))=sqrt(m) then dec(sum,trunc(sqrt(m)));
if sum>m then
        begin
        check:=false;
        writeln(m:5,'  ABUNDANT');
        end else
if sum<m then
        begin
        check:=false;
        writeln(m:5,'  DEFICIENT');
        end else check:=true;

end;

BEGIN
read(n);
writeln('PERFECTION OUTPUT');
while n<>0 do
        begin
        if check(n) then writeln(n:5,'  PERFECT');
        read(n);
        end;
writeln('END OF OUTPUT');
END.
