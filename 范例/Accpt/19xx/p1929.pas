PROGRAM p1929;

TYPE
        BigNum          =       array[0..1000]of Integer;

VAR
        a                       :BigNum;
        b,m                     :Longint;

PROCEDURE Readin;
var
        ch                      :Char;
begin
read(b);
if b=0 then halt;
read(ch);
while (ch=' ') do read(ch);
a[0]:=0;
while (ch<>' ') do
        begin
        inc(a[0]);
        a[a[0]]:=ord(ch)-48;
        read(ch);
        end;

m:=0;
while not eoln do
        begin
        read(ch);
        m:=m * b + ord(ch) - 48;
        end;
readln;
end;

PROCEDURE Print(p:Longint);
begin
if p=0 then exit;
print(p div b);
write(p mod b);
end;

PROCEDURE Main;
var
        i,temp                          :Longint;
begin
if m=0 then
        begin
        for i:=1 to a[0] do write(a[i]);
        writeln;
        exit;
        end;
temp:=0;
for i:=1 to a[0] do
        begin
        temp:=temp * b + a[i];
        temp:=temp mod m;
        end;
if temp=0 then write(0);
print(temp);
writeln;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
while true do
        begin
        Readin;
        Main;
        end;
END.
