PROGRAM p1715;

VAR
        n,q     :integer;
        h       :integer;
        come    :array[1..100]of integer;
        i       :integer;
        temp    :Integer;
        point   :Integer;
        j       :integer;
        max     :integer;
BEGIN
readln(n,q);
while (n<>0)or(q<>0) do
        begin
        fillchar(come,sizeof(come),0);
        for i:=1 to n do
                begin
                read(h);
                for j:=1 to h do
                        begin
                        read(temp);
                        inc(come[temp]);
                        end;
                readln;
                end;
        max:=0;
        for I:=1 to 100 do
                if (come[i]>max) then
                        begin
                        max:=come[i];
                        point:=i;
                        end;
        if max>=q then writeln(point) else writeln(0);
        readln(n,q);
        end;
END.