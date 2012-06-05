PROGRAM P1819;

CONST
        max=70;

TYPE
        bignum=array[1..max]of Integer;

VAR
        sum                     :BigNum;
        n,i                     :Integer;
        num                     :array[0..50,1..50]of BigNum;

FUNCTION mul(var t:BigNum; h:Integer):BigNum;
var
        i,temp                  :Integer;
begin
temp:=0;
for i:=1 to max do
        begin
        temp:=temp+ t[i] * h ;
        mul[i]:=temp mod 10;
        temp:=temp div 10;
        end;
end;

FUNCTION add(var s,t:BigNum):BigNum;
var
        i,temp                  :Integer;
begin
temp:=0;
for i:=1 to max do
        begin
        temp:=temp+s[i]+t[i];
        add[i]:=temp mod 10;
        temp:=temp div 10;
        end;
end;

PROCEDURE Print(var t:BigNum);
var
        i,j                     :Integer;
begin
for j:=max downto 1 do if t[j]<>0 then break;
for I:=j downto 1 do write(t[i]);
writeln;
end;

PROCEDURE makenum;
var
        temp                    :BigNum;
        i,n,h                   :Integer;
begin
fillchar(num,sizeof(num),0);
for I:=1 to 50 do num[i,1][1]:=1;
for n:=2 to 50 do
        for h:=2 to n do
                begin
                temp:=mul(num[n-1,h],h);
                num[n,h]:=add(temp,num[n-1,h-1]);
                end;
end;

BEGIN
makenum;
readln(n);
while (n<>0) do
        begin
        fillchar(sum,sizeof(sum),0);
        for i:=1 to n do
        sum:=add(sum,num[n,i]);
        write(n,' ');
        print(sum);
        readln(n);
        end;
END.