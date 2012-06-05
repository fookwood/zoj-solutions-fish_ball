PROGRAM p2172;

VAR
        step                    :Integer;
        n,i                     :Integer;
        data                    :array[1..15]of String;



BEGIN
step:=0;
readln(n);
while n<>0 do
        begin
        inc(step);
        writeln('SET ',step);
        for i:=1 to n do readln(data[i]);
        for i:=1 to n do
                if i<=(n+1) div 2 then
                begin
                writeln(data[2*i-1]);
                end else
                writeln(data[2*(n-i)+2]);
        readln(n);
        end;
END.