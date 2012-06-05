PROGRAM p2383;

VAR
        n                       :Integer;
        pos                     :array[0..10000]of Integer;
        num                     :array[1..10000]of Integer;

FUNCTION check:Boolean;
var
        i,j,k                   :Integer;
begin
for i:=1 to n-2 do
        for j:=i+1 to n-1 do
                begin
                k:=num[j]+num[j]-num[i];
                if (k>=0)and(k<n)and(pos[k]>j) then
                        begin
                        Check:=true;
                        exit;
                        end;
                end;
check:=false;
end;

PROCEDURE Readin;
var
        i                               :Integer;
        ch                              :Char;
begin
read(ch);
n:=0;
while (ch<>':')and not eoln do
        begin
        n:=n * 10 +ord(ch)-48;
        read(ch);
        end;
if n=0 then halt;
for i:=1 to n do
        begin
        read(num[i]);
        pos[num[i]]:=i;
        end;
readln;
end;

BEGIN
while true do
        begin
        readin;
        if not check then writeln('yes')
                else writeln('no');
        end;
END.