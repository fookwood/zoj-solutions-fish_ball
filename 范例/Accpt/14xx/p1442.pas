PROGRAM p1442;

CONST
        maxp=10;

TYPE
        BigNum=array[0..100]of Longint;


VAR
        ans                     :BigNum;
        n,m,part                :Longint;
        total_up                :Longint;
        up,vector,order         :array[0..9]of Longint;

PROCEDURE Print(var t:BigNum);
var
        i,j                             :Integer;
begin
for i:=t[0] downto 1 do write(t[i]);
writeln;
end;

PROCEDURE MakeOrder;
var
        i                               :Integer;
begin
order[0]:=0;
order[1]:=1;
for i:=2 to 9 do order[i]:=order[i-1] * 2;
//writeln('Here are the 9 order:');
//for i:=0 to 8 do write(order[i],' ');
//writeln;
end;

PROCEDURE Add(var s,t:BigNum);
var
        i,temp                  :Longint;
begin
for i:=t[0] downto s[0]+1 do s[i]:=0;

for i:=1 to t[0] do inc(s[i],t[i]);
if t[0]>s[0] then s[0]:=t[0];

temp:=0;
for i:=1 to s[0] do
        begin
        temp:=temp + s[i];
        s[i]:=temp mod maxp;
        temp:=temp div maxp;
        end;
while (temp>0) do
        begin
        inc(s[0]);
        s[s[0]]:=temp mod maxp;
        temp:=temp div maxp;
        end;
end;

PROCEDURE Decp(var s,t:BigNum);
var
        i,temp                          :Integer;
begin
for i:=1 to t[0] do dec(s[i],t[i]);
temp:=0;
for i:=1 to s[0]-1 do
        if s[i]<0 then
                begin
                s[i]:=maxp+s[i];
                dec(s[i+1]);
                end;
if s[s[0]]<0 then while true do;
while (s[0]>1)and(s[s[0]]=0) do dec(s[0]);
end;

PROCEDURE Mul(var t:BigNum;p:Longint);
var
        i,temp                  :Longint;
begin
temp:=0;
for i:=1 to t[0] do
        begin
        temp:=temp + t[i] * p;
        t[i]:=temp mod maxp;
        temp:=temp div maxp;
        end;
while (temp>0) do
        begin
        inc(t[0]);
        t[t[0]]:=temp mod maxp;
        temp:=temp div maxp;
        end;
end;

PROCEDURE Divp(var t:BigNum;p:Longint);
var
        i,temp                  :Longint;
begin
temp:=0;
for i:=t[0] downto 1 do
        begin
        temp:=temp * maxp + t[i];
        t[i]:=temp div p;
        temp:=temp mod p;
        end;

while (t[0]>1)and(t[t[0]]=0) do dec(t[0]);
end;

PROCEDURE Init;
var
        i                       :Integer;
        temp_up,temp_down       :Longint;
begin
readln(n,m);
total_up:=0;
for i:=1 to n do
        begin
        readln(temp_down,temp_up);
        dec(m,temp_down);
        up[i]:=temp_up-temp_down;
        inc(total_up,up[i]);
        end;

vector[0]:=0;
for i:=1 to n do
        if up[i]<m then
                begin
                inc(vector[0]);
                vector[vector[0]]:=i;
                end;

end;



FUNCTION c(a,b:Longint):BigNum;
var
        i                       :Longint;
        temp                    :BigNum;
begin
if a-b<b then b:=a-b;

temp[0]:=1;
temp[1]:=1;

for i:=1 to b do
        begin
        mul(temp,a-b+i);

        divp(temp,i);
        end;

c:=temp;
end;


PROCEDURE Main;
var
        i,j                     :Longint;
        copym,total_add         :Longint;
        temp                    :BigNum;
begin
fillchar(ans,sizeof(ans),0);

if (m<0) or (total_up<m) then
        begin
        writeln(0);
        exit;
        end;

//ans:=c(m+n-1,m);

for i:=0 to order[vector[0]+1]-1 do
        begin
        copym:=m;
        total_add:=0;
        for j:=1 to vector[0] do
                if order[j] and i = order[j] then
                        begin
                        inc(total_add);
                        dec(copym,up[vector[j]]+1);
                        end;

        if copym<0 then continue;

        if not odd(total_add) then
                begin
                temp:=c(copym+n-1,n-1);
                add(ans,temp);
                end;
        end;

for i:=0 to order[vector[0]+1]-1 do
        begin
        copym:=m;
        total_add:=0;
        for j:=1 to vector[0] do
                if order[j] and i = order[j] then
                        begin
                        inc(total_add);
                        dec(copym,up[vector[j]]+1);
                        end;

        if copym<0 then continue;

        if odd(total_add) then
                begin
                temp:=c(copym+n-1,n-1);
                decp(ans,temp);
                end;
        end;

print(ans);
end;


BEGIN
//assign(input,'p.in');
//reset(input);
MakeOrder;
readln(part);
for part:=part downto 1 do
        begin
        Init;
        Main;
        end;
END.
