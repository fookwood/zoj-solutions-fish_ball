program p1057;

{$APPTYPE CONSOLE}
var
        n       :integer;
        showa,showb     :array[1..20]of longint;
        geta,getb       :longint;
        i       :Integer;

PROCEDURE add(p:integer);
begin
if (showa[p]=1)and(showb[p]=2) then inc(geta,6) else
if (showa[p]=2)and(showb[p]=1) then inc(getb,6) else
if (showa[p]-showb[p]=1) then inc(getb,showa[p]+showb[p]) else
if (showb[p]-showa[p]=1) then inc(geta,showa[p]+showb[p]) else
if (showb[p]>showa[p]) then inc(getb,showb[p]) else
if (showa[p]>showb[p]) then inc(geta,showa[p]);
end;


begin
readln(n);
while n<>0 do
        begin
        for I:=1 to n do read(showa[i]);
        readln;
        for i:=1 to n do read(showb[i]);
        readln;
        geta:=0;
        getb:=0;
        for i:=1 to n do add(i);
        writeln('A has ',geta,' points. B has ',getb,' points.');
        readln(n);
        if n<>0 then writeln;
        end;


end.
