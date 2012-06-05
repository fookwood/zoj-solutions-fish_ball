program p1543;

{$APPTYPE CONSOLE}

var
        n       :integer;
        m       :array[1..100]of real;
        i       :Integer;

PROCEDURE change(a,b:integer);
var
        temp    :real;
begin
temp:=m[a];
m[a]:=m[b];
m[b]:=temp;
end;

PROCEDURE fly(p:integer);
var
        point   :integer;
begin
if 2*p>n then exit;
if (2*p+1<=n)and(m[2*p+1]>m[2*p]) then point:=2*p+1 else point:=2*p;
if m[point]>m[p] then
        begin
        change(p,point);
        fly(point);
        end;
end;

PROCEDURE make(p:integer);
var
        point   :Integer;
begin
if 2*p>n then exit;
if m[2*p]>m[p] then  point:=2*p else point:=p;
if (2*p+1<=n)and(m[2*p+1]>m[point]) then point:=2*p+1;
if point<>p then
        begin
        change(p,point);
        make(point);
        end;
end;

PROCEDURE main;
var
        i,j     :integer;
        min1    :real;
        min2    :real;
        copy    :integer;
begin
for I:=n div 2 downto 1 do make(i);
copy:=n;
for i:=1 to copy-1 do
        begin
        min1:=m[1];
        change(1,n);
        dec(n);
        make(1);
        min2:=m[1];
        m[1]:=2*sqrt(min1*min2);
        fly(1);
        end;
writeln(m[1]:0:3);
end;

begin
while not eof do
        begin
        readln(n);
        for I:=1 to n do
                readln(m[i]);
        main;
        end;
end.
 