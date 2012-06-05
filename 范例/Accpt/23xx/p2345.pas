PROGRAM p2345;

VAR
        part,p                  :Integer;
        n                       :Integer;
        ans                     :array[0..10000]of Longint;

PROCEDURE MakeAns;
var
        i,j,p                   :Integer;
begin;
i:=1;
p:=0;
ans[0]:=0;
while (i<=10000) do
        begin
        j:=1;
        inc(p);
        while (i<=10000)and(j<=p) do
                begin
                ans[i]:=ans[i-1]+p;
                inc(i);
                inc(j);
                end;
        end;
end;

BEGIN
Makeans;
readln(part);
for p:=1 to part do
        begin
        readln(n);
        while (n<>0) do
                begin
                writeln(n,' ',ans[n]);
                readln(n);
                end;
        if p<part then writeln;
        end;
END.