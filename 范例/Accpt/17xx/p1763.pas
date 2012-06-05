PROGRAM p1763;

VAR
        a,b     :real;


BEGIN
readln(b);
while b<>999 do
        begin
        a:=b;
        readln(b);
        if b<>999 then writeln(b-a:0:2);
        end;
writeln('End of Output');
END.