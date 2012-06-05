PROGRAM P1508;

TYPE
        node=record
                s,t,c                   :Longint;
        end;

VAR
        n,i,max                         :Longint;
        edge                            :array[1..50000]of Node;
        d                               :array[0..50000]of Longint;

PROCEDURE Bellman_ford;
var
        infinity                        :Longint;
        i                               :Longint;
        flag                            :Boolean;
begin
for i:=0 to max do d[i]:=0;
repeat
        flag:=true;
        for I:=1 to n do
                with edge[i] do
                if (d[s-1]>d[t]-c) then
                        begin
                        flag:=false;
                        d[s-1]:=d[t]-c;
                        end;
        for i:=1 to max do
                if (d[i]-1>d[i-1]) then
                        begin
                        flag:=false;
                        d[i]:=d[i-1]+1;
                        end;
        for I:=max downto 1 do
                if (d[i-1]>d[i]) then
                        begin
                        flag:=false;
                        d[i-1]:=d[i];
                        end;
until flag;
writeln(d[max]-d[0]);
end;

BEGIN
while not eof do
        begin
        readln(n);
        max:=0;
        for I:=1 to n do
                begin
                readln(edge[i].s,edge[i].t,edge[i].c);
                if edge[i].t>max then max:=edge[i].t;
                end;
        Bellman_ford;
        end;
END.