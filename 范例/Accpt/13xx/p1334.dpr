program p1334;

{$APPTYPE CONSOLE}
var
        screen  :array[1..7]of integer;
        ans     :array[1..7]of integer;
        total   :extended;
        i       :Integer;
        a,b     :Integer;
        ch      :char;
        flag    :boolean;
begin
while not eof do
        begin
        for i:=1 to 7 do
                begin
                read(ch);
                if ch=' ' then screen[i]:=0
                        else
                        if ch<='9' then screen[i]:=ord(ch)-48 else
                                screen[i]:=ord(ch)-ord('A')+10;
                end;
        readln(a,b);
        total:=0;
        for I:=1 to 7 do total:=total*a+screen[i];
        for I:=1 to 7 do
                begin
                ans[i]:=trunc(total-trunc(total/b)*b);
                total:=trunc(total/b);
                end;
        flag:=true;
        for i:=1 to 7 do if screen[i]>a then flag:=false;
        if (total=0)and(flag) then
                begin
                i:=7;
                while (i>=2)and(ans[i]=0) do
                        begin
                        write(' ');
                        dec(i);
                        end;
                while (i>=1) do
                        begin
                        if ans[i]<=9 then write(ans[i]) else write(chr(ans[i]+ord('A')-10));
                        dec(i);
                        end;
                writeln;
                end else writeln('ERROR':7);
        end;

end.


