program p1923;

TYPE
        BigNum=array[0..1000]of Integer;

var
        s                       :BigNum;
        ch                      :Char;
        sum                     :Longint;

FUNCTION Modp(var s:BigNum; p:Integer):Longint;
var
        i,temp                  :Longint;
begin
temp:=0;
sum:=0;
for i:=s[0] downto 1 do
        begin
        temp:=temp * 10 + s[i];
        s[i]:=temp div p;
        inc(sum,s[i]);
        temp:=temp mod p;
        end;
while (s[s[0]]=0) do dec(s[0]);
ModP:=temp;
end;

PROCEDURE print(var s:bigNum);
var
        i                       :Integer;
begin
for i:=s[0] downto 1 do write(s[i]);
writeln;
end;

PROCEDURE Main;
var
        temp,a,b,i              :Longint;
        shownum                 :Longint;
        num                     :array[1..4]of Longint;
begin
if (s[0]=1) then
        begin
        writeln(1,s[1]);
        exit;
        end;

fillchar(num,sizeof(num),0);
if s[0]>1 then shownum:=s[2]*10+s[1] else shownum:=s[1];



while shownum mod 2=0 do
        begin
        if shownum mod 4=0 then
                begin
                Modp(s,4);
                inc(num[1],2);
                end else
                begin
                Modp(s,2);
                inc(num[1]);
                end;
        if s[0]>1 then shownum:=s[2]*10+s[1] else shownum:=s[1];
        end;

while sum mod 3=0 do
        begin
        if sum mod 9=0 then
                begin
                Modp(s,9);
                Inc(num[2],2);
                end else
                begin
                Modp(s,3);
                inc(num[2]);
                end;
        end;

while (s[1]=5)or(s[1]=0) do
        begin
        Modp(s,5);
        inc(num[3]);
        end;

repeat
        if (s[1]=1)and(s[0]=1) then break;
        temp:=modp(s,7);
        if temp>0 then
                begin
                writeln('There is no such number.');
                exit;
                end;
        inc(num[4]);
until false;
if (s[1]<>1)and(s[0]<>1) then
        begin
        writeln('There is no such number.');
        exit;
        end;

a:=num[1] mod 3;
b:=num[2] mod 2;
dec(num[1],a);
dec(num[2],b);
if ((a=1)and(b=0))or((a=2)and(b=1)) then
        write(2);
if (a=0)and(b=1) then
        write(3);
if (a=2) and(b=0) then
        write(4);
for I:=1 to num[3] do write(5);
if (a>=1)and(b=1) then write(6);
for i:=1 to num[4] do write(7);
for i:=1 to num[1] div 3 do write(8);
for i:=1 to num[2] div 2 do write(9);
writeln;
end;

PROCEDURE Change(var s:BigNum);
var
        i,temp                          :longint;
begin
for i:=1 to s[0] div 2 do
        begin
        temp:=s[i];
        s[i]:=s[s[0]-i+1];
        s[s[0]-i+1]:=temp;
        end;
end;

begin
//assign(input,'p.in');
//reset(input);
repeat
        read(ch);
        if ch='-' then break;
        s[0]:=1;
        s[1]:=ord(ch)-48;
        sum:=s[1];
        while not eoln do
                begin
                read(ch);
                inc(s[0]);
                s[s[0]]:=ord(ch)-48;
                inc(sum,s[s[0]]);
                end;
        Change(s);
        readln;
        Main;
until false;
end.
