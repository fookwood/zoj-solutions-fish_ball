PROGRAM p2320;

TYPE
        parr=^arr;
        arr=array[1..541]of Boolean;
        BigNum=array[0..100]of Integer;

VAR
        total,part,p,n,m,sa,sb  :Integer;
        prime,linkn,linkm       :array[1..100]of Integer;
        A                       :array[1..100,1..100]of 0..1;
        ans                     :BigNum;

PROCEDURE Print(var t:BigNum);
var
        i                       :Integer;
begin
for I:=t[0] downto 1 do write(t[i]);
writeln;
end;

PROCEDURE Mul(var t:BigNum;p:Integer);
var
        i,temp                  :Integer;
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

PROCEDURE MakePrime;
var
        i,j                     :Integer;
        num                     :Parr;
begin
getmem(num,sizeof(arr));
fillchar(num^,sizeof(arr),1);
total:=0;
i:=2;
for i:=2 to 541 do
        if num^[i] then
                begin
                inc(total);
                prime[total]:=i;
                for j:=2 to 541 div i do
                        num^[i*j]:=false;
                end;
freemem(num,sizeof(arr));
end;

PROCEDURE Readin;
var
        num                             :Longint;
        i,j                             :Integer;
begin
readln(m,n);
fillchar(A,sizeof(A),0);
for i:=1 to n do
        begin
        j:=1;
        read(num);
        while (j<=m) do
                if num mod prime[j]=0 then
                        begin
                        num:=num div prime[j];
                        A[i][j]:=(A[i][j]+1) mod 2;
                        end else inc(j);
        end;
readln;
end;

PROCEDURE Change(var a,b:Integer);
var
        temp                            :Integer;
begin
temp:=a;
a:=b;
b:=temp;
end;

FUNCTION Find(p:Integer):Boolean;
var
        i,j                             :Integer;
begin
Find:=true;
if (sa<>0)and(sb<>0) and (A[linkn[sa]][linkm[sb]]=1) then
        begin
        change(linkn[sa],linkn[p]);
        change(linkm[sb],linkm[p]);
        exit;
        end;
for i:=p to n do
        for J:=p to m do
                if A[linkn[i]][linkm[j]]=1 then
                        begin
                        change(linkn[i],linkn[p]);
                        change(linkm[j],linkm[p]);
                        exit;
                        end;
find:=false;
end;

PROCEDURE PrintMatrix;
var
        i,j                             :Integer;
begin
writeln('here is the matrix:');
for i:=1 to n do
        begin
        for j:=1 to m do write(a[linkn[i]][linkm[j]]);
        writeln;
        end;

end;

PROCEDURE main;
var
        i,j,k                           :Integer;
begin
for i:=1 to n do linkn[i]:=i;
for i:=1 to m do linkm[i]:=i;
i:=1;
sa:=0;sb:=0;
while (i<=n) do
        begin
        if find(i) then
                begin
                for j:=i+1 to n do
                        if A[linkn[j]][linkm[i]]=1 then
                                for k:=i to m do
                                        begin
                                        A[linkn[j]][linkm[k]]:=abs(A[linkn[j]][linkm[k]]-A[linkn[i]][linkm[k]]);
                                        if A[linkn[j]][linkm[k]]=1 then
                                                begin
                                                sa:=j;
                                                sb:=k;
                                                end;
                                        end;
                end else break;
        inc(i);
        end;
dec(n,i-1);
ans[1]:=1;
ans[0]:=1;
for i:=1 to n div 3 do
        mul(ans,8);
for i:=1 to n mod 3 do
        mul(ans,2);
dec(ans[1]);
if ans[1]=0 then writeln(0) else
        print(ans);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
MakePrime;
readln(part);
for p:=1 to part do
        begin
        Readin;
        Main;
        if p<part then writeln;
        end;
END.
