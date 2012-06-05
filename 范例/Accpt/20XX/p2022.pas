PROGRAM p2022;

VAR
        n,i                             :Integer;
        ans                             :Longint;
        temp                            :Longint;

BEGIN
readln(n);
for i:=1 to n do
        begin
        readln(temp);
        ans:=0;
        while temp>0 do
                begin
                inc(ans,temp div 5);
                temp:=temp div 5;
                end;
        writeln(ans);
        end;
END.