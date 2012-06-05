PROGRAM P1037;

VAR
        k       :integer;
        i       :integer;
        a,b     :Integer;
        ans     :real;

BEGIN
readln(k);
for I:=1 to k do
        begin
        readln(a,b);
        if (a mod 2=0)or (b mod 2=0) then ans:=a*b else ans:=a*b+0.414;
        writeln('Scenario #',i,':');writeln(ans:0:2);
        writeln;
        end;
END.



