PROGRAM p1449;

VAR
        n                               :Integer;
        map,sum                         :array[0..20,0..20,0..20]of Longint;

PROCEDURE Readin;
var
        add                             :Longint;
        i,j,k,p,q                       :Integer;
begin
fillchar(sum,sizeof(sum),0);
for i:=1 to n do
        for j:=1 to n do
                begin
                for k:=1 to n do
                        begin
                        read(map[i,j,k]);
                        add:=0;
                        for p:=1 to i do
                                for q:=1 to j do inc(add,map[p,q,k]);
                        sum[i,j,k]:=sum[i,j,k-1]+add;
                        end;
                readln;
                end;
end;

PROCEDURE Main;
var
        i,j,k,p,q,r                             :Integer;
        max                                     :Integer;
        temp                                    :Integer;
begin
max:=-maxint;
for i:=1 to n do
for j:=1 to n do
for k:=1 to n do
for p:=i to n do
for q:=j to n do
for r:=k to n do
        begin
        temp:=sum[p,q,r]+sum[i-1,j-1,r]+sum[i-1,q,k-1]+sum[p,j-1,k-1]
                -sum[i-1,q,r]-sum[p,j-1,r]-sum[p,q,k-1]-sum[i-1,j-1,k-1];
        if temp>max then max:=temp;
        end;
writeln(max);
end;

BEGIN
assign(input,'p.in');
reset(input);
readln(n);
while n<>0 do
        begin
        Readin;
        Main;
        readln(n);
        end;
END.
