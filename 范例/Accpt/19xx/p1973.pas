PROGRAM p1973;

TYPE
        PosType=record
        x,y                     :Extended;
        end;

VAR
        n,p,i                   :Longint;
        data                    :array[1..1001]of PosType;

BEGIN
assign(input,'p.in');
reset(input);
while not eof do
        begin
        read(n);
        for i:=1 to n do read(data[i].x,data[i].y);
        readln;
        data[n+1]:=data[1];
        write(n);
        for i:=1 to n do write(' ',(data[i].x+data[i+1].x)/2:0:6,' ',(data[i].y+data[i+1].y)/2:0:6);
        writeln;
        end;
END.