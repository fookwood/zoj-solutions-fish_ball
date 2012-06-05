PROGRAM p1969;

TYPE
        BigNum= array[0..1000]of Integer;

VAR
        a,b,c                           :BigNum;

PROCEDURE Short(var s:BigNum);
begin
while (s[0]>1)and(s[s[0]]=0) do dec(s[0]);
end;

PROCEDURE Print(var s:BigNum);
var
        i                               :Integer;
begin
for i:=s[0] downto 1 do write(s[i]);
writeln;
end;

PROCEDURE Readin;
var
        ch                              :Char;
begin

fillchar(a,sizeof(a),0);
fillchar(b,sizeof(b),0);
fillchar(c,sizeof(c),0);

a[0]:=0;
read(ch);
while (ch<>'+') do
        begin
        inc(a[0]);
        a[a[0]]:=ord(ch)-48;
        read(ch);
        end;

b[0]:=0;
read(ch);
while (ch<>'=') do
        begin
        inc(b[0]);
        b[b[0]]:=ord(ch)-48;
        read(ch);
        end;

c[0]:=0;
while (not eoln) do
        begin
        read(ch);
        inc(c[0]);
        c[c[0]]:=ord(ch)-48;
        end;
readln;
short(a);
short(b);
short(c);
end;


PROCEDURE Add(var s,t:BigNum);
var
        i,temp                          :Integer;
begin
temp:=0;
if t[0]>s[0] then s[0]:=t[0];
for i:=1 to s[0] do s[i]:=s[i]+t[i];
for i:=1 to s[0] do
        begin
        temp:=temp + s[i];
        s[i]:=temp mod 10;
        temp:=temp div 10;
        end;
while (temp>0) do
        begin
        inc(s[0]);
        s[s[0]]:=temp mod 10;
        temp:=temp div 10;
        end;
end;

FUNCTION Check:Boolean;
var
        i,max                           :Integer;
begin
//print(a);
//print(b);
Add(a,b);
//print(a);
//print(c);
if a[0]>c[0] then max:=a[0]+1 else max:=c[0]+1;
for i:=0 to max do
        if a[i]<>c[i] then
                begin
                check:=false;
                exit;
                end;
check:=true;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
//assign(output,'p.out');
//rewrite(output);
while not eof do
        begin
        Readin;
        if check then writeln('True') else writeln('False');
        end;
//close(output);
END.
