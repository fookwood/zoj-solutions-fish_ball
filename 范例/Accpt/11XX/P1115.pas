PROGRAM P1115;


VAR
        i       :integer;
        num     :longint;
        s       :string;

FUNCTION ans:integer;
var     copy    :longint;
        n       :longint;
begin
n:=num;
while n>=10 do
        begin
        copy:=0;
        while n>0 do
                begin
                copy:=copy+(n mod 10);
                n:=n div 10;
                end;
        n:=copy;
        end;
ans:=n;
end;

BEGIN
readln(s);
while s<>'0' do
        begin
        num:=0;
        for i:=1 to length(s) do
        num:=num+ord(s[i])-48;
        writeln(ans);
        readln(s);
        end;
END.