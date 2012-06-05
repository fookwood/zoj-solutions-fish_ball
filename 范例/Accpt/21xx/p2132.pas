PROGRAM p2132;

VAR
        n,i                                             :Longint;
        p                                                       :Longint;
        counter,num                                                     :Longint;

BEGIN
while not eof do
        begin
        read(n);
        num:=0;counter:=0;
        for i:=1 to n do
                begin
                read(p);
                if counter=0 then
                        begin
                        num:=p;counter:=1;
                        end else
                if p=num then inc(counter) else dec(counter);
                end;
        writeln(num);
        readln;
        end;
END.