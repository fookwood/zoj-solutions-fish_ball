PROGRAM p1501;

VAR
        n,i,j,q,a                       :Integer;
        num,min,max                     :array[1..512]of Longint;
        order,sum                       :array[0..9]of Longint;


PROCEDURE MakeOrder;
var
        i                               :Integer;
begin
order[0]:=1;
sum[0]:=1;
order[1]:=2;
sum[1]:=3;
for i:=2 to 9 do
        begin
        order[i]:=order[i-1]*2;
        sum[i]:=sum[i-1]+order[i];
        end;
end;

PROCEDURE Main;
var
        i,j                                     :Integer;
begin
min[1]:=1;
max[1]:=1;
for j:=2 to n+1 do
for i:=sum[j-1]-order[j-1]+1 to sum[j-1] do
        if num[i]=num[i div 2] then
                begin
                min[i]:=min[i div 2];
                max[i]:=max[i div 2];
                end else
                begin
                min[i]:=min[i div 2]+1;
                max[i]:=order[n]-order[n-j+1]+1;
                end;

{for i:=1 to sum[n] do
        write(i:3);
writeln;
for I:=1 to sum[n] do
        write(max[i]:3);
writeln;}
end;

BEGIN
//assign(input,'p.in');
//reset(input);
MakeOrder;
readln(n);
while (n<>0) do
        begin
        for i:=n downto 1 do
                for j:=sum[i-1]-order[i-1]+1 to sum[i-1] do
                        read(num[j]);
        for j:=sum[n]-order[n]+1 to sum[n] do num[j]:=j-sum[n]+order[n];
        readln;
        read(q);
        Main;
        for i:=1 to q do
                begin
                read(a);
                writeln('Player ',a,' can be ranked as high as ',min[sum[n-1]+a],' or as low as ',max[sum[n-1]+a],'.');
                end;

        readln(n);
        if n<>0 then writeln;

        end;
END.