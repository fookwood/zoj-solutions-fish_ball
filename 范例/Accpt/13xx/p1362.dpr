program p1362;

{$APPTYPE CONSOLE}

var
        leave   :array[1..1000]of boolean;
        n,m     :integer;
        have    :array[1..50]of integer;
        i       :Integer;
        ans     :longint;
        step    :integer;


PROCEDURE sort;
var
        i,j     :integer;
        temp    :Integer;
begin
for I:=1 to m-1 do
        for J:=i+1 to m do
        if have[i]<have[j] then
                begin
                temp:=have[i];
                have[i]:=have[j];
                have[j]:=temp;
                end;
end;

PROCEDURE makeans;
var
        i,j     :Integer;
        live    :boolean;
        p       :integer;
        q       :integer;
begin
for I:=1 to m do
        begin
        live:=true;
        for j:=have[i] to n*m do if leave[j] then
                begin
                live:=false;
                q:=j;
                break;
                end;
        if live then
                begin
                inc(ans);
                j:=0;
                p:=1;
                repeat
                if leave[p] then
                        begin
                        leave[p]:=false;
                        inc(j);
                        end;
                inc(p);
                until j=n-1;
                end else
                begin
                leave[q]:=false;
                j:=0;
                p:=1;
                repeat
                if leave[p] then
                        begin
                        leave[p]:=false;
                        inc(j);
                        end;
                inc(p);
                until  j=n-2;
                end;
        end;
end;

begin
readln(n,m);
step:=0;
while (n<>0)or(m<>0) do
        begin
        ans:=0;
        inc(step);
        fillchar(leave,sizeof(leave),true);
        for I:=1 to m  do
                begin
                read(have[i]);
                leave[have[i]]:=false;
                end;
        readln;
        readln;
        sort;
        makeans;
        writeln('Case ',step,': ',ans);
        readln(n,m);
        end;
end.
 