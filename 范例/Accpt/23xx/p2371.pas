PROGRAM p2371;

CONST
        maxn=64;

TYPE
        BigNum=array[0..100]of Integer;

VAR
        data                            :array[1..maxn]of BigNum;

PROCEDURE Mulp(var s:BigNum);
var
        temp,i                          :Integer;
begin
temp:=0;
for i:=1 to s[0] do
        begin
        temp:=temp + s[i] * 3;
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

PROCEDURE MakeData;
var
        i                               :Integer;
begin
fillchar(data,sizeof(data),0);
data[1][0]:=1;
data[1][1]:=1;
for i:=2 to 64 do
        begin
        data[i]:=data[i-1];
        Mulp(data[i]);
        end;
end;

PROCEDURE  Print(var s:BigNum);
var
        i                               :Integer;
begin
for i:=s[0] downto 1 do write(s[i]);

end;

PROCEDURE Main;
var
        i                               :Integer;
        first                           :Boolean;
        temp                            :BigNum;
        n                               :Int64;
begin
readln(n);
while (n<>0) do
        begin
        dec(n);
        temp[0]:=0;
        while n>0 do
                begin
                inc(temp[0]);
                temp[temp[0]]:=n mod 2;
                n:=n div 2;
                end;
        write('{');
        first:=true;
        for i:=1 to temp[0] do
                if temp[i]=1 then
                        begin
                        if not first then write(',');
                        write(' ');
                        print(data[i]);
                        first:=false;
                        end;
        writeln(' }');
        readln(n);
        end;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
MakeData;
main;
END.