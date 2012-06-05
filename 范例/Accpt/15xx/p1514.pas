PROGRAM p1514;

VAR
        whether :array[1..1000]of integer;
        i,ans   :longint;
        n,m     :integer;
        temp   :integer;
BEGIN
readln(n,m);
while (n<>0) and(m<>0) do
        begin
        fillchar(whether,sizeof(whether),0);
        ans:=0;
        for i:=1 to m do
                begin
                read(temp);
                inc(whether[temp]);
                if whether[temp]=2 then
                        inc(ans);
                end;
        readln;
        writeln(ans);
        readln(n,m);
        end;
END.