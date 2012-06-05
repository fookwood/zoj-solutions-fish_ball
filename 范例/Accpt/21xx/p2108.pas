PROGRAM p2108;

VAR
        a,b,total,i,ans                     :Longint;

BEGIN
read(total);
while total<>0 do
        begin
        a:=0;
        ans:=0;
        for i:=1 to total do
                begin
                read(b);
                if b>a then inc(ans,(b-a)*6);
                if b<a then inc(ans,(a-b)*4);
                inc(ans,5);
                a:=b;
                end;
        writeln(ans);
        readln;
        read(total);
        end;
END.