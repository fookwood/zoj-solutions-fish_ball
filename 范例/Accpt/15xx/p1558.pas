PROGRAM p1558;

CONST
        up=200;
        down=-100;

VAR
        i,part                  :Integer;
        num                     :array[1..6]of Integer;
        minway                  :array[down..up]of Longint;

PROCEDURE Search(p:Integer);
var
        i,j                     :Longint;
begin
for i:=1 to 6 do
        begin
        j:=p + num[i];

        if (j<up)and(minway[p]+1<minway[j]) then
                begin
                minway[j]:=minway[p]+1;
                Search(j);
                end;

        j:=p - num[i];
        if (j>down) and (minway[p]+1<minway[j]) then
                begin
                minway[j]:=minway[p]+1;
                Search(j);
                end;

        end;
end;

PROCEDURE Main;
var
        i,maxone,total                  :Longint;
begin
maxone:=-1;
total:=0;
for i:=1 to 100 do
        begin
        total:=total+minway[i];
        if minway[i]>maxone then maxone:=minway[i];
        end;
writeln(total/100:0:2,' ',maxone);
end;

BEGIN
readln(part);
for part:=part downto 1 do
        begin
        for i:=1 to 6 do read(num[i]);
        readln;

        for i:=down to up do minway[i]:=maxlongint;
        minway[0]:=0;

        Search(0);
        Main;
        end;
END.