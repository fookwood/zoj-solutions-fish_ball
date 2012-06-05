PROGRAM p1535;

TYPE
        BigNum=array[0..20]of Integer;

VAR
        n                       :Integer;
        num,save                :BigNum;

PROCEDURE CostTime;
var
        i,j                     :Longint;
begin
for i:=1 to 100 do for j:=1 to 1000000 do ;
end;

PROCEDURE Readin;
var
        ch                      :Char;
begin
n:=0;
while not eoln do
        begin
        inc(n);
        read(ch);
        num[n]:=ord(ch)-48;
        end;
readln;
save:=num;
n:=n div 2;
end;

FUNCTION Fit(p:Integer):Boolean;
var
        sum_up,sum_down,i       :Integer;
        have                    :Boolean;
begin
sum_up:=0;
for i:=1 to n do inc(sum_up,num[i]);

sum_down:=0;
for i:=n+1 to p do inc(sum_down,num[i]);

if (sum_down+(n+n-p) * 9 < sum_up) or (sum_down>sum_up) then
        begin
        Fit:=false;
        exit;
        end;

if p<n+n then sum_down:=sum_down+num[p+1];

have:=false;
for i:=p+2 to n do if num[i]>0 then have:=true;
inc(sum_down,ord(have));
if sum_down>sum_up then Fit:=false
        else Fit:=true;
end;

PROCEDURE print(var t:BigNum);
var
        i                       :Integer;
begin
for i:=1 to n+n do write(t[i]);
writeln;
end;

FUNCTION decp(s,t:BigNum):BigNum;
var
        i,temp                  :Integer;
begin
for i:=1 to n+n do s[i]:=s[i]-t[i];
for i:=n+n downto 1 do
        if s[i]<0 then
                begin
                s[i]:=10 + s[i];
                dec(s[i-1]);
                end;
i:=1;
while (i<=n+n) and (s[i]=0) do inc(i);
s[0]:=i;
decp:=s;
end;

PROCEDURE Main;
var
        i,j,t                   :Integer;
        ans                     :BigNum;
begin
i:=n+1;
t:=0;
while (i<=n+n) do
        if not fit(i) then
                begin
                inc(t);
                j:=i;
                while (num[j]=9) do
                        begin
                        num[j]:=0;
                        dec(j);
                        end;
                inc(num[j]);
                for j:=i+1 to n+n do num[j]:=0;
                if t>20 then i:=n+1;
                end else
                begin
                inc(i);
                t:=0;
                end;

ans:=decp(num,save);
for i:=ans[0] to n+n do write(ans[i]);
if ans[0]=n+n+1 then write(0);
writeln;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
while not eof do
        begin
        Readin;
        Main;
        end;
END.
