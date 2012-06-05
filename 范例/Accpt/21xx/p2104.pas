PROGRAM p2104;

VAR
        n       :Integer;
        dic     :array[1..1000]of string;
        num     :array[1..1000]of integer;
        find    :boolean;
        have    :Integer;
        temp    :string;
        i,j     :Integer;
        max     :integer;
        point   :integer;
BEGIN
readln(n);
while n<>0 do
        begin
        have:=0;
        fillchar(num,sizeof(num),0);
        for i:=1 to n do
                begin
                readln(temp);
                find:=false;
                for j:=1 to have do
                        if dic[j]=temp then
                        begin
                        inc(num[j]);
                        find:=true;
                        break;
                        end;
                if not find then
                        begin
                        inc(have);
                        dic[have]:=temp;
                        num[have]:=1;
                        end;
                end;
        max:=0;
        for i:=1 to have do
                if num[i]>max then
                        begin
                        max:=num[i];
                        point:=i;
                        end;
        writeln(dic[point]);
        readln(n);
        end;
END.