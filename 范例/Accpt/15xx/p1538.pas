PROGRAM p1538;

VAR
        n,i                     :Longint;
        num                     :array[0..61098]of Longint;
        ans                     :Longint;

BEGIN
while not eof do
        begin
        readln(n);
        for i:=0 to n-1 do read(num[i]);
        readln;
        ans:=0;
        for i:=1 to n do ans:=(ans+num[ans]) mod n;
        writeln(num[ans]);
        end;
END.