PROGRAM p2393;

{$APPTYPE CONSOLE}

CONST
        maxn=70000;

TYPE
        BigNum=array[0..maxn]of Longint;

VAR
        n,total                         :Integer;
        availuble                       :array[1..2]of Longint;
        ans,a                           :BigNum;

PROCEDURE print;
var
        i                               :Longint;
begin
for i:=ans[0] downto 1 do
        write(ans[i]);
writeln;
end;

FUNCTION Kfs:Boolean;
var
        i,s,t,p                         :Longint;
        find                            :Boolean;
        prev,line,leave                 :array[0..maxn+100]of Longint;
        reach                           :array[0..maxn+100]of Boolean;
begin
fillchar(reach,sizeof(reach),0);
s:=1;
t:=0;
for i:=1 to total do
        if availuble[i]<>0 then
                begin
                inc(t);
                line[t]:=availuble[i] mod n;
                leave[t]:=availuble[i] mod n;
                reach[leave[t]]:=true;
                if leave[t]=0 then
                        begin
                        a[0]:=1;
                        a[1]:=availuble[i];
                        Kfs:=true;
                        exit;
                        end;
                prev[t]:=0;
                end;
find:=false;
repeat
        for i:=1 to total do
                begin
                p:=(leave[s] * 10 + availuble[i]) mod n;
                if not reach[p] then
                        begin
                        inc(t);
                        line[t]:=availuble[i];
                        leave[t]:=p;
                        reach[p]:=true;
                        prev[t]:=s;
                        end;
                if reach[0] then break;
                end;
        if reach[0] then
                begin
                find:=true;
                a[0]:=0;
                p:=t;
                while (p<>0) do
                        begin
                        inc(a[0]);
                        a[a[0]]:=line[p];
                        p:=prev[p];
                        end;
                break;
                end;
        inc(s);
until s>t;
Kfs:=find;
end;


FUNCTION comp(var a,b:BigNum):Integer;
var
        i                               :Longint;
begin
if a[0]>b[0] then comp:=1
        else
if a[0]<b[0] then comp:=-1
        else
        begin
        i:=a[0];
        while (i>1)and(a[i]=b[i]) do dec(i);
        if a[i]>b[i] then comp:=1 else
        if a[i]<b[i] then comp:=-1 else
        comp:=0;
        end;
end;

PROCEDURE Main;
var
        have                            :Boolean;
        i,j                             :Longint;
begin
ans[0]:=maxint;
have:=false;
for i:=1 to 9 do
        begin
        total:=1;
        availuble[1]:=i;
        if Kfs and (comp(a,ans)<0) then
                begin
                ans:=a;
                have:=true;
                end;
        end;

if have then
        begin
        print;
        exit;
        end; 

total:=2;

for i:=0 to 8 do
        for J:=i+1 to 9 do
                begin
                availuble[1]:=i;
                availuble[2]:=j;
                if Kfs then
                        if (comp(a,ans)<0) then ans:=a;
                end;

print;
end;

BEGIN
readln(n);
while (n<>0) do
        begin
        Main;
        readln(n);
        end;
END.