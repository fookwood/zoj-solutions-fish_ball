PROGRAM p1874;

VAR
        n,m     :longint;
        add     :integer;
        ans     :integer;
        y       :Integer;
        copy    :longint;
BEGIN
readln(n,m);
while (n<>0)or(m<>0) do
        begin
        ans:=0;
        while (n>0)or(m>0) do
                begin
                add:=(n mod 10)+(m mod 10);
                n:=n div 10;
                m:=m div 10;
                if add>=10 then
                        begin
                        inc(ans);
                        if m mod 10=9 then
                                begin
                                copy:=m;
                                y:=0;
                                while copy mod 10=9 do
                                        begin
                                        inc(y);
                                        copy:=copy div 10;
                                        end;
                                inc(ans,y);
                                end;
                        m:=m+1;
                        end;
                end;
        if ans=0 then writeln('No carry operation.')
                else
                if ans=1 then writeln(ans,' carry operation.')
                        else writeln(ans, ' carry operations.');
        readln(n,m);
        end;
END.