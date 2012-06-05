PROGRAM P1062;


VAR
        n       :int64;
        data    :array[0..30]of int64;



PROCEDURE print(num:int64;p:integer);
var
        k       :Integer;
        least   :integer;
        sum     :int64;
begin
if p=0 then exit;
if data[p-1]>=num then
        begin
        write('(');
        write('X');
        print(num,p-1);
        write(')');
        end else
        begin
        sum:=data[p-1];
        for k:=1 to p-1 do
                begin
                sum:=sum+data[k]*data[p-1-k];
                if sum>=num then break;
                end;
        sum:=sum-data[k]*data[p-1-k];
        write('(');
        if (num-sum ) mod data[p-1-k]=0 then
                print((num-sum) div data[p-1-k],k)
                        else
                        print((num-sum) div data[p-1-k]+1,k);
        write('X');
        if (num-sum) mod data[p-1-k]=0  then
                print(data[p-1-k],p-1-k)
                        else
                        print((num-sum) mod data[p-1-k],p-1-k);
        write(')');
        end;
end;

PROCEDURE ans;
var
        k       :integer;
        sum     :int64;
        num     :int64;
        p       :integer;
begin
sum:=0;
for k:=1 to 20 do
        begin
        sum:=sum+data[k];
        if sum>=n then break;
        end;
num:=n-(sum-data[k]);
p:=k;

if data[p-1]>=num then
        begin
        write('X');
        print(num,p-1);
        end else
        begin
        sum:=data[p-1];
        for k:=1 to p-1 do
                begin
                sum:=sum+data[k]*data[p-1-k];
                if sum>=num then break;
                end;
        sum:=sum-data[k]*data[p-1-k];
        if (num-sum ) mod data[p-1-k]=0 then
                print((num-sum) div data[p-1-k],k)
                        else
                        print((num-sum) div data[p-1-k]+1,k);
        write('X');
        if (num-sum) mod data[p-1-k]=0  then
                print(data[p-1-k],p-1-k)
                        else
                        print((num-sum) mod data[p-1-k],p-1-k);
        end;

writeln;
end;


PROCEDURE makedata;
var
        i,j     :integer;
        k       :integer;
begin
data[0]:=1;
data[1]:=1;
for K:=2 to 20 do
        begin
        data[k]:=1;
        j:=2;
        for i:=k+2 to 2*k do
                begin
                data[k]:=data[k]*i;
                while (j<=k)and(data[k] mod j=0) do
                        begin
                        data[k]:=data[k] div j;
                        inc(j);
                        end;
                end;
        end;
end;


BEGIN
makedata;
readln(n);
while n<>0 do
        begin
        ans;
        readln(n);
        end;
END.