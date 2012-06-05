PROGRAM p2186;

VAR
        a       :array[1..3]of integer;
        temp    :integer;
        i,j     :integer;
BEGIN
while not eof do
        begin
        for i:=1 to 3 do
        read(a[i]);
        for i:=1 to 2 do
                for j:=i+1 to 3 do
                if a[i]>a[j] then
                begin
                temp:=a[i];
                a[i]:=a[j];
                a[j]:=temp;
                end;
        if (a[1]>168) then writeln('NO CRASH') else
                begin
                write('CRASH ');
                i:=1;
                while (i<=3)and(a[i]<=168) do inc(i);
                writeln(a[i-1]);
                end;
        readln;
        end;
END.