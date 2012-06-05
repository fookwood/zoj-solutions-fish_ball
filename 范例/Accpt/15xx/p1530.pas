PROGRAM p1530;


VAR
        puss    :array[1..200]of integer;
        num     :integer;
        n       :Integer;
        what    :array[1..200]of integer;
        whether :array[0..200]of boolean;
        leave   :array[1..200]of integer;



PROCEDURE print(p:integer);
begin
if p=1 then write(1)
        else
        begin
        print(puss[p]);
        write(what[p]);
        end;
end;

PROCEDURE wfs;

var
        s,t     :integer;
        find    :boolean;
begin
if n=1 then
        begin
        writeln(1);
        exit;
        end;
fillchar(whether,sizeof(whether),false);
s:=1;
t:=1;
puss[1]:=0;
what[1]:=1;
whether[1]:=true;
leave[1]:=1;
find:=false;
repeat
if not whether[(leave[s]*10) mod n] then
        begin
        inc(t);
        leave[t]:=(leave[s]*10) mod n;
        what[t]:=0;
        whether[(leave[s]*10) mod n]:=true;
        puss[t]:=s;
        if whether[0] then find:=true;
        end;
if (not find)and(not whether[(leave[s]*10+1) mod n]) then
        begin
        inc(t);
        leave[t]:=(leave[s]*10+1) mod n;
        what[t]:=1;
        whether[(leave[s]*10+1) mod n]:=true;
        if whether[0] then find:=true;
        puss[t]:=s;
        end;
inc(s);
until find;
print(t);
writeln;
end;

BEGIN
readln(n);
while n<>0 do
        begin
        wfs;
        readln(n);
        end;
END.