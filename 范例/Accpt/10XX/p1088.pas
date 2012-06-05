PROGRAM P1088;

VAR
        n       :integer;

FUNCTION check(p:integer):boolean;
var     have    :array[0..150]of boolean;
        g       :integer;
        i       :Integer;
        j       :Integer;
begin
fillchar(have,sizeof(have),false);
have[1]:=true;
g:=1;
for i:=1 to n-2 do
begin
j:=0;
while j<p do
        begin
        g:=(g+1) mod n;
        if not have[g] then inc(j);
        end;
if g=2 then
begin
check:=false;
exit;
end;
have[g]:=true;
end;
check:=true;
end;

FUNCTION solve:integer;
var     d       :Integer;
begin
d:=2;
while not check(d) do
begin
inc(d);
end;
solve:=d;
end;

BEGIN
readln(N);
while n<>0  do
        begin
        writeln(solve);
        readln(n);
        end;
END.