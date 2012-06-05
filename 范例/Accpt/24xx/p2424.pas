PROGRAM p2424;

TYPE
        BigNum=array[0..100]of Longint;

VAR
        n                       :BigNum;
        m                       :Integer;

PROCEDURE mul(var t:BigNum;p:Longint);
var
        i,temp                  :Longint;
begin
temp:=0;
for i:=1 to t[0] do
        begin
        temp:=temp + t[i] * p;
        t[i]:=temp mod 10;
        temp:=temp div 10;
        end;
while (temp>0) do
        begin
        inc(t[0]);
        t[t[0]]:=temp mod 10;
        temp:=temp div 10;
        end;
end;

PROCEDURE Divp(var t:BigNum;p:Longint);
var
        temp,i                  :Longint;
begin
temp:=0;
for i:=t[0] downto 1 do
        begin
        temp:=temp * 10 + t[i];
        t[i]:=temp div p;
        temp:=temp mod p;
        end;
while (t[t[0]]=0) do dec(t[0]);
end;

PROCEDURE Print(var t:BigNum);
var
        i                       :Integer;
begin
for i:=t[0] downto 1 do write(t[i]);
writeln;
end;


PROCEDURE Main;
var
        i                       :Integer;
begin
n[0]:=1;
n[1]:=1;
for i:=1 to m do
        begin
        mul (n , ( 2 * m - i +1));
        divp (n,i);
        end;
divp(n,m+1);
print(n);
end;

BEGIN
readln(m);
while (m<>-1) do
        begin
        main;
        readln(m);
        end;
END.