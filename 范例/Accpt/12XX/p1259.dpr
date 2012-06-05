program p1259;

{$APPTYPE CONSOLE}

var
        n       :Integer;
        s,t     :array[1..1200]of integer;
        l       :Integer;
        i       :Integer;

FUNCTION push:integer;
begin
if l=0 then push:=0 else
begin
push:=s[l];
dec(l);
end;
end;

PROCEDURE get(p:integer);
begin
inc(l);
s[l]:=p;
end;

PROCEDURE main;
var
        i,j     :Integer;
begin
j:=1;
for i:=1 to n do
        begin
        if j>t[i] then
                if push<>t[i] then
                        begin
                        writeln('No');
                        exit;
                        end;
        while j<t[i] do
                begin
                get(j);
                inc(j);
                end;
        if j=t[i] then inc(j);
        end;
writeln('Yes');
end;

begin
readln(n);
while n<>0 do
        begin
        read(t[1]);
        while t[1]<>0 do
                begin
                i:=1;
                l:=0;
                if t[1]<>0 then while (i<n) do
                        begin
                        inc(i);
                        read(t[i]);
                        end;
                readln;
                main;
                read(t[1]);
                end;
        readln;
        writeln;
        readln(n);
        end;
end.
