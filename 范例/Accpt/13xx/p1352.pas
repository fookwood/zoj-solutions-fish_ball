PROGRAM p1352;

TYPE
        BigNum  =       array[0..1000]of Longint;

VAR
        part,p                  :Longint;
        m,n                     :Longint;
        s                       :string;
        ans                     :BigNum;

FUNCTION CharToInt(var t:String):BigNum;
var
        temp                    :BigNum;
        i                       :Longint;
begin
temp[0]:=length(t);
for i:=1 to temp[0] do
        if (t[i]>='0') and (t[i]<='9') then
                temp[temp[0]-i+1]:=ord(t[i]) - ord('0') else
        if (t[i]>='A') and (t[i]<='Z') then
                temp[temp[0]-i+1]:=ord(t[i]) - ord('A')+10 else
        if (t[i]>='a') and (t[i]<='z') then
                temp[temp[0]-i+1]:=ord(t[i]) - ord('a')+36;
CharToInt:=temp;
end;

FUNCTION divp(var t:BigNum):Longint;
var
        i,temp                  :Longint;
begin
temp:=0;
for i:=t[0] downto 1 do
        begin
        temp:=temp * m + t[i];
        t[i]:=temp div n;
        temp:=temp mod n;
        end;
divp:=temp;
while (t[0]>1)and(t[t[0]]=0) do dec(t[0]);
end;

PROCEDURE Print(var t:BigNum);
var
        i                       :Longint;
begin
for i:=t[0] downto 1 do
        if t[i]<=9 then write(t[i]) else
        if t[i]<36 then write(chr(t[i]+ord('A')-10)) else
        write(chr(t[i]+ord('a')-36));
writeln;
end;

PROCEDURE Change(t:BigNum);
var
        answer                  :BigNum;
begin
answer[0]:=0;
while (t[0]<>1) or (t[1]<>0) do
        begin
        inc(answer[0]);
        answer[answer[0]]:=divp(t);
        end;

if answer[0]=0 then
        begin
        inc(answer[0]);
        answer[1]:=0;
        end;

write(m,' ');
print(ans);
write(n,' ');
print(answer);
writeln;
end;


BEGIN
//assign(input,'p.in');
//reset(input);
//assign(output,'p.out');
//rewrite(output);
readln(part);
for P:=1 to part do
        begin
        Readln(m,n,s);
        while (s[1]=' ') do delete(s,1,1);
        ans:=CharToInt(s);
        Change(ans);
        end;
//close(output);
END.