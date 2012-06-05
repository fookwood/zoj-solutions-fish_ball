PROGRAM p2203;

VAR
        n,m,d,i                              :Integer;
        prime                                :array[1..10000]of Boolean;
        add                                  :array[1..1000]of Boolean;
        puss                                 :array[1..1000]of Integer;
        find                                 :Boolean;

PROCEDURE makePrime;
var
        i,j                                     :Integer;
begin
fillchar(prime,sizeof(prime),1);
prime[1]:=false;
for i:=1 to 10000 do
        if prime[i] then
                for j:=2 to 10000 div i do
                        prime[i*j]:=false;
end;


PROCEDURE Search(dep:Integer);
var
        sum                                     :Integer;
        i,j                                     :Integer;
        flag                                    :Boolean;
begin
if dep=m-n+2 then find:=true;
if dep>m-n+2 then exit;
if find then exit;
for i:=n to m do
        if not add[i] then
        begin
        flag:=true;
        sum:=i;
        for j:=1 to d-1 do
                if dep>j then
                begin
                sum:=sum+puss[dep-j];
                if prime[sum] then
                        begin
                        flag:=false;
                        break;
                        end;
                end;
        if flag then
                begin
                puss[dep]:=i;
                add[i]:=true;
                search(dep+1);
                if find then exit;
                add[i]:=false;
                end;
        end;
end;

BEGIN
makeprime;
readln(n,m,d);
while (n<>0)or(m<>0)or(d<>0) do
        begin
        fillchar(add,sizeof(add),0);
        find:=false;
        Search(1);
        if find then for i:=1 to m-n do write(puss[i],',');
        if find then writeln(puss[m-n+1]) else
        writeln('No anti-prime sequence exists.');
        readln(n,m,d);
        end;
END.