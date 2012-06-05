PROGRAM p1652;

VAR
        n                               :Integer;
        num                             :array[0..10000]of Longint;

PROCEDURE MakeNum;
var
        i                               :Integer;
begin
num[0]:=1;
for i:=0 to 9999 do
        num[i+1]:=num[i] + ( 3 * i +1) * 3;
end;

BEGIN
MakeNum;
while not eof do
        begin
        readln(n);
        writeln(num[n]-2 * n);
        end;
END.