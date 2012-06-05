program p1239;

{$APPTYPE CONSOLE}
var
        n       :Integer;
        data    :array[1..50]of longint;
        ans     :longint;
        k       :integer;
        team    :integer;
        j       :Integer;

PROCEDURE search(dep:integer);
var
        i       :Integer;
        have    :integer;
        temp    :integer;
        can     :boolean;
begin
if dep>ans then ans:=dep;
have:=1;
can:=false;
while (have<=n)and(data[have]<>-1) do inc(have);
for i:=1 to have-1 do
        if trunc(sqrt(dep+data[i]))=sqrt(dep+data[i]) then
                begin
                can:=true;
                temp:=data[i];
                data[i]:=dep;
                search(dep+1);
                data[i]:=temp;
                end;
if (have<=n)and(not can) then
        begin
        data[have]:=dep;
        search(dep+1);
        data[have]:=-1;
        end;
end;

begin
readln(k);
for team:=1 to k do
        begin
        readln(n);
        for j:=1 to n do data[j]:=-1;
        ans:=0;
        search(1);
        writeln(ans-1);
        end;
end.
