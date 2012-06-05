PROGRAM p1339;

VAR
        n,i,j                          :Integer;
        ch                             :Char;
        total,min,per                  :Integer;


BEGIN
//assign(input,'p.in');
//reset(input);
readln(n);
while (n<>0) do
        begin
        total:=0;
        min:=maxint;
        for i:=1 to n do
                begin
                per:=0;
                for j:=1 to 25 do
                        begin
                        read(ch);
                        if ch<>'X' then inc(per);
                        end;
                inc(total,per);
                if per<min then min:=per;
                readln;
                end;
        writeln(total-min*n);
        readln(n);
        end;
END.