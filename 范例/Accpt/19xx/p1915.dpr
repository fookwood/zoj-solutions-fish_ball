program p1915;

{$APPTYPE CONSOLE}


var
        score   :array[1..1000]of integer;
        ave     :real;
        total   :integer;
        i       :Integer;
        part,p  :Integer;
        n       :Integer;
        sum     :real;
begin
  { TODO -oUser -cConsole Main : Insert code here }
readln(part);
for P:=1 to part do
        begin
        read(n);
        sum:=0;
        total:=0;
        for i:=1 to n do
                begin
                read(score[i]);
                sum:=sum+score[i];
                end;
        ave:=sum/n;

        for i:=1 to n do
                if score[i]>ave then inc(total);
        writeln(100*total/n:0:3,'%');
        end;


end.
