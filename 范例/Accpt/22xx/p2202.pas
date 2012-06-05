PROGRAM p2202;

VAR
        first                                   :Boolean;
        ch1,ch2                                 :Char;
        a,b,c                                   :Integer;
        ans                                     :array[0..1]of Extended;

BEGIN
while (true) do
        begin
        a:=0;
        b:=1;
        ans[0]:=0;
        ans[1]:=1;
        first:=true;
        ch2:='0';
        repeat
                read(ch1);
                if first and (ch1='0') then break;
                c:=(ord(ch2)-48) * 10 +ord(ch1)-48;
                if (c=0) then ans[a]:=0 else
                if (c>26)and(ch1<>'0') then ans[a]:=ans[b] else
                if (c>26)and(ch1='0') then ans[a]:=0 else
                if not first and (ch2='0') then ans[a]:=ans[b] else
                if (ch1='0') then ans[a]:=ans[a] else
                ans[a]:=ans[a]+ans[b];
                ch2:=ch1;
                a:=(a+1) mod 2;
                b:=(b+1) mod 2;
                first:=false;
                if eoln then break;
        until false;
        if first then break;
        readln;
        writeln(ans[b]:0:0);
        end;
END.