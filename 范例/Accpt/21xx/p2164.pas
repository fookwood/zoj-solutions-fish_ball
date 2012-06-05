PROGRAM p2164;

VAR
        n,m     :integer;
        i       :integer;
        j       :Integer;
        p,c     :Integer;
        pic     :array[1..50]of integer;
        temp    :array[1..50] of integer;
BEGIN
readln(n,m);
while (n<>0)and(m<>0) do
        begin
        for i:=1 to n do pic[i]:=n-i+1;
        for i:=1 to m do
                begin
                readln(p,c);
                for j:=1 to p-1 do temp[j]:=pic[j];
                for j:=1 to c do pic[j]:=pic[p+j-1];
                for j:=c+1 to p+c-1 do pic[j]:=temp[j-c];
                end;
        writeln(pic[1]);
        readln(n,m);
        end;
END.