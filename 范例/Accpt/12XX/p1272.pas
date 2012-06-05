PROGRAM p1272;

TYPE
        BigNum=array[0..100]of Longint;

VAR
        i                               :Longint;
        per,total                       :array[1..23]of BigNum;
        s,ans                           :String;
        zero,d                          :BigNum;

FUNCTION Mul(t:BigNum;p:Longint):BigNum;
var
        i,temp                          :Longint;
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
mul:=t;
end;

FUNCTION add(a,b:BigNum):BigNum;
var
        i,temp                          :Integer;
begin
temp:=0;
for i:=b[0] downto a[0]+1 do a[i]:=0;
for i:=1 to b[0] do a[i]:=a[i] + b[i];
if b[0]>a[0] then a[0]:=b[0] ;
for i:=1 to a[0] do
        begin
        temp:=temp + a[i];
        a[i]:=temp mod 10;
        temp:=temp div 10;
        end;
while (temp>0) do
        begin
        inc(a[0]);
        a[a[0]]:=temp mod 10;
        temp:=temp div 10;
        end;
add:=a;
end;

FUNCTION Decp(a,b:BigNum):BigNum;
var
        i,temp                          :Longint;
begin
temp:=0;
for i:=1 to b[0] do a[i]:=a[i]-b[i];
for i:=1 to a[0]-1 do
        if a[i]<0 then
                begin
                a[i]:=10 + a[i];
                dec(a[i+1]);
                end;
while (a[0]>1) and (a[a[0]]=0) do dec(a[0]);
decp:=a;
end;

PROCEDURE Print(var t:BigNum);
var
        i                               :Longint;
begin
for i:=t[0] downto 1 do
        begin
        if (i mod 3=0)and(i<>t[0]) then write(',') ;
        write(t[i]);
        end;
writeln;
end;

PROCEDURE MakeData;
var
        i                               :Integer;
begin
per[1][0]:=1;
per[1][1]:=1;
total[1][0]:=2;
total[1][1]:=6;
total[1][2]:=2;
for i:=2 to 23 do per[i]:=mul(per[i-1],26);
for i:=2 to 22 do total[i]:=add(total[i-1],per[i+1]);
zero[0]:=1;
zero[1]:=0;
end;

FUNCTION Compare(var a,b:BigNum):Integer;
var
        i                               :Longint;
begin
if a[0]>b[0] then compare:=1 else
if a[0]<b[0] then compare:=-1 else
        begin
        i:=a[0];
        while (i>1) and (a[i]=b[i]) do dec(i);
        if a[i]>b[i] then compare:=1 else
        if a[i]<b[i] then compare:=-1 else
        compare:=0;
        end;
end;

PROCEDURE Changetochar;
var
        i,j                             :Longint;
        data                            :BigNum;
begin
data[0]:=length(s);
for i:=1 to data[0] do data[data[0]-i+1]:=ord(s[i])-48;
d:=data;

ans:='';
for i:=1 to 23 do
        if compare(total[i],data)>=0 then break;

if i>1 then decp(data,total[i-1]);



while (compare(data,zero)>0) do
        begin
        j:=0;

        while (compare(data,per[i])>=0) do
                begin
                data:=decp(data,per[i]);
                inc(j);
                end;

        ans:=ans+chr(j+ord('a')-1);
        dec(i);
        end;
end;

PROCEDURE changetonum;
var
        i,j                             :Integer;
begin
ans:=s;
d[0]:=1;
d[1]:=0;
if length(ans)>1 then d:=total[length(ans)-1];

for i:=1 to length(s) do
        for j:=ord('a') to ord(s[i])-1 do
                d:=add(d,per[length(s)-i+1]);

d:=add(d,per[1]);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
MakeData;
readln(s);
while (s<>'*') do
        begin
        if (s[1]>='0') and (s[1]<='9') then changetochar
                else changetonum;
        write(ans);
        for i:=length(ans)+1 to 22 do write(' ');
        print(d);
        readln(s);
        end;
END.