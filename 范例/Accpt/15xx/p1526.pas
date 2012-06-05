PROGRAM p_unknow;

VAR
        n       :longint;
        k       :integer;
        i       :integer;
        e       :extended;


FUNCTION p:longint;
var
        a,b       :extended;
begin
a:=sqrt(2*3.141592658*n);
b:=n/2.7182815;
a:=ln(a)/ln(10);
b:=ln(b)/ln(10);
p:=trunc(a+n*b)+1;
end;

BEGIN
readln(k);
for i:=1 to k do
        begin
        readln(n);
        writeln(p);
        end;
END.
