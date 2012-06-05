PROGRAM p1619;

VAR
        n,m     :Integer;




FUNCTION ans(n:Integer):extended;
var
        p,m     :extended;
        i       :integer;
        ch      :integer;
begin
if n=1 then ans:=0 else
        if n=0 then ans:=1 else
begin
p:=0;
m:=1;
ch:=-1;
for i:=2 to n do
        begin
        m:=m*i;
        ch:=ch*(-1);
        p:=p+ch/m;
        end;
ans:=p;
end;
end;


FUNCTION jiecheng(m:integer):extended;
var
        I       :integer;
        p       :extended;
begin
p:=1;
for i:=2 to m do
        p:=p*i;
jiecheng:=p;
end;

BEGIN
while not eof do
        begin
        readln(n,m);
        if n<m then writeln('0.00000000') else
        writeln(ans(n-m)/jiecheng(m):0:8);
        end;
END.
