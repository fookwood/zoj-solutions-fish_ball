PROGRAM p1689;

VAR
        total,m,a,b             :Longint;
        whether                 :array[1..100000]of Boolean;
        prime                   :array[1..9592]of Longint;

PROCEDURE MakePrime;
var
        i,j                     :Longint;
begin
fillchar(whether,sizeof(whether),1);
total:=0;
for i:=2 to 100000 do
        if whether[i] then
                begin
                inc(total);
                prime[total]:=i;
                for j:=2 to 100000 div i do
                        whether[i*j]:=false;
                end;
end;

PROCEDURE Main;
var
        down,up                         :Longint;
        i                               :Longint;
        p,q,max,max_p,max_q             :Longint;
begin
max:=0;
for p:=1 to total do
        begin
        if prime[p]*prime[p]>m then break;
        for q:=p to total do
                begin
                if a*prime[q]>b*prime[p] then break;
                if prime[p]*prime[q]>m then break;

                if prime[p]*prime[q]>max then
                        begin
                        max:=prime[p]*prime[q];
                        max_p:=p;
                        max_q:=q;
                        end;
                end;
        end;
writeln(prime[max_p],' ',prime[max_q]);
end;

BEGIN
MakePrime;
while true do
        begin
        readln(m,a,b);
        if (m=0) then break;
        main;
        end;
END.