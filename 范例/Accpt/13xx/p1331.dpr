program p1331;

{$APPTYPE CONSOLE}

type
        node=record
                a,b,c,d:longint;
                end;

var
        map     :array[2..200]of longint;
        whether :array[8..8000000]of boolean;
        puss    :array[0..3]of longint;
        num     :integer;
        n       :longint;
        data    :array[1..300]of node;
PROCEDURE search(dep:integer);
var
        i       :longint;
begin
for i:=puss[dep-1] to 200 do
        begin
        puss[dep]:=i;
        if (dep=3) then
                begin
                {if (puss[1]=3)and(puss[2]=4)true then
                        begin
                        writeln(puss[1],puss[2],puss[3]);readln;
                        end;}
                if (map[puss[1]]+map[puss[2]]+map[puss[3]]<=8000000)and(whether[map[puss[1]]+map[puss[2]]+map[puss[3]]]) then
                        begin
                        inc(num);
                        data[num].a:=puss[1];
                        data[num].b:=puss[2];
                        data[num].c:=puss[3];
                        data[num].d:=map[puss[1]]+map[puss[2]]+map[puss[3]];
                        end;
                end else search(dep+1);
        end;


end;


PROCEDURE makemap;
var
        i,j     :longint;

begin
fillchar(whether,sizeof(whether),0);
for i:=2 to 200 do
        begin
        map[i]:=i*i*i;
        whether[map[i]]:=true;
        end;
end;

PROCEDURE sort;
var
        i,j     :integer;
        temp    :node;
begin
for i:=1 to num-1 do
        for j:=i+1 to num do
                if (data[i].d>data[j].d)or((data[i].d=data[j].d)and((data[i].a>data[j].a)or((data[i].a=data[j].a)and(data[i].b>data[j].b)))) then
                        begin
                        temp:=data[i];
                        data[i]:=data[j];
                        data[j]:=temp;
                        end;
end;

PROCEDURE print;
var
        i       :integer;
        j       :Integer;
        ma      :longint;
begin
for i:=1 to num do
begin
for j:=2 to 200 do
        if map[j]=data[i].d then
                begin
                ma:=j;
                break;
                end;
writeln('Cube = ',ma,',',' Triple = (',data[i].a,',',data[i].b,',',data[i].c,')');
end;
end;

begin
makemap;
puss[0]:=2;
num:=0;
search(1);
sort;
print;
readln;
end.

