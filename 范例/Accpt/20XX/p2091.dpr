program p2091;

{$APPTYPE CONSOLE}
var
        num     :array[1..3000000]of longint;
        n       :longint;
        sum,best       :real;
        i       :longint;

begin
while not eof do
        begin
        readln(n);
        for I:=1 to n do read(num[i]);
        readln;
        sum:=0;
        best:=0;
        for i:=n downto 1 do
                begin
                sum:=sum+num[i];
                if sum/(n-i+1)>best then best:=sum/(n-i+1);
                end;
        writeln(best:0:6);
        end;


end.
 