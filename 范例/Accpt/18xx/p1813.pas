PROGRAM p1813;

CONST
        pi=3.1415927;


VAR
        d       :real;
        num     :longint;
        time    :real;
        s,v     :real;
        step    :integer;

BEGIN
readln(d,num,time);
step:=0;
while num<>0 do
        begin
        inc(step);
        s:=d*pi*num/12/5280;
        v:=s*3600/time;
        writeln('Trip #',step,': ',s:0:2,' ',v:0:2);
        readln(d,num,time);
        end;
END.