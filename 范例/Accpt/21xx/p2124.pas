PROGRAM p2124;

VAR
        n,copy                          :Int64;

FUNCTION Gcd(a,b:Int64):Int64;
begin
if a=0 then Gcd:=b else Gcd:=gcd(b mod a,a);
end;

FUNCTION Ans:Int64;
var
        q,num,total                     :Int64;

begin
q:=2;
num:=0;
total:=0;
while (q<=trunc(abs(sqrt(n)))) do
        if n mod q=0 then
        begin
        total:=0;
        while n mod q=0 do
                begin
                inc(total);
                n:=n div q;
                end;
        if num=0 then num:=total;
        if num>total then num:=gcd(total,num) else num:=gcd(num,total);
        end else inc(q);
if num=0 then num:=1;
if n<>1 then
        begin
        if n>num then num:=gcd(num,n) else num:=gcd(n,num);
        end;
if (copy<0) then
        begin
        if (num mod 2=0)or(num=1) then Ans:=1 else Ans:=num;
        if (num mod 2=0) then
                begin
                while num mod 2=0 do
                        num:=num div 2;
                ans:=num;
                end;
        end else Ans:=num;
end;

BEGIN
readln(n);
while (n<>0) do
        begin
        copy:=n;
        n:=abs(n);
        writeln(ans);
        readln(n);
        end;
END.
