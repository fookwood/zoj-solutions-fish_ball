PROGRAM p1009;

TYPE
        enigma=array['A'..'Z']of Char;

VAR
        step                            :Integer;
        t1,t2                           :Integer;
        max,ch,a                        :Char;
        n,i,total                       :Integer;
        s,save                          :array[1..3]of Enigma;

PROCEDURE writeout(goal:Char);
begin
write(lowercase(s[1][s[2][s[3][goal]]]));
end;

PROCEDURE Change(var what:Enigma);
var
        copy                            :Enigma;
        ch                              :Char;
begin
for ch:='A' to pred(max) do
        begin
        if what[ch]=max then copy[succ(ch)]:='A' else
                copy[succ(ch)]:=succ(what[ch]);
        end;
if what[max]=max then copy['A']:='A' else copy['A']:=succ(what[max]);
for ch:='A' to max do what[ch]:=copy[ch];
end;

PROCEDURE Print(goal:Char);
begin
writeout(goal);
inc(t1);
change(s[1]);
if t1=total then
        begin
        t1:=0;
        change(s[2]);
        inc(t2);
        end;
if t2=total then
        begin
        t2:=0;
        change(s[3]);
        end;
end;

BEGIN
step:=0;
readln(total);
while (total<>0) do
        begin
        inc(step);
        max:=chr(total+ord('A')-1);
        for i:=1 to 3 do
                begin
                //s[i]:='';
                for ch:='A' to max do s[i][ch]:=' ';
                for ch:='A' to max do
                        begin
                        read(a);
                        s[i][a]:=ch;
                        end;
                save[i]:=s[i];
                readln;
                end;
        readln(n);
        writeln('Enigma ',step,':');
        for I:=1 to n do
                begin
                s:=save;
                t1:=0;t2:=0;
                while not eoln do
                        begin
                        read(ch);
                        print(ch);
                        end;
                readln;
                writeln;
                end;
        readln(total);
        if total<>0 then writeln;
        end;
END.
