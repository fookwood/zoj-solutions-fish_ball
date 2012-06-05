program p1314;

{$APPTYPE CONSOLE}

var
        m,n     :longint;
        s       :longint;


FUNCTION gcd(a,b:longint):longint;
begin
if a=0 then gcd:=b else
        gcd:=gcd(b mod a,a);
end;


begin
while not eof do
        begin
        readln(n,m);
        if n>m then s:=gcd(m,n) else s:=gcd(n,m);
        if s=1 then
                writeln(n:10,m:10,'    Good Choice') else
                writeln(n:10,m:10,'    Bad Choice');
        writeln;
        end;
end.
 