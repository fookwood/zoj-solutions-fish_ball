PROGRAM p1475;

CONST
        maxl=500;
        fire=1000000;


TYPE
        BigNum=array[0..maxl]of Longint;

VAR
        n                               :Integer;
        ans,s                           :array[0..200]of BigNum;

PROCEDURE Print(var t:BigNum);
var
        i,j                             :Integer;
begin
write(t[t[0]]);
for i:=t[0]-1 downto 1 do
        begin

        for j:=1 to 5-trunc(ln(t[i])/ln(10)) do write(0);
        write(t[i]);
        end;
writeln;
end;

FUNCTION Multiply(var t:BigNum;p:Longint):BigNum;
var
        i,temp                          :Longint;
begin
temp:=0;
for i:=1 to t[0] do
        begin
        temp:=temp + t[i] * p;
        Multiply[i]:=temp mod fire;
        temp:=temp div fire;
        end;
i:=t[0];
while (temp>0) do
        begin
        inc(i);
        Multiply[i]:=temp mod fire;
        temp:=temp div fire;
        end;
Multiply[0]:=i;
end;

FUNCTION Add(var a,b:BigNum):BigNum;
var
        fadd                            :BigNum;
        i,temp,max,min                  :Longint;
begin
fadd:=a;
for i:=a[0]+1 to maxl do fadd[i]:=0;
for i:=1 to b[0] do
        fadd[i]:=fadd[i]+b[i];
if b[0]>fadd[0] then fadd[0]:=b[0];
temp:=0;
for i:=1 to fadd[0] do
        begin
        temp:=temp + fadd[i];
        fadd[i]:=temp mod fire;
        temp:=temp div fire;
        end;
while (temp>0) do
        begin
        inc(fadd[0]);
        fadd[fadd[0]]:=temp mod fire;
        temp:=temp div fire;
        end;
add:=fadd;
end;

PROCEDURE MakeAns;
var
        temp                            :BigNum;
        i,j,k                           :Integer;
begin
fillchar(s,sizeof(s),0);
fillchar(ans,sizeof(ans),0);
s[1][1]:=1;
s[1][0]:=1;
ans[1][0]:=1;
ans[1][1]:=1;
for i:=2 to 200 do
        begin

        for j:=i downto 2 do
                begin
                s[j]:=add(s[j],s[j-1]);
                s[j]:=multiply(s[j],j);
                end;

        for j:=i downto 1 do
                ans[i]:=add(ans[i],s[j]);


        {for j:=1 to i do
                begin
                temp:=s[j];
                for k:=2 to j do
                temp:=multiply(temp,k);
                ans[i]:=add(ans[i],temp);

                s[j]:=add(s[j],s[j-1]);

                end;

        for j:=200 downto 1 do
                begin
                temp:=multiply(s[j],j);
                s[j]:=add(temp,s[j-1]);
                end;  }
        end;
end;

BEGIN
MakeAns;
readln(n);
while (n>0) do
        begin
        print(ans[n]);
        readln(n);
        end;
END.
