PROGRAM p2000;

VAR
        n                               :Longint;
        num                             :array[0..10]of Int64;
        sum                             :Int64;

PROCEDURE Main;
var
        i,j                             :Integer;
        s                               :String;
begin
if n<10 then
        begin
        writeln(n);
        exit;
        end;
sum:=0;
for j:=1 to 20 do
        begin
        inc(sum,num[(j+1) div 2]);
        if sum>=n then break;
        end;
dec(sum,num[(j+1) div 2]);
if j mod 2=0 then
        begin
        str(n-sum-1,s);
        while length(s)<j div 2 do s:='0'+s;
        s[1]:=succ(s[1]);
        write(s);
        for i:=length(s) downto 1 do write(s[i]);
        writeln;
        end else
        begin
        str(n-sum-1,s);
        while length(s)<(j+1) div 2 do s:='0'+s;
        s[1]:=succ(s[1]);
        write(s);
        for I:=length(s)-1 downto 1 do write(s[i]);
        writeln;
        end;
end;


PROCEDURE MakeNum;
var
        i                               :Integer;
begin
num[0]:=1;
num[1]:=9;
for I:=1 to 9 do
        num[i+1]:=num[i]*10;

end;

BEGIN
makeNum;
readln(n);
while n<>0 do
        begin
        Main;
        readln(n);
        end;

END.
