PROGRAM p1954;

CONST
        max=100000;

VAR
        n                       :Longint;
        x,y                     :array[1..max]of Longint;

PROCEDURE MakePos;
var
        i,j                     :Longint;
        p,c                     :Longint;
begin
p:=1;
c:=0;

x[1]:=0;
y[1]:=0;
while true do
        begin
        inc(c);

        for i:=0 downto -c do
                begin
                inc(p);
                x[p]:=i;
                y[p]:=c;

                if p>=max then exit;
                end;


        for i:=c-1 downto 1 do
                begin
                inc(p);
                x[p]:=-c;
                y[p]:=i;
                if p>=max then exit;
                end;



        for i:=-c to -1 do
                begin
                inc(p);
                x[p]:=i;
                y[p]:=-c-i;
                if p>=max then exit;
                end;



        for i:=0 to c do
                begin
                inc(p);
                x[p]:=i;
                y[p]:=-c;
                if p>=max then exit;
                end;

        for i:=-c+1 to 1 do
                begin
                inc(p);
                x[p]:=c;
                y[p]:=i;
                if p>=max then exit;
                end;


        for i:=c-1 downto 1 do
                begin
                inc(p);
                x[p]:=i;
                y[p]:=c+1-i;
                if p>=max then exit;
                end;


        end;
end;

BEGIN
MakePos;
while not eof do
        begin
        Readln(n);
        writeln(x[n],' ',y[n]);
        end;
END.