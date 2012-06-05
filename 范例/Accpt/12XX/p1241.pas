PROGRAM P1241;

VAR
        a,b,c   :real;
        step    :integer;

BEGIN
readln(a,b,c);
step:=0;
while (a<>0)or(b<>0)or(c<>0) do
        begin
        inc(step);
        writeln('Triangle #',step);
        if a=-1 then
                begin
           if c>b then
           writeln('a = ',sqrt(c*c-b*b):0:3)    else writeln('Impossible.');
                end;
        if b=-1 then
                begin
           if c>a then
           writeln('b = ',sqrt(c*c-a*a):0:3)    else writeln('Impossible.');
                end;
        if c=-1 then writeln('c = ',sqrt(a*a+b*b):0:3);
        readln(a,b,c);
        writeln;
        end;
END.