PROGRAM p1858;

CONST
        pre     :array['A'..'Z']of char=
        ('0','1','2','3','0','1','2','0','0','2','2','4','5','5','0','1',
        '2','6','2','3','0','1','0','2','0','2');


VAR
        s       :string;
        i       :Integer;
        j       :Integer;
        can     :boolean;
BEGIN
while not eof do
        begin
        readln(s);
        for I:=1 to length(s) do s[i]:=pre[s[i]];
        i:=1;
        while (i<=length(s))and(s[i]='0')do inc(i);
        if i=1 then
                begin
                write(s[1]);
                i:=2;
                end;
        for J:=i to length(s) do
                if (s[j]<>'0')and(s[j]<>s[j-1]) then write(s[j]);
        writeln;
        end;
END.