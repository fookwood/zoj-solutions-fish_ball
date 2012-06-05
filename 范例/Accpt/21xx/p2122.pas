PROGRAM p2122;

VAR
        s,x,y,dx,dy                                             :Int64;
        step                                                    :Longint;
        get                                                     :Boolean;
BEGIN
readln(s,x,y,dx,dy);
while (s<>0)or(x<>0)or(y<>0)or(dx<>0)or(dy<>0) do
        begin
        step:=0;
        if (x mod s=0) or (y mod s=0) or not odd(x div s + y div s) then
                repeat
                inc(step);
                x:=x+dx;
                y:=y+dy;
                if (x mod s<>0)and(y mod s<>0) and odd(x div s+y div s) then  break;
                until step=30000;
        if step=30000 then
                writeln('The flea cannot escape from black squares.') else
        writeln('After ',step,' jumps the flea lands at (',x,', ',y,').');

        readln(s,x,y,dx,dy);
        end;
END.