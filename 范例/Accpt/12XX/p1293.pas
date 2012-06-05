PROGRAM p1293;

VAR
        step                                    :Integer;
        n                               :Longint;

BEGIN
step:=0;
readln(n);
while n<>0 do
        begin
        inc(step);
        {n:=round(n/2);
        n:=round(n*1.5);
        }
        n:=round(n*0.75);
        if frac(n/62/30000)=0 then n:=trunc(n/62/30000)
                else n:=trunc(n/62/30000)+1;
        writeln('File #',step);
        writeln('John needs ',n,' floppies.');
        writeln;
        readln(n);
        end;
END.
