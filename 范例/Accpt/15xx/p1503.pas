PROGRAM p1503;

VAR
        n1,m1     :longint;
        step    :integer;
        num     :array[0..30,0..30]of longint;
        whether :array[0..30,0..30]of boolean;
FUNCTION max(a,b:longint):longint;
begin
if a>b then max:=a else max:=b;
end;

FUNCTION ans(n,m:longint):longint;
begin
if whether[n,m] then
        begin
        ans:=num[n,m];
        exit;
        end;
if n=0 then
        begin
        ans:=0;
        num[n,m]:=0;
        exit;
        end else
if m=0 then
        begin
        ans:=n;
        num[n,m]:=n;
        end else
num[n,m]:=ans(n-1,m)+ans(n-1,m-1)+1;
ans:=num[n,m];
whether[n,m]:=true;
end;

BEGIN
readln(n1,m1);
step:=0;
while (n1<>0)or(m1<>0) do
        begin
        inc(step);
        write('Case ',step,': ');
        writeln(ans(n1,m1));
        readln(n1,m1);
        end;
END.