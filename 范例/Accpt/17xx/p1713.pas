PROGRAM p1713;

CONST
        Stop='e/o/i';

VAR
        s                               :String;
        sin                             :Set of Char;


FUNCTION Check:Boolean;
var
        i,total                         :Integer;
begin
i:=1;
total:=0;
while (s[i]<>'/') do
        begin
        if (s[i] in sin) and not (s[i+1] in sin) then
                begin
                inc(total);
                end;
        inc(i);
        end;
if total<>5 then
        begin
        writeln(1);
        check:=false;
        exit;
        end;


inc(i);
total:=0;
while (s[i]<>'/') do
        begin
        if (s[i] in sin) and not (s[i+1] in sin) then
                inc(total);
        inc(i);
        end;

if total<>7 then
        begin
        writeln(2);
        check:=false;
        exit;
        end;

inc(i);
total:=0;
while (i<=length(s)) do
        begin
        if (i=length(s)) and (s[i] in sin) then inc(total);
        if (i<>length(s)) and (s[i] in sin) and not (s[i+1] in sin) then
                inc(total);
        inc(i);
        end;
if total<>5 then
        begin
        writeln(3);
        check:=false;
        exit;
        end;

check:=true;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
sin:=['a','e','i','o','u','y'];
readln(S);
while (s<>stop) do
        begin
        if check then writeln('Y');
        readln(s);
        end;
END.