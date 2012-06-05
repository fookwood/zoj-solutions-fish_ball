PROGRAM p2362;

CONST
        maxn=1030000;

VAR
	n			:Longint;
	order			:array[0..13]of Longint;
        whether                 :array[0..maxn]of Boolean;

PROCEDURE MakeOrder;
var
	i,j	:Longint;
begin
order[0]:=1;
for i:=1 to 10 do order[i]:=order[i-1] * i;
fillchar(whether,sizeof(whether),0);
whether[0]:=true;
for i:=0 to 10 do
        for j:=maxn-order[i] downto 0 do if whether[j] then whether[j+order[i]]:=true;
end;

PROCEDURE Main;
begin
readln(n);
while (n>=0) do
begin
if (whether[n])and(n<>0) then writeln('YES') else writeln('NO');
readln(n);
end;
end;

BEGIN
MakeOrder;
Main;
END.
