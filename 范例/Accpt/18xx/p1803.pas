PROGRAM p1803;

VAR
        i                       :Integer;
        step                    :Integer;
        total                   :Integer;
        num,ci                  :array[1..500]of Integer;

FUNCTION mul(l:Integer):Integer;
var
        s                       :String;
        i,temp                  :Integer;
begin
if l=1 then
        begin
        mul:=2*ci[l]-1;
        exit;
        end;
temp:=0;
str(num[l],s);
inc(temp,length(s));
inc(temp);
inc(temp,2*ci[l]);
for i:=1 to l-1 do dec(ci[i],ci[l]);
mul:=mul(l-1)+temp;
end;

PROCEDURE Main;
var
        i,j,x,long              :Integer;
        ans1,ans2               :Integer;
begin
long:=total;
x:=num[total+1];
i:=2;
while (i<=long) do
        if num[i]=0 then
                begin
                for j:=i to long-1 do
                        begin
                        num[j]:=num[j+1];
                        ci[j]:=ci[j+1];
                        end;
                dec(long);
                end else inc(i);
ans1:=0;
for i:=1 to long do
        if odd(ci[i]) then inc(ans1,num[i]*x) else inc(ans1,num[i]);
writeln(ans1,' ',mul(long)+1);
end;

BEGIN
step:=0;
read(total);
while (total<>0) do
        begin
        inc(step);
        inc(total);
        for i:=1 to total do ci[i]:=total-i;
        for i:=1 to total do read(num[i]);
        readln(num[total+1]);
        write('Polynomial ',step,': ');
        Main;
        read(total);
        end;
END.