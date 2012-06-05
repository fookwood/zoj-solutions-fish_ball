PROGRAM p1113;

VAR
        n       :Integer;
        i       :Integer;
        sum     :real;
        ji      :longint;

BEGIN
sum:=1;
ji:=1;
writeln('n e');
writeln('- -----------');
writeln('0 1');
writeln('1 2');
writeln('2 2.5');
for i:=1 to 9 do
        begin
        ji:=ji*i;
        sum:=sum+1/ji;
        if (i<>2)and(i<>1) then
                write(i,' ',sum:0:9);
        if (i<>1)and(i<>2) then writeln;
        end;
readln;
END.
