PROGRAM p1486;

TYPE
        BigNum=array[0..1000]of Integer;

VAR

        n,m,i                   :Integer;
        ans                     :BigNum;

PROCEDURE Mul(var t:BigNum; p:Integer);
var
        temp,i                  :Integer;
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

PROCEDURE Print(var t:BigNum);
var
        i                       :Integer;
begin
for i:=t[0] downto 1 do write(t[i]);
writeln;
end;

BEGIN
readln(n,m);
while (n<>0) or (m<>0) do
        begin
        ans[0]:=1;
        ans[1]:=1;
        mul(ans,m);
        dec(m);
        for i:=1 to n-1 do
                begin
                readln;
                mul(ans,m);
                end;
        print(ans);
        readln(n,m);
        end;
END.