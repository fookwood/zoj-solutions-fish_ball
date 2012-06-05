PROGRAM p2143;

CONST
        max=150;

TYPE
        BigNum=array[1..max]of Integer;

VAR
        line                                            :array[0..61]of Char;
        s                                               :String;
        ch                                              :Char;
        b,part,p                                        :Integer;
        num,goal                                        :BigNum;

PROCEDURE makeline;
var
        i                                               :Integer;
begin
for i:=0 to 9 do line[i]:=char(i+48);
for i:=1 to 26 do line[i+9]:=char(i+ord('A')-1);
for i:=1 to 26 do line[i+35]:=char(i+ord('a')-1);
end;


FUNCTION S_0(var t:BigNum):Boolean;
var
        i                                               :Integer;
begin
S_0:=true;
for i:=1 to max do if t[i]<>0 then
        begin
        S_0:=false;
        exit;
        end;
end;

FUNCTION Modp(var t:BigNum):Integer;
var
        i,temp                                          :Integer;
begin
temp:=0;
for i:=max downto 1 do
        begin
        temp:=temp*10+t[i];
        t[i]:=temp div B;
        temp:=temp mod B;
        end;
Modp:=temp;
end;


PROCEDURE Main;
var
        total,start                                     :Integer;
        i                                               :Integer;
begin
fillchar(goal,sizeof(goal),0);
fillchar(num,sizeof(num),0);
for i:=1 to length(s) do num[length(s)-i+1]:=ord(s[i])-48;
total:=0;
while not S_0(num) do
        begin
        inc(total);
        goal[total]:=Modp(num);
        end;

for i:=1 to total do
        if goal[i]>=(b+1) div 2 then
        begin
        inc(goal[i+1]);
        goal[i]:=goal[i]-b;
        end;
if goal[total+1]<>0 then inc(total);
for i:=total downto 1 do
        begin
        if goal[i]<0 then write('-');
        write(line[abs(goal[i])]);
        end;
writeln;
end;


BEGIN
makeline;
readln(part);
for P:=1 to part do
        begin
        read(b,ch);
        readln(s);
        Main;
        end;
END.