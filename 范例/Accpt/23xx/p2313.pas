PROGRAM p2313;

TYPE
        BigNum=array[0..2020]of Integer;

VAR
        ch                                      :Char;
        part,p                                  :Longint;
        num                                     :BigNum;


PROCEDURE Print(var d:BigNum);
var
        i                                       :Integer;
begin
for i:=d[0] downto 1 do write(d[i]);
writeln;
end;

PROCEDURE Divp;
var
        i,temp                                  :Integer;
begin
temp:=0;
for i:=num[0] downto 1 do
        begin
        temp:=temp*10+num[i];
        num[i]:=temp div 2;
        temp:=temp mod 2;
        end;
if num[num[0]]=0 then dec(num[0]);
end;

PROCEDURE subtration(p:Integer);
var
        i                                       :Integer;
begin
if num[1]>=p then dec(num[1],p) else
        begin
        num[1]:=num[1]+10-p;
        i:=2;
        while num[i]=0 do
                begin
                num[i]:=9;
                inc(i);
                end;
        dec(num[i]);
        if num[num[0]]=0 then dec(num[0]);
        end;
end;


PROCEDURE Main;
var
        i,flag                                  :Integer;
begin
flag:=num[2]*10+num[1];

Divp;

if odd(flag) then
        print(num)
                else
if flag mod 4=0 then
        begin
        subtration(1);
        print(num);
        end else
        begin
        subtration(2);
        print(num);
        end;
end;

PROCEDURE Change;
var
        i,temp                                  :Integer;
begin
for i:=1 to num[0] div 2 do
        begin
        temp:=num[i];
        num[i]:=num[num[0]-i+1];
        num[num[0]-i+1]:=temp;
        end;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(part);
for p:=1 to part do
        begin
        readln;
        num[0]:=0;
        repeat
                read(ch);
                inc(num[0]);
                num[num[0]]:=ord(ch)-48;
        until eoln;

        Change;

        Main;
        if p<part then writeln;
        readln;
        end;
END.