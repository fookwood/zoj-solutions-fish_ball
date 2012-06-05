PROGRAM p1028;

VAR
        total   :integer;
        part,p  :Integer;
        odd     :integer;
        even    :integer;
        temp,i  :Integer;

BEGIN
readln(part);
for p:=1 to part do
        begin
        read(total);
        even:=0;odd:=0;
        for I:=1 to total do
                begin
                read(temp);
                if (temp=1)and(i mod 2=0) then inc(even);
                if (temp=1) and(i mod 2=1) then inc(odd);
                end;
        if total mod 2=0 then
                begin
                if abs(odd-even)<=1 then writeln('YES')
                        else writeln('NO');
                end else
                begin
                writeln('YES');
                end;

        end;
END.