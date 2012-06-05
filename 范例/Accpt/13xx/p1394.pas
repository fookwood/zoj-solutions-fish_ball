PROGRAM p1394;

CONST
        pi=3.14159;

VAR
        s                       :String;
        x,y,z                   :Longint;
        leave                   :Extended;


BEGIN
//assign(input,'p.in');
//reset(input);
readln(s);
while (s<>'ENDOFINPUT') do
        begin
        readln(x,y,z);
        readln;
        y:= y * 5;

        if z>180 then z:=360-z;

        z:=z*2;

        leave:=y - pi*x*z/180;

        if leave>-0.0000001 then
                writeln('YES ',trunc(leave/5))
                        else
                writeln('NO ',y);
        readln(s);
        end;
END.