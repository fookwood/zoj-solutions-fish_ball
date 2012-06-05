PROGRAM p2028;

VAR     s1,s2,s                                          :array[1..1000]of Char;
        st1,st2                                          :String;
        i                                                :Integer;
        l1,l2                                            :Longint;
        ch                                               :Char;
        n,m                                              :Longint;
        code                                             :Integer;

BEGIN
while not eof do
        begin
        for i:=1 to 500 do
                begin
                s[i]:=' ';
                s1[i]:=' ';
                s2[i]:=' ';
                end;
        readln(s);
        for i:=1 to 500 do if s[i]=' ' then break;
        move(s[1],s1[1],i-1);
        move(s[i+1],s2[1],500-i);
        l1:=i-1;
        l2:=500; while not((s2[l2]>='0')and(s2[l2]<='9')) do dec(l2);
        if l1<=3 then
                begin
                n:=0;
                for i:=1 to l1 do n:=n*10+ord(s1[i])-48;
                end else
                begin
                n:=0;
                for I:=l1-2 to l1 do n:=n*10+ord(s1[i])-48;
                end;
        if l2<=3 then
                begin
                m:=0;
                for i:=1 to l2 do m:=m*10+ord(s2[i])-48;
                end else
                begin
                m:=0;
                for i:=l2-2 to l2 do m:=m*10+ord(s2[i])-48;
                end;
        if (s1[1]='1')and(l1=1) then
                begin
                for i:=1 to l2 do write(s2[i]);
                writeln;
                end else
        if (s2[1]='1')and(l2=1) then
                begin
                for i:=1 to l1 do write(s1[i]);
                writeln;
                end else
        if (n*m) mod 8=0 then writeln('Yes') else
        if (n*m) mod 4=0 then writeln(4) else
        writeln((n*m) mod 4);
        end;
END.