PROGRAM p1210;

TYPE
        BigNum=array[0..100]of Longint;

VAR
        n                       :BigNum;
        total_2,total_5,total_10
                                :Integer;
        order                   :array[1..2,1..300]of BigNum;

PROCEDURE Print(var t:BigNum);
var
        i                       :Integer;
begin
for i:=t[0] downto 1 do write(t[i]);
end;

FUNCTION Mul(ans:BigNum;p:Integer):BigNum;
var
        temp,i                  :Integer;
begin
temp:=0;
for i:=1 to ans[0] do
        begin
        temp:=temp + ans[i] * p;
        ans[i]:=temp mod 10;
        temp:=temp div 10;
        end;
while (temp>0) do
        begin
        inc(ans[0]);
        ans[ans[0]]:=temp mod 10;
        temp:=temp div 10;
        end;
Mul:=ans;
end;

PROCEDURE Divp(var ans:BigNum;p:Integer);
var
        i,temp                          :Integer;
begin
temp:=0;
for i:=ans[0] downto 1 do
        begin
        temp:=temp * 10 + ans[i];
        ans[i]:=temp div p;
        temp:=temp mod p;
        end;
while (ans[ans[0]]=0) do dec(ans[0]);
end;

PROCEDURE MakeOrder;
var
        i                       :Integer;
begin
fillchar(order,sizeof(order),0);
order[1][1][0]:=1;
order[1][1][1]:=2;
order[2][1][0]:=1;
order[2][1][1]:=5;
for i:=2 to 300 do
        begin
        order[1][i]:=mul(order[1][i-1],2);
        if order[1][i][0]>80 then break;
        end;
for i:=2 to 300 do
        begin
        order[2][i]:=mul(order[2][i-1],5);
        if order[2][i][0]>80 then break;
        end;
end;

PROCEDURE Change(var n:BigNum);
var
        i,temp                  :Longint;
begin
for i:=1 to n[0] div 2 do
        begin
        temp:=n[i];
        n[i]:=n[n[0]-i+1];
        n[n[0]-i+1]:=temp;
        end;
end;

PROCEDURE Readin(var n:BigNum);
var
        save                    :BigNum;
        ch                      :Char;
begin
n[0]:=0;
total_2:=0;
total_5:=0;
total_10:=0;
while not eoln do
        begin
        inc(n[0]);
        read(ch);
        n[n[0]]:=ord(ch)-48;
        end;

save:=n;
change(save);

writeln;
write('1 / ');
print(save);
writeln(' =');

while (n[n[0]]=0) do
        begin
        dec(n[0]);
        inc(total_10);
        end;
readln;
change(n);
end;

PROCEDURE Writeout;
var
        i,j                             :Integer;
begin
if (total_2=0)and(total_5=0)and(total_10=0) then
        begin
        writeln(1);
        exit;
        end;
write('0.');
if (total_2=0)and(total_5=0) then j:=total_10-1 else
if total_2=0 then j:=total_10 - order[1][total_5][0] else
        j:=total_10 - order[2][total_2][0];

for i:=1 to j do write(0);



if (total_2=0)and(total_5=0) then write(1)
        else
        if total_2=0 then print(order[1][total_5])
                else print(order[2][total_2]);
writeln;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
MakeOrder;
writeln('Problem 4 by team x');
while not eof do
        begin
        Readin(n);
        while not odd(n[1]) do
                begin
                inc(total_2);
                inc(total_10);
                divp(n,2);
                end;
        while (n[1]=0) or (n[1]=5) do
                begin
                inc(total_5);
                inc(total_10);
                divp(n,5);
                end;


        writeOut;

        end;
writeln('End of problem 4 by team x');
END.