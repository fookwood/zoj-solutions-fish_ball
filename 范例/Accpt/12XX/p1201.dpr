program p1201;

{$APPTYPE CONSOLE}

type
        node=record
                p:0..1;
                n:integer;
                end;

var
        num     :array[1..50]of node;
        over    :array[1..50]of integer;
        total   :integer;
        ch      :char;


PROCEDURE  answer1;
var
        i       :integer;
        j       :integer;
begin
for i:=1 to total do
        begin
        read(num[i].n);
        over[num[i].n]:=0;
        for J:=1 to i-1 do
                if num[j].n>num[i].n then inc(over[num[i].n]);
        end;
readln;
for i:=1 to total-1 do write(over[i],' ');
writeln(over[total]);
end;

PROCEDURE answer2;
var
        i,j     :integer;
        pos     :integer;
begin
for i:=1 to total do num[i].p:=0;
for I:=1 to total do
        begin
        read(over[i]);
        j:=0;
        pos:=0;
        while j<=over[i] do
                begin
                inc(pos);
                if num[pos].p=0 then inc(j);
                end;
        num[pos].n:=i;
        num[pos].p:=1;
        end;
for i:=1 to total-1 do write(num[i].n,' ');
writeln(num[total].n);
end;


begin
readln(total);
while total<>0 do
        begin
        read(ch);
        if ch='P' then answer1 else answer2;
        readln(total);
        end;
end.
