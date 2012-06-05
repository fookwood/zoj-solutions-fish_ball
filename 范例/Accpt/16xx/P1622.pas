PROGRAM P1622;


VAR
        n       :integer;
        i       :integer;
        odd     :integer;
        num     :array[0..1]of integer;
        temp    :integer;
        ans     :integer;

BEGIN
while not eof do
        begin
        read(n);
        num[0]:=0;num[1]:=0;
        for i:=1 to n do
                begin
                read(temp);
                inc(num[i mod 2],temp);
                end;
        odd:=n-(n div 2);
        ans:=num[1]+n-odd-num[0];
        if odd-num[1]+num[0]<ans then ans:=odd-num[1]+num[0];
        writeln(ans);
        readln;
        end;

END.