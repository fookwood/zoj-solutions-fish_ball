PROGRAM p1814;

VAR
        i       :Integer;
        sweat,add       :array[1..10000]of integer;
        n       :integer;
        step    :Integer;


FUNCTION check:boolean;
var
        i       :Integer;
begin
for i:=2 to n do
        if sweat[i]<>sweat[i-1] then
                begin
                check:=false;
                exit;
                end;
check:=true;
end;

PROCEDURE main;
var
        i,j     :integer;
begin
step:=0;
while not check do
        begin
        inc(step);
        fillchar(add,sizeof(add),0);
        for i:=2 to n do
                begin
                add[i-1]:=add[i-1]+sweat[i] div 2;
                sweat[i]:=sweat[i] div 2;
                end;
        add[n]:=add[n]+sweat[1] div 2;
        sweat[1]:=sweat[1] div 2;
        for I:=1 to n do
                begin
                sweat[i]:=sweat[i]+add[i];
                if odd(sweat[i]) then inc(sweat[i]);
                end;

        end;
writeln(step,' ',sweat[1]);
end;

BEGIN
readln(n);
while n<>0 do
        begin
        for i:=1 to n do
                readln(sweat[i]);
        main;
        readln(n);
        end;
END.