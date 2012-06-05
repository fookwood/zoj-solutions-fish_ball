PROGRAM p1382;

VAR
        n       :longint;
        k       :integer;
        i       :Integer;
PROCEDURE ans;
var     j       :longint;
begin
j:=0;
while n mod 2=0 do
        begin
        inc(j);
        n:=n div 2;
        end;
writeln(n,' ',j);
end;

BEGIN
readln(k);
for I:=1 to k do
        begin
        readln(n);
        ans;
        end;
END.
