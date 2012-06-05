program p1195;

{$APPTYPE CONSOLE}

var
        n,m,c           :longint;
        i               :integer;
        max             :longint;
        now             :longint;
        temp            :longint;
        sta             :array[1..20]of boolean;
        leave           :array[1..20]of longint;
        step            :Integer;

PROCEDURE main;
var
        i               :longint;
        can             :boolean;
begin
writeln('Sequence ',step);
fillchar(sta,sizeof(sta),false);
max:=0;now:=0;
can:=true;
for i:=1 to m do
        begin
        readln(temp);
        if not sta[temp] then
                begin
                sta[temp]:=true;
                inc(now,leave[temp]);
                if (now >c)and(can) then
                        begin
                        writeln('Fuse was blown.');
                        can:=false;
                        end;
                if now>max then max:=now;
                end else
                begin
                sta[temp]:=false;
                now:=now-leave[temp];
                end;
        end;
if can then
        begin
        writeln('Fuse was not blown.');
        writeln('Maximal power consumption was ',max,' amperes.');
        end;
writeln;
end;

begin
readln(n,m,c);
step:=0;
while (n<>0)or(m<>0)or(c<>0) do
        begin
        inc(steP);
        for I:=1 to n do
                readln(leave[i]);
        main;
        readln(n,m,c);
        end;
end.
