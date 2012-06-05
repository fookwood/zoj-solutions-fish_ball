PROGRAM p1889;

VAR
        n       :Integer;

FUNCTION ans:longint;
var
        i       :longint;
        yu,shang       :longint;
begin
i:=1;
yu:=1;
while yu<>0 do
        begin
        inc(i);
        yu:=(yu*10+1) mod n;
        end;
ans:=i;
end;

BEGIN
while not eof do
        begin
        readln(n);
        if n=0 then writeln('0') else if n=1 then writeln('1') else
        writeln(ans);
        end;
END.