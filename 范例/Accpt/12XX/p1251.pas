PROGRAM p1251;

VAR
        num     :array[1..50]of integer;
        have    :integer;
        ans     :longint;
        avg,sum :longint;
        i       :Integer;
        step    :Integer;
BEGIN
readln(have);
step:=0;
while have<>0 do
        begin
        inc(step);
        sum:=0;
        for i:=1 to have do
                begin
                read(num[i]);
                sum:=sum+num[i];
                end;
        avg:=sum div have;
        ans:=0;
        for i:=1 to have do
                ans:=ans+abs(avg-num[i]);
        writeln('Set #',step);
        write('The minimum number of moves is ');
        writeln(ans div 2,'.');
        readln(have);
        writeln;
        end;
END.