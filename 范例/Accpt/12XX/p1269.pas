PROGRAM p1269;

VAR
        n       :longint;

FUNCTION check(dep,p,leave:longint):boolean;
begin
if dep=p+1 then
        begin
        if (leave mod p=0) then
                begin
                check:=true;
                exit;
                end;
        end;
if (leave-1) mod p<>0 then
        begin
        check:=false;
        exit;
        end;
check:=check(dep+1,p,leave-1-leave div p);
end;


PROCEDURE main;
var
        i       :longint;

begin
for I:=n-1 downto 2 do
        if (n-1) mod i=0 then
        if check(1,i,n) then
                begin
                writeln(n,' coconuts, ',i,' people and 1 monkey');
                exit;
                end;
writeln(n,' coconuts, no solution');
end;


BEGIN
readln(n);
while N<>-1 do
        begin
        main;
        readln(n);
        end;
END.