PROGRAM p1048;

VAR
        sum     :real;
        i       :integer;
        temp    :real;

BEGIN
while not eof do
        begin
        sum:=0;
        for i:=1 to 12 do
                begin
                readln(temp);
                sum:=sum+temp;
                end;
        writeln('$',sum/12:0:2);
        end;
END.