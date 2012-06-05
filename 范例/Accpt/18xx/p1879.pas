PROGRAM p1879;

VAR
        whether :array[1..4000]of boolean;
        n       :longint;
        num     :array[1..4000]of longint;
        i       :longint;

FUNCTION check:boolean;
var
        i,p     :longint;

begin
if n=1 then begin check:=true; exit; end;
fillchar(whether,sizeof(whether),false);
for I:=2 to n do
        begin
        p:=abs(num[i]-num[i-1]);
        if (p=0)or(p>=n) then
                begin
                check:=false;
                exit;
                end;
        if whether[p] then
                begin
                check:=false;
                exit;
                end else whether[p]:=true;
        end;
check:=true;
end;

BEGIN
while not eof do
        begin
        read(n);
        for I:=1 to n do
                read(num[i]);
        if check then writeln('Jolly') else writeln('Not jolly');
        readln;
        end;
END.