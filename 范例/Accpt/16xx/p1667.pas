PROGRAM p1667;

VAR
        up,down,left,right,front,back           :Integer;
        n,i                                     :Integer;
        s                                       :String;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(n);
while (n<>0) do
        begin
        up:=1;front:=2;left:=3;down:=6;back:=5;right:=4;
        for i:=1 to n do
                begin
                readln(s);
                if s='north' then
                        begin
                        front:=up;up:=back;back:=7-front;down:=7-up;
                        end else
                if s='south' then
                        begin
                        up:=front;front:=down;down:=7-up;back:=7-front;
                        end else
                if s='east' then
                        begin
                        up:=left;left:=down;down:=7-up;right:=7-left;
                        end else
                if s='west' then
                        begin
                        up:=right;right:=down;left:=7-right;down:=7-up;
                        end else
                        writeln('error');

                end;
        writeln(up);
        readln(n);
        end;
END.
