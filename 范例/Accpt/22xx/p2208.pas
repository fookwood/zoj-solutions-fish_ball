PROGRAM p2208;

VAR
        n       :integer;
        total   :integer;
        m       :integer;
        data    :array[1..200]of char;
        i,j     :integer;
        ch      :char;


BEGIN
readln(n);
while n<>0 do
        begin
        total:=0;
        repeat
        read(ch);
        inc(total);
        data[total]:=ch;
        until eoln;
        readln;
        m:=total div n;
        //readin;
        for i:=1 to n do
                for J:=1 to m do
                        if j mod 2=0 then
                        write(data[j*n-i+1]) else
                        write(data[(j-1)*n+i]);
        writeln;
        readln(n);
        end;
END.