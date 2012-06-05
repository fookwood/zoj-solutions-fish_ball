PROGRAM p1229;

VAR
        total,goal                      :Integer;
        find,can                            :Boolean;

PROCEDURE Search(dep,pos:Integer);
begin
if find then exit;
if pos=goal then
        begin
        find:=true;
        exit;
        end;
if pos-dep>0 then Search(dep+2,pos-dep);
if pos+dep<=total then Search(dep+2,pos+dep);
end;

BEGIN
readln(total,goal);
while (total<>0)or(goal<>0) do
        begin
        if total<49 then find:=false else find:=true;
        if total<49 then search(1,0);
        if find then writeln('Let me try!') else
                writeln('Don','''','t make fun of me!');
        readln(total,goal);
        end;
END.