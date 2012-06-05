PROGRAM P1760;

VAR
        num     :array[1..99]of boolean;
        n,k     :integer;


FUNCTION ans:longint;
var     I       :integer;
        temp    :longint;
begin
temp:=0;
for i:=1 to 49 do
        if (num[i])and(num[2*i]) then inc(temp);
ans:=temp;
end;

BEGIN
read(n);
while n<>-1 do
        begin
        fillchar(num,sizeof(num),false);
        while n<>0 do
                begin
                num[n]:=true;
                read(n);
                end;
        writeln(ans);
        readln;
        read(n);
        end;
END.