PROGRAM P1582;

VAR
        s,t     :string;

        num     :longint;
        i,k     :integer;
        j       :integer;
        max     :integer;
        speed   :integer;
BEGIN
readln(k);
for i:=1 to k do
        begin
        readln(speed);
        readln(s);
        readln(t);
        j:=1;
        if length(s)>length(t) then max:=length(t) else max:=length(s);
        while (j<=max)and(s[j]=t[j]) do inc(j);
        dec(j);
        num:=speed*(length(s)+length(t)-j*2);
        writeln(num);
        end;
END.